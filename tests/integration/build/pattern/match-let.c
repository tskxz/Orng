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
int64_t _1404_main(void);

/* Function definitions */
int64_t _1404_main(void){
    int64_t _1404_t2;
    int64_t _1404_t3;
    int64_t _1404_t4;
    struct0 _1405_x;
    int64_t _1404_t5;
    int64_t _1404_t6;
    int64_t _1404_t7;
    uint8_t _1404_t8;
    int64_t _1404_t0;
    int64_t _1404_t11;
    uint8_t _1404_t12;
    int64_t _1404_$retval;
    int64_t _1404_t9;
    uint8_t _1404_t10;
    _1404_t2 = 1;
    _1404_t3 = 2;
    _1404_t4 = 3;
    _1405_x = (struct0) {_1404_t2, _1404_t3, _1404_t4};
    _1404_t5 = 2;
    _1404_t6 = 3;
    _1404_t7 = 1;
    $bounds_check(_1404_t5, _1404_t6, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1404_t8 = *((int64_t*)&_1405_x + _1404_t5) == _1404_t7;
    if (_1404_t8) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _1404_t0 = 2;
    goto BB5;
BB6:
    _1404_t9 = 2;
    $bounds_check(_1404_t5, _1404_t6, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1404_t10 = *((int64_t*)&_1405_x + _1404_t5) == _1404_t9;
    if (_1404_t10) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _1404_$retval = _1404_t0;
    return _1404_$retval;
BB8:
    _1404_t0 = 22;
    goto BB5;
BB9:
    _1404_t11 = 3;
    $bounds_check(_1404_t5, _1404_t6, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1404_t12 = *((int64_t*)&_1405_x + _1404_t5) == _1404_t11;
    if (_1404_t12) {
        goto BB11;
    } else {
        goto BB13;
    }
BB11:
    _1404_t0 = 222;
    goto BB5;
BB13:
    _1404_t0 = 0;
    goto BB5;
}

int main(void) {
  printf("%ld",_1404_main());
  return 0;
}
