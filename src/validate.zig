const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const std = @import("std");
const symbols = @import("symbol.zig");

const AST = _ast.AST;
const Error = errs.Error;
const Scope = symbols.Scope;
const Symbol = symbols.Symbol;

pub fn validateScope(scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    for (scope.symbols.keys()) |key| {
        var symbol = scope.symbols.get(key) orelse {
            std.debug.print("{s} doesn't exist in this scope\n", .{key});
            return error.typeError;
        };
        try validateSymbol(symbol, errors, allocator);
    }
    for (scope.children.items) |child| {
        try validateScope(child, errors, allocator);
    }
}

pub fn validateSymbol(symbol: *Symbol, errors: *errs.Errors, allocator: std.mem.Allocator) error{ typeError, Unimplemented, OutOfMemory }!void {
    if (symbol.valid) {
        return;
    }
    symbol.valid = true;
    if (symbol.kind == ._fn) {
        var codomain = symbol._type.?.function.rhs;
        try validateAST(symbol.init.?, codomain, symbol.scope, errors, allocator);
    } else {
        if (symbol.init != null and symbol._type != null) {
            try validateAST(symbol._type.?, _ast.typeType, symbol.scope, errors, allocator);
            try validateAST(symbol.init.?, symbol._type, symbol.scope, errors, allocator);
        } else if (symbol.init == null) {
            // Default value (probably done at the IR side?)
        } else if (symbol._type == null) {
            // Infer type
            var _type = try symbol.init.?.typeof(symbol.scope, errors, allocator);
            symbol._type = _type;
            try validateAST(symbol.init.?, symbol._type, symbol.scope, errors, allocator);
        } else {
            unreachable;
        }
    }
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
pub fn validateAST(ast: *AST, expected: ?*AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) error{ typeError, Unimplemented, OutOfMemory }!void {
    if (expected != null and expected.?.* == .product) {
        var new_terms = std.ArrayList(*AST).init(allocator);
        for (expected.?.product.terms.items, 0..) |term, i| {
            if (ast.* == .product and i < ast.product.terms.items.len) {
                std.debug.print("append product self at i:{}\n", .{i});
                try new_terms.append(ast.product.terms.items[i]);
            } else if (ast.* == .unit or (ast.* != .product and i > 0) or (ast.* == .product and i >= ast.product.terms.items.len)) {
                if (term.* == .annotation and term.annotation.init != null) {
                    std.debug.print("append default at i:{}\n", .{i});
                    try new_terms.append(term.annotation.init.?);
                } else {
                    std.debug.print("no default to append at i:{}\n", .{i});
                }
            } else {
                std.debug.print("appending self at i:{}\n", .{i});
                try new_terms.append(ast);
            }
        }
        if (new_terms.items.len >= 2) {
            ast.* = AST{ .product = .{ .common = ast.getCommon().*, .terms = new_terms } };
        }
    }

    switch (ast.*) {
        .unit => {
            if (expected != null and !expected.?.typesMatch(_ast.unitType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .int => {
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .char => {
            if (expected != null and !expected.?.typesMatch(_ast.charType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.charType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .float => {
            if (expected != null and !expected.?.typesMatch(_ast.floatType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .string => {
            // TODO: strings
            std.debug.print("string\n", .{});
        },

        .identifier => {
            // look up symbol, that's the type
            var symbol = try findSymbol(ast, scope, errors);
            try validateSymbol(symbol, errors, allocator);
            var _type = symbol._type.?;
            if (expected != null and !expected.?.typesMatch(_type)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _type, .stage = .typecheck } });
                return error.typeError;
            }
        },

        ._true => {
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        ._false => {
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .not => {
            try validateAST(ast.not.expr, _ast.boolType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .negate => {
            try validateAST(ast.negate.expr, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .dereference => {
            if (expected != null) {
                var ast_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !expected.?.typesMatch(ast_type)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                    return error.typeError;
                }
                try validateAST(ast.dereference.expr, try _ast.AST.createAddrOf(ast.getToken(), expected.?, false, std.heap.page_allocator), scope, errors, allocator);
            } else {
                try validateAST(ast.dereference.expr, null, scope, errors, allocator);
            }
        },
        ._try => {
            std.debug.print("try\n", .{});
        },
        .optional => {
            std.debug.print("optional\n", .{});
        },
        .fromOptional => {
            std.debug.print("fromOptional\n", .{});
        },
        .inferredError => {
            std.debug.print("inferred error\n", .{});
        },

        .assign => {
            try validateLValue(ast.assign.lhs, scope, errors);
            try assertMutable(ast.assign.lhs, scope, errors, allocator);
            try validateAST(ast.assign.rhs, try ast.assign.lhs.typeof(scope, errors, allocator), scope, errors, allocator);
        },
        ._or => {
            try validateAST(ast._or.lhs, _ast.boolType, scope, errors, allocator);
            try validateAST(ast._or.rhs, _ast.boolType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._and => {
            try validateAST(ast._and.lhs, _ast.boolType, scope, errors, allocator);
            try validateAST(ast._and.rhs, _ast.boolType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .notEqual => {
            // TODO: typeof lhs and typeof rhs match
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .add => {
            try validateAST(ast.add.lhs, _ast.floatType, scope, errors, allocator);
            try validateAST(ast.add.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .sub => {
            try validateAST(ast.sub.lhs, _ast.floatType, scope, errors, allocator);
            try validateAST(ast.sub.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .mult => {
            try validateAST(ast.mult.lhs, _ast.floatType, scope, errors, allocator);
            try validateAST(ast.mult.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .div => {
            try validateAST(ast.div.lhs, _ast.floatType, scope, errors, allocator);
            try validateAST(ast.div.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .mod => {
            try validateAST(ast.mod.lhs, _ast.floatType, scope, errors, allocator);
            try validateAST(ast.mod.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .exponent => {
            for (ast.exponent.terms.items) |term| {
                try validateAST(term, _ast.floatType, scope, errors, allocator);
            }
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._catch => {
            std.debug.print("catch\n", .{});
        },
        ._orelse => {
            std.debug.print("orelse\n", .{});
        },
        .call => {
            // TODO: Validate lhs is function, returns expected
            var lhs_type = try ast.call.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* != .function) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "call is not to a function", .stage = .typecheck } });
                return error.typeError;
            }

            try validateAST(ast.call.lhs, null, scope, errors, allocator);
            try validateAST(ast.call.rhs, lhs_type.function.lhs, scope, errors, allocator);

            if (expected != null and !expected.?.typesMatch(lhs_type.function.rhs)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.function.rhs, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .index => {
            std.debug.print("index\n", .{});
        },
        .select => {
            std.debug.print("select\n", .{});
        },
        .function => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .delta => {
            std.debug.print("delta\n", .{});
        },
        .composition => {
            std.debug.print("composition\n", .{});
        },
        .prepend => {
            std.debug.print("prepend\n", .{});
        },
        .sum => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._error => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .diff => {
            std.debug.print("diff\n", .{});
        },
        .concat => {
            std.debug.print("concat\n", .{});
        },
        ._union => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .product => {
            if (expected != null and expected.?.typesMatch(_ast.typeType)) {
                if (expected.?.product.terms.items.len != ast.product.terms.items.len) {
                    std.debug.print("1\n", .{});
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                }
                for (ast.product.terms.items) |term| {
                    try validateAST(term, _ast.typeType, scope, errors, allocator);
                }
            } else if (expected != null and expected.?.* == .product) {
                if (expected.?.product.terms.items.len != ast.product.terms.items.len) {
                    std.debug.print("2\n", .{});
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                }
                for (ast.product.terms.items, expected.?.product.terms.items) |term, expected_term| { // Ok, this is cool!
                    try validateAST(term, expected_term, scope, errors, allocator);
                }
            } else if (expected == null) {
                for (ast.product.terms.items) |term| {
                    try validateAST(term, null, scope, errors, allocator);
                }
            } else {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return error.typeError;
                // unreachable;
            }
        },
        .conditional => {
            for (ast.conditional.exprs.items) |child| {
                try validateAST(child, _ast.floatType, scope, errors, allocator);
            }
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .addrOf => {
            if (expected != null and expected.?.typesMatch(_ast.typeType)) {
                // Address type, type of this ast must be a type, inner must be a type
                var ast_type: *AST = try ast.addrOf.expr.typeof(scope, errors, allocator);
                if (!ast_type.typesMatch(expected.?)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return error.typeError;
                } else {
                    try validateAST(ast.addrOf.expr, _ast.typeType, scope, errors, allocator);
                }
            } else if (expected != null and expected.?.* == .addrOf) {
                // Address value, expected must be an address, inner must match with expected's inner
                if (!expected.?.typesMatch(try ast.typeof(scope, errors, allocator))) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return error.typeError;
                }
                try validateAST(ast.addrOf.expr, expected.?.addrOf.expr, scope, errors, allocator);
                try validateLValue(ast.addrOf.expr, scope, errors);
                if (ast.addrOf.mut) {
                    try assertMutable(ast.addrOf.expr, scope, errors, allocator);
                }
            } else if (expected == null) {
                try validateAST(ast.addrOf.expr, null, scope, errors, allocator);
                try validateLValue(ast.addrOf.expr, scope, errors);
            } else {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return error.typeError;
            }
        },
        .sliceOf => {
            std.debug.print("slice of\n", .{});
        },
        .namedArg => {
            std.debug.print("arg\n", .{});
        },
        .subSlice => {
            std.debug.print("subslice\n", .{});
        },
        .annotation => {
            std.debug.print("annotation\n", .{});
        },
        .inferredMember => {
            std.debug.print("member\n", .{});
        },

        ._if => {
            if (ast._if.let) |let| {
                try validateAST(let, null, scope, errors, allocator);
            }
            try validateAST(ast._if.condition, _ast.boolType, ast._if.scope.?, errors, allocator);
            try validateAST(ast._if.bodyBlock, expected, ast._if.scope.?, errors, allocator);
            if (ast._if.elseBlock) |elseBlock| {
                try validateAST(elseBlock, expected, ast._if.scope.?, errors, allocator);
            }
        },
        .cond => {
            if (ast.cond.let) |let| {
                try validateAST(let, null, scope, errors, allocator);
            }
            var num_rhs: usize = 0;
            for (ast.cond.mappings.items) |mapping| {
                try validateAST(mapping, expected, ast.cond.scope.?, errors, allocator);
                if (mapping.mapping.rhs) |_| {
                    num_rhs += 1;
                }
            }
            if (num_rhs == 0) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "expected at least one non-null rhs prong", .stage = .typecheck } });
                return error.typeError;
            }
        },
        .match => {
            // TODO: After pattern matching
            std.debug.print("match\n", .{});
        },
        .mapping => {
            switch (ast.mapping.kind) {
                .cond => {
                    if (ast.mapping.lhs) |lhs| {
                        try validateAST(lhs, _ast.boolType, scope, errors, allocator);
                    }
                    if (ast.mapping.rhs) |rhs| {
                        try validateAST(rhs, expected, scope, errors, allocator);
                    }
                },
                .match => {},
            }
        },
        ._while => {
            if (ast._while.let) |let| {
                try validateAST(let, null, scope, errors, allocator);
            }
            try validateAST(ast._while.condition, _ast.boolType, ast._while.scope.?, errors, allocator);
            try validateAST(ast._while.bodyBlock, expected, ast._while.scope.?, errors, allocator);
            if (ast._while.elseBlock) |elseBlock| {
                try validateAST(elseBlock, expected, ast._while.scope.?, errors, allocator);
            }
            if (ast._while.post) |post| {
                try validateAST(post, null, ast._while.scope.?, errors, allocator);
            }
        },
        ._for => {
            // TODO: After type-classes and iterators
        },
        .block => {
            if (ast.block.final) |final| {
                var i: usize = 0;
                while (i < ast.block.statements.items.len) : (i += 1) {
                    var term = ast.block.statements.items[i];
                    try validateAST(term, null, ast.block.scope.?, errors, allocator);
                }
                try validateAST(final, null, ast.block.scope.?, errors, allocator);
            } else {
                if (ast.block.statements.items.len > 1) {
                    var i: usize = 0;
                    while (i < ast.block.statements.items.len - 1) : (i += 1) {
                        var term = ast.block.statements.items[i];
                        try validateAST(term, null, ast.block.scope.?, errors, allocator);
                    }
                    try validateAST(ast.block.statements.items[ast.block.statements.items.len - 1], expected, ast.block.scope.?, errors, allocator);
                } else if (ast.block.statements.items.len == 1) {
                    try validateAST(ast.block.statements.items[0], null, ast.block.scope.?, errors, allocator);
                }

                var block_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !expected.?.typesMatch(block_type)) {
                    if (ast.block.statements.items.len > 1) {
                        errors.addError(Error{ .expected2Type = .{ .span = ast.block.statements.items[ast.block.statements.items.len - 1].getToken().span, .expected = expected.?, .got = block_type, .stage = .typecheck } });
                        return error.typeError;
                    } else {
                        errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = block_type, .stage = .typecheck } });
                        return error.typeError;
                    }
                }
            }
        },

        // no return
        ._break => {
            if (!scope.in_loop) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`break` must be inside a loop",
                    .stage = .typecheck,
                } });
                return error.typeError;
            }
        },
        ._continue => {
            if (!scope.in_loop) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`continue` must be inside a loop",
                    .stage = .typecheck,
                } });
                return error.typeError;
            }
        },

        .throw, ._return => {
            if (scope.in_function == 0) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`return` must be contained in a function",
                    .stage = .typecheck,
                } });
                return error.typeError;
            }
        },
        ._unreachable => {},

        ._defer => {
            try scope.defers.append(ast._defer.statement);
        },
        .fnDecl => {
            // TODO: ast expression is a function type
        },
        .decl => {
            ast.decl.symbol.?.defined = true;
            // statement, no type
            if (expected != null) {
                errors.addError(Error{ .expectedType = .{ .span = ast.getToken().span, .expected = expected.?, .stage = .typecheck } });
                return error.typeError;
            }
        },
    }
}

fn findSymbol(ast: *AST, scope: *Scope, errors: *errs.Errors) !*Symbol {
    var symbol = scope.lookup(ast.identifier.common.token.data, false) orelse {
        errors.addError(Error{ .undeclaredIdentifier = .{ .identifier = ast.identifier.common.token, .stage = .typecheck } });
        return error.typeError;
    };
    if (!symbol.defined) {
        errors.addError(Error{ .useBeforeDef = .{ .identifier = ast.identifier.common.token, .symbol = symbol, .stage = .typecheck } });
        return error.typeError;
    }
    return symbol;
}

fn validateLValue(ast: *AST, scope: *Scope, errors: *errs.Errors) !void {
    switch (ast.*) {
        .identifier => {
            _ = try findSymbol(ast, scope, errors);
        },

        .dereference => {
            var child = ast.dereference.expr;
            if (child.* != .addrOf) {
                try validateLValue(child, scope, errors);
            }
        },

        else => {
            errors.addError(Error{ .basic = .{
                .span = ast.getToken().span,
                .msg = "not an l-value",
                .stage = .typecheck,
            } });
            return error.typeError;
        },
    }
}

fn assertMutable(ast: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    switch (ast.*) {
        .identifier => {
            var symbol = try findSymbol(ast, scope, errors);
            if (symbol.kind != .mut) {
                errors.addError(Error{ .modifyImmutable = .{
                    .identifier = ast.identifier.common.token,
                    .symbol = symbol,
                    .stage = .typecheck,
                } });
                return error.typeError;
            }
        },

        .dereference => {
            var child = ast.dereference.expr;
            var child_type = try child.typeof(scope, errors, allocator);
            if (!child_type.addrOf.mut) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "attempt to modify non-mutable address",
                    .stage = .typecheck,
                } });
                return error.typeError;
            }
        },

        else => {
            errors.addError(Error{ .basic = .{
                .span = ast.getToken().span,
                .msg = "not modifiable",
                .stage = .typecheck,
            } });
            return error.typeError;
        },
    }
}
