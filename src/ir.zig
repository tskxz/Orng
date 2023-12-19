const std = @import("std");
const ast_ = @import("ast.zig");
const basic_block_ = @import("basic-block.zig");
const cfg_ = @import("cfg.zig");
const errs = @import("errors.zig");
const lval_ = @import("lval.zig");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig");
const symbol_ = @import("symbol.zig");

var ir_uid: u64 = 0;
pub const IR = struct {
    uid: u64,
    kind: Kind,
    dest: ?*lval_.L_Value,
    src1: ?*lval_.L_Value,
    src2: ?*lval_.L_Value,

    data: Data,
    next: ?*IR,
    prev: ?*IR,

    in_block: ?*basic_block_.Basic_Block,
    span: span_.Span,

    removed: bool,
    allocator: std.mem.Allocator,

    safe: bool, // Disables static UB checks for this IR. Used for IR generated by `match`'s

    pub fn create(kind: Kind, dest: ?*lval_.L_Value, src1: ?*lval_.L_Value, src2: ?*lval_.L_Value, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try allocator.create(IR);
        retval.kind = kind;
        retval.dest = dest;
        retval.src1 = src1;
        retval.src2 = src2;
        retval.uid = ir_uid;
        retval.in_block = null;
        retval.prev = null;
        retval.next = null;
        retval.data = Data.none;
        retval.span = span;
        retval.allocator = allocator;
        ir_uid += 1;
        return retval;
    }

    pub fn createInt(dest: *lval_.L_Value, int: i128, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadInt, dest, null, null, span, allocator);
        retval.data = Data{ .int = int };
        return retval;
    }

    pub fn createFloat(dest: *lval_.L_Value, float: f64, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadFloat, dest, null, null, span, allocator);
        retval.data = Data{ .float = float };
        return retval;
    }

    pub fn createString(dest: *lval_.L_Value, id: usize, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadString, dest, null, null, span, allocator);
        retval.data = Data{ .string_id = id };
        return retval;
    }

    pub fn create_ast(dest: *lval_.L_Value, ast: *ast_.AST, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        const retval = try IR.create(.loadAST, dest, null, null, span, allocator);
        retval.data = Data{ .ast = ast };
        return retval;
    }

    pub fn create_simple_copy(dest: *lval_.L_Value, src: *lval_.L_Value, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        const ir = try IR.create(.copy, dest, src, null, span, allocator);
        return ir;
    }

    pub fn createLabel(cfg: *cfg_.CFG, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.label, null, null, null, span, allocator);
        retval.data = Data{ .cfg = cfg };
        return retval;
    }

    // TODO: Rename create_branch_ir, rename IR kind as well
    pub fn createBranch(condition: *lval_.L_Value, label: ?*IR, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.branchIfFalse, null, condition, null, span, allocator);
        retval.data = Data{ .branch = label };
        return retval;
    }

    // TODO: Rename create_jump_ir, rename IR kind as well
    pub fn createJump(label: ?*IR, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.jump, null, null, null, span, allocator);
        retval.data = Data{ .branch = label };
        return retval;
    }

    pub fn create_jump_addr(next: ?*basic_block_.Basic_Block, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.jump, null, null, null, span, allocator);
        retval.data = Data{ .jump_bb = .{ .next = next } };
        return retval;
    }

    pub fn create_branch_addr(condition: *lval_.L_Value, next: ?*basic_block_.Basic_Block, branch: ?*basic_block_.Basic_Block, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.branchIfFalse, null, condition, null, span, allocator);
        retval.data = Data{ .branch_bb = .{ .next = next, .branch = branch } };
        return retval;
    }

    pub fn createCall(dest: *lval_.L_Value, src1: *lval_.L_Value, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.call, dest, src1, null, span, allocator);
        retval.data = Data{ .lval_list = std.ArrayList(*lval_.L_Value).init(allocator) };
        return retval;
    }

    pub fn createLoadStruct(dest: *lval_.L_Value, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadStruct, dest, null, null, span, allocator);
        retval.data = Data{ .lval_list = std.ArrayList(*lval_.L_Value).init(allocator) };
        return retval;
    }

    pub fn createGetTag(dest: *lval_.L_Value, src1: *lval_.L_Value, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        const retval = try IR.create(.get_tag, dest, src1, null, span, allocator);
        return retval;
    }

    pub fn createUnion(dest: *lval_.L_Value, init: ?*lval_.L_Value, tag: i128, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadUnion, dest, init, null, span, allocator);
        retval.data = Data{ .int = tag };
        return retval;
    }

    pub fn createDiscard(src1: *lval_.L_Value, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.discard, null, src1, null, span, allocator);
        retval.data = Data.none;
        return retval;
    }

    pub fn createStackPush(span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.pushStackTrace, null, null, null, span, allocator);
        retval.data = Data.none;
        return retval;
    }

    pub fn createStackPop(span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.popStackTrace, null, null, null, span, allocator);
        retval.data = Data.none;
        return retval;
    }

    pub fn createPanic(message: []const u8, span: span_.Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.panic, null, null, null, span, allocator);
        retval.data = Data{ .string = message };
        return retval;
    }

    pub fn create_int_float_kind(
        int_kind: Kind,
        float_kind: Kind,
        dest: ?*lval_.L_Value,
        src1: ?*lval_.L_Value,
        src2: ?*lval_.L_Value,
        span: span_.Span,
        scope: *symbol_.Scope,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) !*IR {
        if (try src1.?.get_type().can_represent_float(scope, errors, allocator)) {
            return try create(float_kind, dest, src1, src2, span, allocator);
        } else {
            return try create(int_kind, dest, src1, src2, span, allocator);
        }
    }

    pub fn deinit(self: *IR) void {
        if (self.dest != null) {
            self.dest.?.deinit();
        }
        self.allocator.destroy(self);
    }

    pub fn getTail(self: *IR) *IR {
        var mut_self: *IR = self;
        while (mut_self.next != null) : (mut_self = mut_self.next.?) {}
        return mut_self;
    }

    pub fn pprint(self: IR, allocator: std.mem.Allocator) ![]const u8 {
        var out = String.init(allocator);
        defer out.deinit();

        switch (self.kind) {
            .label => try out.writer().print("BB{}:\n", .{self.uid}),

            .loadInt => {
                try out.writer().print("    {} := {}\n", .{ self.dest.?, self.data.int });
            },
            .loadFloat => {
                try out.writer().print("    {} := {}\n", .{ self.dest.?, self.data.float });
            },
            .loadSymbol => {
                try out.writer().print("    {} := {s}\n", .{ self.dest.?, self.data.symbol.name });
            },
            .loadStruct => {
                try out.writer().print("    {} := {{", .{self.dest.?});
                var i: usize = 0;
                while (i < self.data.lval_list.items.len) : (i += 1) {
                    const lval = self.data.lval_list.items[i];
                    try out.writer().print("{}", .{lval});
                    if (i < self.data.lval_list.items.len - 1) {
                        try out.writer().print(", ", .{});
                    }
                }
                try out.writer().print("}}\n", .{});
            },
            .loadUnion => {
                // init may be null, if it is unit
                try out.writer().print("    {} := {{init={?}, tag={}}}\n", .{ self.dest.?, self.src1, self.data.int });
            },
            .loadString => {
                try out.writer().print("    {} := <interned string:{}>\n", .{ self.dest.?, self.data.string_id });
            },
            .loadAST => {
                try out.writer().print("    {} := AST({})\n", .{ self.dest.?, self.data.ast });
            },
            .loadUnit => {
                try out.writer().print("    {} := {{}}\n", .{self.dest.?});
            },

            .copy => {
                try out.writer().print("    {} := {?}\n", .{ self.dest.?, self.src1 });
            },
            .not => {
                try out.writer().print("    {} := !{}\n", .{ self.dest.?, self.src1.? });
            },
            .negate_int => {
                try out.writer().print("    {} := -{}\n", .{ self.dest.?, self.src1.? });
            },
            .negate_float => {
                try out.writer().print("    {} := -.{}\n", .{ self.dest.?, self.src1.? });
            },
            .sizeOf => {
                try out.writer().print("    {} := sizeof({})\n", .{ self.dest.?, self.src1.? });
            },
            .addrOf => {
                try out.writer().print("    {} := &{}\n", .{ self.dest.?, self.src1.? });
            },

            .equal => {
                try out.writer().print("    {} := {} == {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .not_equal => {
                try out.writer().print("    {} := {} != {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .greater_int => {
                try out.writer().print("    {} := {} > {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .greater_float => {
                try out.writer().print("    {} := {} >. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .lesser_int => {
                try out.writer().print("    {} := {} < {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .lesser_float => {
                try out.writer().print("    {} := {} <. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .greater_equal_int => {
                try out.writer().print("    {} := {} >= {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .greater_equal_float => {
                try out.writer().print("    {} := {} >=. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .lesser_equal_int => {
                try out.writer().print("    {} := {} <= {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .lesser_equal_float => {
                try out.writer().print("    {} := {} <=. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .add_int => {
                try out.writer().print("    {} := {} + {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .add_float => {
                try out.writer().print("    {} := {} +. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .sub_int => {
                try out.writer().print("    {} := {} - {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .sub_float => {
                try out.writer().print("    {} := {} -. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .mult_int => {
                try out.writer().print("    {} := {} * {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .mult_float => {
                try out.writer().print("    {} := {} *. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .div_int => {
                try out.writer().print("    {} := {} / {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .div_float => {
                try out.writer().print("    {} := {} /. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .mod => {
                try out.writer().print("    {} := {} % {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },

            .get_tag => {
                try out.writer().print("    {} := {}.tag\n", .{ self.dest.?, self.src1.? });
            },

            .jump => {
                if (self.data.jump_bb.next) |next| {
                    try out.writer().print("    jump BB{}\n", .{next.uid});
                } else {
                    try out.writer().print("    ret\n", .{});
                }
            },
            .branchIfFalse => {
                if (self.data.branch_bb.next) |next| {
                    try out.writer().print("    if ({}) jump BB{}", .{ self.src1.?, next.uid });
                } else {
                    try out.writer().print("    if ({}) ret", .{self.src1.?});
                }
                try out.writer().print(" ", .{});
                if (self.data.branch_bb.branch) |branch| {
                    try out.writer().print("else jump BB{}\n", .{branch.uid});
                } else {
                    try out.writer().print("else ret\n", .{});
                }
            },
            .call => {
                try out.writer().print("    {} := {}(", .{ self.dest.?, self.src1.? });
                var i: usize = 0;
                while (i < self.data.lval_list.items.len) : (i += 1) {
                    const lval = self.data.lval_list.items[i];
                    try out.writer().print("{}", .{lval});
                    if (i < self.data.lval_list.items.len - 1) {
                        try out.writer().print(", ", .{});
                    }
                }
                try out.writer().print(")\n", .{});
            },

            .discard => {
                try out.writer().print("    _ := {}\n", .{self.src1.?});
            },
            .pushStackTrace => {
                try out.writer().print("    push-stack-trace\n", .{});
            },
            .popStackTrace => {
                try out.writer().print("    pop-stack-trace\n", .{});
            },
            .panic => {
                try out.writer().print("    panic\n", .{});
            },

            else => {
                try out.writer().print("<TODO: {s}>\n", .{@tagName(self.kind)});
            },
        }

        return (try out.toOwned()).?;
    }

    pub fn format(self: IR, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }

    /// This function is O(n) in terms of IR between start and stop
    pub fn get_latest_def_after(start_at_ir: *IR, symbol: *symbol_.Symbol, stop_at_ir: ?*IR) ?*IR {
        var maybe_ir: ?*IR = start_at_ir;
        var retval: ?*IR = null;
        while (maybe_ir != null and maybe_ir != stop_at_ir) : (maybe_ir = maybe_ir.?.next) {
            var ir: *IR = maybe_ir.?;
            if (ir.dest != null and ir.dest.?.* == .select and ir.dest.?.extract_symbver().symbol == symbol) {
                return null;
            } else if (ir.dest != null and ir.dest.?.* == .index and ir.dest.?.extract_symbver().symbol == symbol) {
                return null;
            } else if (ir.dest != null and ir.dest.?.* == .symbver and ir.dest.?.symbver.symbol == symbol) {
                retval = ir;
            } else if (ir.kind == .addrOf and ir.src1.?.extract_symbver().symbol == symbol) {
                retval = null;
            }
        }
        return retval;
    }

    // This function is O(n)
    pub fn any_def_after(start_at_ir: *IR, symbol: *symbol_.Symbol, stop_at_ir: ?*IR) ?*IR {
        var maybe_ir: ?*IR = start_at_ir;
        while (maybe_ir != null and maybe_ir != stop_at_ir) : (maybe_ir = maybe_ir.?.next) {
            var ir: *IR = maybe_ir.?;
            if (ir.dest != null and ir.dest.?.* == .select and ir.dest.?.extract_symbver().symbol == symbol) {
                return ir;
            } else if (ir.dest != null and ir.dest.?.* == .index and ir.dest.?.extract_symbver().symbol == symbol) {
                return ir;
            } else if (ir.kind == .addrOf and ir.src1.?.extract_symbver().symbol == symbol) {
                return ir;
            } else if (ir.dest != null and ir.dest.?.* == .symbver and ir.dest.?.symbver.symbol == symbol) {
                return ir;
            }
        }
        return null;
    }
};

pub const Kind = enum {
    // nullary instructions
    loadSymbol,
    loadExtern,
    loadInt,
    loadFloat,
    loadStruct, // TODO: Rename to load_tuple
    loadUnion, // src1 is init, data.int is tag id // TODO: Rename to load_sum
    loadString,
    loadAST,
    loadUnit, // no-op, but required. DO NOT optimize away

    // Monadic instructions
    copy,
    not,
    negate_int,
    negate_float,
    sizeOf, //< For extern types that Orng can't do automatically
    addrOf,

    // Diadic instructions
    equal,
    not_equal,
    greater_int,
    greater_float,
    lesser_int,
    lesser_float,
    greater_equal_int,
    greater_equal_float,
    lesser_equal_int,
    lesser_equal_float,
    add_int,
    add_float,
    sub_int,
    sub_float,
    mult_int,
    mult_float,
    div_int,
    div_float,
    mod,
    get_tag, // dest = src1.tag
    cast,

    // Control-flow
    label,
    jump, // jump to BB{uid} if codegen, ip := {addr} if interpreting
    branchIfFalse,
    call, // dest = src1(symbver_list...)

    // Non-Code Generating
    discard, // Marks that a symbol isn't used, but that's OK

    // Errors
    pushStackTrace, // Pushes a static span/code to the lines array if debug mode is on
    popStackTrace, // Pops a message off the stack after a function is successfully called
    panic, // if debug mode is on, panics with a message, unrolls lines stack, exits

    pub fn precedence(self: Kind) i64 {
        return switch (self) {
            .loadSymbol,
            .loadExtern,
            .loadInt,
            .loadFloat,
            .loadStruct,
            .loadUnion,
            .loadString,
            => 0,

            .call,
            .get_tag,
            => 1,

            .negate_int,
            .negate_float,
            .not,
            .sizeOf,
            .cast,
            .addrOf,
            => 2,

            .mult_int,
            .mult_float,
            .div_int,
            .div_float,
            .mod,
            => 3,

            .add_int,
            .add_float,
            .sub_int,
            .sub_float,
            => 4,

            // No bitshift operators, would be precedence 5

            .greater_int,
            .greater_float,
            .lesser_int,
            .lesser_float,
            .greater_equal_int,
            .greater_equal_float,
            .lesser_equal_int,
            .lesser_equal_float,
            => 6,

            .equal,
            .not_equal,
            => 7,

            .copy => 14,

            else => {
                std.debug.print("Unimplemented precedence for kind {s}\n", .{@tagName(self)});
                unreachable;
            },
        };
    }
};

pub const Data = union(enum) {
    branch: ?*IR,
    jump_bb: struct { next: ?*basic_block_.Basic_Block },
    branch_bb: struct { next: ?*basic_block_.Basic_Block, branch: ?*basic_block_.Basic_Block },
    int: i128,
    float: f64,
    string_id: usize,
    cfg: *cfg_.CFG, // Used by the interpreter to know how much space to leave for a CFGs locals
    string: []const u8,
    symbol: *symbol_.Symbol,
    lval_list: std.ArrayList(*lval_.L_Value),
    // lval: *lval_.L_Value,
    select: struct { offset: i128, field: i128 },
    ast: *ast_.AST,
    none,

    pub fn pprint(self: Data, allocator: std.mem.Allocator) ![]const u8 {
        var out = String.init(allocator);
        defer out.deinit();

        switch (self) {
            .int => {
                try out.writer().print("{}", .{self.int});
            },
            .float => {
                try out.writer().print("{d:.6}", .{self.float});
            },
            .none => {
                try out.writer().print("none", .{});
            },
            .symbol => {
                try out.writer().print("{s}", .{self.symbol.name});
            },
            .string_id => {
                try out.writer().print("<interned string:{}>", .{self.string_id});
            },
            else => {
                try out.writer().print("??? ({s})", .{@tagName(self)});
            },
        }

        return (try out.toOwned()).?;
    }

    pub fn format(self: Data, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }

    pub fn equals(self: Data, other: Data) bool {
        if (self == .branch and other == .branch) {
            return self.branch == other.branch;
        } else if (self == .int and other == .int) {
            return self.int == other.int;
        } else if (self == .float and other == .float) {
            return self.float == other.float;
        } else if (self == .int and other == .float) {
            return self.int == @as(i128, @intFromFloat(other.float)); // These will crash if float is not representable by i128
        } else if (self == .float and other == .int) { //                This should not be a problem with user-generated code, since it's type-checked
            return @as(i128, @intFromFloat(self.float)) == other.int; // But keep it in mind for compiler-generated code generated after type-checking, such as defaults
        } else if (self == .string_id and other == .string_id) {
            return self.string_id == other.string_id;
        } else if (self == .string and other == .string) {
            return std.mem.eql(u8, self.string, other.string);
        } else if (self == .symbol and other == .symbol) {
            return self.symbol == other.symbol;
        } else {
            return false; // tags are mismatched
        }
    }
};
