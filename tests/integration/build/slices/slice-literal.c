/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;
struct struct2;

/* Typedefs */
struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function0)(struct struct1);

struct struct2 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1353_main(void);
int64_t _1355_sum(struct struct1 _1355_xs);

/* Function definitions */
int64_t _1353_main(void){
    function0 _1353_t0;
    int64_t _1353_t4;
    int64_t _1353_t5;
    int64_t _1353_t6;
    struct struct2 _1353_t3;
    int64_t _1353_t7;
    int64_t _1353_t8;
    int64_t* _1353_t9;
    int64_t _1353_t10;
    struct struct1 _1353_t2;
    int64_t _1353_t1;
    int64_t _1353_$retval;
    _1353_t0 = _1355_sum;
    _1353_t4 = 200;
    _1353_t5 = 0;
    _1353_t6 = 8;
    _1353_t3 = (struct struct2) {_1353_t4, _1353_t5, _1353_t6};
    _1353_t7 = 0;
    _1353_t8 = 3;
    $bounds_check(_1353_t7, _1353_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1353_t9 = ((int64_t*)&_1353_t3 + _1353_t7);
    _1353_t10 = 3;
    _1353_t2 = (struct struct1) {_1353_t9, _1353_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1353_t1 = _1353_t0(_1353_t2);
    $line_idx--;
    _1353_$retval = _1353_t1;
    return _1353_$retval;
}

int64_t _1355_sum(struct struct1 _1355_xs){
    int64_t _1355_t1;
    uint8_t _1355_t3;
    int64_t _1355_t10;
    int64_t* _1355_t11;
    struct struct1 _1355_t12;
    int64_t _1355_t7;
    int64_t _1355_t0;
    int64_t _1355_$retval;
    int64_t _1355_t5;
    function0 _1355_t6;
    int64_t _1355_t8;
    uint8_t _1355_t9;
    _1355_t1 = 0;
    _1355_t3 = _1355_xs._1==_1355_t1;
    if (_1355_t3) {
        goto BB1625;
    } else {
        goto BB1629;
    }
BB1625:
    _1355_t0 = 0;
    goto BB1628;
BB1629:
    _1355_t5 = 0;
    _1355_t6 = _1355_sum;
    _1355_t8 = 1;
    _1355_t9 = _1355_t8>_1355_xs._1;
    if (_1355_t9) {
        goto BB1630;
    } else {
        goto BB1631;
    }
BB1628:
    _1355_$retval = _1355_t0;
    return _1355_$retval;
BB1630:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1631:
    _1355_t10 = $sub_int64_t(_1355_xs._1, _1355_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1355_t11 = _1355_xs._0+_1355_t8;
    _1355_t12 = (struct struct1) {_1355_t11, _1355_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1355_t7 = _1355_t6(_1355_t12);
    $line_idx--;
    $bounds_check(_1355_t5, _1355_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1355_t0 = $add_int64_t(*((int64_t*)_1355_xs._0 + _1355_t5), _1355_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1628;
}

int main(void) {
  printf("%ld",_1353_main());
  return 0;
}
