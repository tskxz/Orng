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
int64_t _1243_main(void);

/* Function definitions */
int64_t _1243_main(void){
    int64_t _1243_t2;
    int64_t _1243_t3;
    int64_t _1243_t4;
    struct0 _1243_t1;
    int64_t _1243_t5;
    uint8_t _1243_t6;
    int64_t _1246_x;
    int64_t _1246_y;
    int64_t _1243_t7;
    int64_t _1243_t8;
    int64_t _1243_$retval;
    _1243_t2 = 100;
    _1243_t3 = 60;
    _1243_t4 = 8;
    _1243_t1 = (struct0) {_1243_t2, _1243_t3, _1243_t4};
    _1243_t5 = 100;
    _1243_t6 = _1243_t1._0==_1243_t5;
    if (_1243_t6) {
        goto BB1491;
    } else {
        goto BB1495;
    }
BB1491:
    _1246_x = _1243_t1._1;
    _1246_y = _1243_t1._2;
    _1243_t7 = 100;
    _1243_t8 = $add_int64_t(_1243_t7, _1246_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _1243_$retval = $add_int64_t(_1243_t8, _1246_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _1243_$retval;
BB1495:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:35:\n        _           => unreachable\n                                 ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1243_main());
  return 0;
}
