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

/* Function forward definitions */
int64_t _803_main(void);

/* Function definitions */
int64_t _803_main(void) {
    int64_t _803_t1;
    int64_t _803_t2;
    int64_t _803_t3;
    struct0 _804_x;
    int64_t _803_t5;
    int64_t _803_t6;
    int64_t _803_t7;
    struct0 _803_t4;
    int64_t _803_t8;
    int64_t _803_$retval;
    _803_t1 = 1;
    _803_t2 = 2;
    _803_t3 = 3;
    _804_x = (struct0) {_803_t1, _803_t2, _803_t3};
    _803_t5 = 60;
    _803_t6 = 23;
    _803_t7 = 200;
    _803_t4 = (struct0) {_803_t5, _803_t6, _803_t7};
    _804_x._1 = _803_t4._0;
    _804_x._2 = _803_t4._1;
    _804_x._0 = _803_t4._2;
    _803_t8 = $sub_int64_t(_804_x._0, _804_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _803_$retval = $add_int64_t(_803_t8, _804_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _803_$retval;
}

int main(void) {
  printf("%ld",_803_main());
  return 0;
}
