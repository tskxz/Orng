/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct dyn2;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

struct dyn2 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*d)(int64_t, int64_t);
};

/* Function forward definitions */
int64_t _1772_main(void);
int64_t _1770_d(int64_t _1770_x, int64_t _1770_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1769_$vtable = {
    .d = _1770_d,
};


/* Function definitions */
int64_t _1772_main(void){
    int64_t _1772_t1;
    int64_t _1772_t2;
    struct struct1 _1773_my_val;
    struct dyn2 _1772_t4;
    struct dyn2 _1773_my_dyn;
    int64_t _1772_t8;
    int64_t _1772_t9;
    int64_t _1772_t7;
    int64_t _1772_$retval;
    _1772_t1 = 100;
    _1772_t2 = 45;
    _1773_my_val = (struct struct1) {_1772_t1, _1772_t2};
    _1772_t4 = (struct dyn2) {&_1773_my_val, &_1769_$vtable};
    _1773_my_dyn = _1772_t4;
    _1772_t8 = 200;
    _1772_t9 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _1772_t7 = _1773_my_dyn.vtable->d(_1772_t8, _1772_t9);
    $line_idx--;
    _1772_$retval = _1772_t7;
    return _1772_$retval;
}

int64_t _1770_d(int64_t _1770_x, int64_t _1770_y){
    int64_t _1770_$retval;
    _1770_$retval = $add_int64_t(_1770_x, _1770_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _1770_$retval;
}


int main(void) {
  printf("%ld",_1772_main());
  return 0;
}
