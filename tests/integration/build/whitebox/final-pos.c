/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1195_main(void);

/* Function definitions */
int64_t _1195_main(void) {
    int64_t _1196_x;
    int64_t _1195_t2;
    uint8_t _1195_t3;
    int64_t _1195_t5;
    uint8_t _1195_t7;
    int64_t _1195_t10;
    int64_t _1195_$retval;
    int64_t _1195_t8;
    _1196_x = 0;
    goto BB1;
BB1:
    _1195_t2 = 100;
    _1195_t3 = _1196_x < _1195_t2;
    if (_1195_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1195_t5 = 40;
    _1195_t7 = _1196_x == _1195_t5;
    if (_1195_t7) {
        goto BB5;
    } else {
        goto BB11;
    }
BB7:
    _1195_$retval = _1196_x;
    return _1195_$retval;
BB5:
    _1195_t8 = 1;
    _1196_x = $add_int64_t(_1196_x, _1195_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB7;
BB11:
    _1195_t10 = 1;
    _1196_x = $add_int64_t(_1196_x, _1195_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_1195_main());
  return 0;
}
