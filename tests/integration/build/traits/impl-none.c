/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;

/* Struct, union, and function definitions */
struct struct1 {
    struct struct3* _0;
    int64_t _1;
};

typedef int64_t(*function0)(struct struct3*, int64_t);

typedef int64_t(*function2)(int64_t);

struct struct3 {
    int64_t _0;
    int64_t _1;
};

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _1670_main(void);
int64_t _1664_a(void* _1664_$self_ptr, int64_t _1664_x);
int64_t _1666_c(void* _1666_self, int64_t _1666_x);
int64_t _1668_d(int64_t _1668_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1670_main(void){
    int64_t _1670_t1;
    int64_t _1670_t2;
    struct struct3 _1671_my_val;
    struct struct3* _1670_t5;
    int64_t _1670_t6;
    function0 _1670_t7;
    int64_t _1670_t4;
    int64_t _1670_t8;
    int64_t _1670_$retval;
    _1670_t1 = 200;
    _1670_t2 = 45;
    _1671_my_val = (struct struct3) {_1670_t1, _1670_t2};
    _1670_t5 = &_1671_my_val;
    _1670_t6 = 2;
    _1670_t7 = (function0) _1664_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1670_t4 = _1670_t7(_1670_t5, _1670_t6);
    $line_idx--;
    _1670_t8 = 2;
    _1670_$retval = $add_int64_t(_1670_t4, _1670_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1670_$retval;
}

int64_t _1664_a(void* _1664_$self_ptr, int64_t _1664_x){
    struct struct3 _1665_self;
    int64_t _1664_t1;
    int64_t _1664_$retval;
    _1665_self = *(struct struct3*)_1664_$self_ptr;
    _1664_t1 = $mult_int64_t(_1665_self._1, _1664_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1664_$retval = $add_int64_t(_1665_self._0, _1664_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1664_$retval;
}

int64_t _1666_c(void* _1666_self, int64_t _1666_x){
    int64_t _1666_t0;
    int64_t _1666_$retval;
    (*(struct struct3*)_1666_self)._0 = _1666_x;
    _1666_t0 = $mult_int64_t((*(struct struct3*)_1666_self)._1, _1666_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1666_$retval = $add_int64_t((*(struct struct3*)_1666_self)._0, _1666_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1666_$retval;
}

int64_t _1668_d(int64_t _1668_x){
    int64_t _1668_t0;
    int64_t _1668_$retval;
    _1668_t0 = 4;
    _1668_$retval = $add_int64_t(_1668_x, _1668_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1668_$retval;
}


int main(void) {
  printf("%ld",_1670_main());
  return 0;
}
