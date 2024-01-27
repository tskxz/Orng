/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct dyn1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct dyn1 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*b)(void*, int64_t);
    void(*c)(void*, int64_t);
};

/* Function forward definitions */
int64_t _42_main(void);
int64_t _38_b(void* _38_self, int64_t _38_x);
void _40_c(void* _40_self, int64_t _40_x);

/* Trait vtable implementations */
struct vtable_My_Trait _37_$vtable = {
    .b = _38_b,
    .c = _40_c,
};


/* Function definitions */
int64_t _42_main(void){
    int64_t _42_t1;
    int64_t _42_t2;
    struct struct0 _43_my_val;
    struct dyn1 _42_t3;
    struct dyn1 _43_my_dyn;
    int64_t _42_t5;
    int64_t _42_t7;
    int64_t _42_t6;
    int64_t _42_$retval;
    _42_t1 = 100;
    _42_t2 = 45;
    _43_my_val = (struct struct0) {_42_t1, _42_t2};
    _42_t3 = (struct dyn1) {&_43_my_val, &_37_$vtable};
    _43_my_dyn = _42_t3;
    _42_t5 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:19:13:\n    my_dyn.>c(2)\n           ^";
    (void) _43_my_dyn.vtable->c(_43_my_dyn.data_ptr, _42_t5);
    $line_idx--;
    _42_t7 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:20:13:\n    my_dyn.>b(2)\n           ^";
    _42_t6 = _43_my_dyn.vtable->b(_43_my_dyn.data_ptr, _42_t7);
    $line_idx--;
    _42_$retval = _42_t6;
    return _42_$retval;
}

int64_t _38_b(void* _38_self, int64_t _38_x){
    int64_t _38_t0;
    int64_t _38_$retval;
    _38_t0 = $mult_int64_t((*(struct struct0*)_38_self)._1, _38_x, "tests/integration/traits/receiver-addr-object.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _38_$retval = $add_int64_t((*(struct struct0*)_38_self)._0, _38_t0, "tests/integration/traits/receiver-addr-object.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _38_$retval;
}

void _40_c(void* _40_self, int64_t _40_x){
    (*(struct struct0*)_40_self)._0 = $mult_int64_t((*(struct struct0*)_40_self)._0, _40_x, "tests/integration/traits/receiver-addr-object.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}


int main(void) {
  printf("%ld",_42_main());
  return 0;
}
