/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
    struct0 _2;
} struct1;

/* Function forward definitions */
int64_t _80_main(void);

/* Function definitions */
int64_t _80_main(void){
    int64_t _80_t2;
    int64_t _80_t3;
    int64_t _80_t4;
    struct0 _80_t1;
    int64_t _80_t6;
    int64_t _80_t7;
    int64_t _80_t8;
    struct0 _80_t5;
    int64_t _80_t10;
    int64_t _80_t11;
    int64_t _80_t12;
    struct0 _80_t9;
    struct1 _81_x;
    int64_t _80_t13;
    int64_t _80_t14;
    int64_t _80_t15;
    int64_t _80_t16;
    int64_t _80_t17;
    int64_t _80_t19;
    int64_t _80_t20;
    int64_t _80_t21;
    int64_t _80_t22;
    int64_t _80_t23;
    int64_t _80_t24;
    int64_t _80_t25;
    int64_t _80_t26;
    int64_t _80_$retval;
    _80_t2 = 1;
    _80_t3 = 2;
    _80_t4 = 3;
    _80_t1 = (struct0) {_80_t2, _80_t3, _80_t4};
    _80_t6 = 4;
    _80_t7 = 5;
    _80_t8 = 68;
    _80_t5 = (struct0) {_80_t6, _80_t7, _80_t8};
    _80_t10 = 7;
    _80_t11 = 8;
    _80_t12 = 9;
    _80_t9 = (struct0) {_80_t10, _80_t11, _80_t12};
    _81_x = (struct1) {_80_t1, _80_t5, _80_t9};
    _80_t13 = 1;
    _80_t14 = 3;
    _80_t15 = 2;
    _80_t16 = 3;
    _80_t17 = 1;
    _80_t19 = 1;
    _80_t20 = 3;
    _80_t21 = 2;
    _80_t22 = 3;
    $bounds_check(_80_t19, _80_t20, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_80_t21, _80_t22, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_80_t13, _80_t14, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_80_t15, _80_t16, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    *((int64_t*)((struct0*)&_81_x + _80_t19) + _80_t21) = $add_int64_t(*((int64_t*)((struct0*)&_81_x + _80_t13) + _80_t15), _80_t17, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    _80_t23 = 1;
    _80_t24 = 3;
    _80_t25 = 2;
    _80_t26 = 3;
    $bounds_check(_80_t23, _80_t24, "tests/integration/arrays/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    $bounds_check(_80_t25, _80_t26, "tests/integration/arrays/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    _80_$retval = *((int64_t*)((struct0*)&_81_x + _80_t23) + _80_t25);
    return _80_$retval;
}

int main(void) {
  printf("%ld",_80_main());
  return 0;
}
