/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1329_main(void);


/* Function definitions */
int64_t _1329_main(void){
    int64_t _1329_t2;
    int64_t _1329_t3;
    int64_t _1329_t4;
    struct struct0 _1329_t1;
    int64_t _1329_t5;
    uint8_t _1329_t6;
    int64_t _1332_x;
    int64_t _1332_y;
    int64_t _1329_t7;
    int64_t _1329_t8;
    int64_t _1329_$retval;
    _1329_t2 = 100;
    _1329_t3 = 60;
    _1329_t4 = 8;
    _1329_t1 = (struct struct0) {_1329_t2, _1329_t3, _1329_t4};
    _1329_t5 = 100;
    _1329_t6 = _1329_t1._0==_1329_t5;
    if (_1329_t6) {
        goto BB1537;
    } else {
        goto BB1541;
    }
BB1537:
    _1332_x = _1329_t1._1;
    _1332_y = _1329_t1._2;
    _1329_t7 = 100;
    _1329_t8 = $add_int64_t(_1329_t7, _1332_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _1329_$retval = $add_int64_t(_1329_t8, _1332_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _1329_$retval;
BB1541:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:35:\n        _           => unreachable\n                                 ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1329_main());
  return 0;
}
