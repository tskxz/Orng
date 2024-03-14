/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;
struct struct2;
struct struct3;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

struct struct2 {
    struct struct1 _0;
    struct struct1 _1;
    struct struct1 _2;
};

struct struct3 {
    struct struct1* _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1377_main(void);


/* Function definitions */
int64_t _1377_main(void){
    int64_t _1377_t1;
    int64_t _1377_t2;
    int64_t _1377_t3;
    struct struct0 _1378_x;
    int64_t _1377_t7;
    int64_t _1377_t8;
    int64_t* _1377_t9;
    int64_t _1377_t10;
    struct struct1 _1377_t6;
    int64_t _1377_t12;
    int64_t _1377_t13;
    int64_t* _1377_t14;
    int64_t _1377_t15;
    struct struct1 _1377_t11;
    int64_t _1377_t17;
    int64_t _1377_t18;
    int64_t* _1377_t19;
    int64_t _1377_t20;
    struct struct1 _1377_t16;
    struct struct2 _1378_y;
    int64_t _1377_t23;
    int64_t _1377_t24;
    struct struct1* _1377_t25;
    int64_t _1377_t26;
    struct struct3 _1378_z;
    int64_t _1377_t29;
    int64_t _1377_t30;
    int64_t _1377_t31;
    int64_t _1377_t32;
    int64_t _1377_$retval;
    _1377_t1 = 1;
    _1377_t2 = 2;
    _1377_t3 = 3;
    _1378_x = (struct struct0) {_1377_t1, _1377_t2, _1377_t3};
    _1377_t7 = 0;
    _1377_t8 = 3;
    $bounds_check(_1377_t7, _1377_t8, "tests/integration/slices/multi-dim.orng:4:37:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                   ^");
    _1377_t9 = ((int64_t*)&_1378_x + _1377_t7);
    _1377_t10 = 3;
    _1377_t6 = (struct struct1) {_1377_t9, _1377_t10};
    _1377_t12 = 0;
    _1377_t13 = 3;
    $bounds_check(_1377_t12, _1377_t13, "tests/integration/slices/multi-dim.orng:4:45:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                           ^");
    _1377_t14 = ((int64_t*)&_1378_x + _1377_t12);
    _1377_t15 = 3;
    _1377_t11 = (struct struct1) {_1377_t14, _1377_t15};
    _1377_t17 = 0;
    _1377_t18 = 3;
    $bounds_check(_1377_t17, _1377_t18, "tests/integration/slices/multi-dim.orng:4:53:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                                   ^");
    _1377_t19 = ((int64_t*)&_1378_x + _1377_t17);
    _1377_t20 = 3;
    _1377_t16 = (struct struct1) {_1377_t19, _1377_t20};
    _1378_y = (struct struct2) {_1377_t6, _1377_t11, _1377_t16};
    _1377_t23 = 0;
    _1377_t24 = 3;
    $bounds_check(_1377_t23, _1377_t24, "tests/integration/slices/multi-dim.orng:5:34:\n    let z: [mut][mut]Int = [mut]y\n                                ^");
    _1377_t25 = ((struct struct1*)&_1378_y + _1377_t23);
    _1377_t26 = 3;
    _1378_z = (struct struct3) {_1377_t25, _1377_t26};
    _1377_t29 = 1;
    _1377_t30 = 2;
    $bounds_check(_1377_t29, _1378_z._1, "tests/integration/slices/multi-dim.orng:6:17:\n    z[1][2] = 82\n               ^");
    $bounds_check(_1377_t30, (*((struct struct1*)_1378_z._0 + _1377_t29))._1, "tests/integration/slices/multi-dim.orng:6:17:\n    z[1][2] = 82\n               ^");
    *((int64_t*)(*((struct struct1*)_1378_z._0 + _1377_t29))._0 + _1377_t30) = 82;
    _1377_t31 = 1;
    _1377_t32 = 2;
    $bounds_check(_1377_t31, _1378_z._1, "tests/integration/slices/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    $bounds_check(_1377_t32, (*((struct struct1*)_1378_z._0 + _1377_t31))._1, "tests/integration/slices/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    _1377_$retval = *((int64_t*)(*((struct struct1*)_1378_z._0 + _1377_t31))._0 + _1377_t32);
    return _1377_$retval;
}


int main(void) {
  printf("%ld",_1377_main());
  return 0;
}
