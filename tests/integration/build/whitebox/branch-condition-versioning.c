/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    uint8_t _3_found;
    int64_t _4_n;
    int64_t _2_$retval;
    int64_t _2_t13;
    _3_found = 0;
    _4_n = 0;
BB1:
    if (_4_n < 10) {
        goto BB4;
    } else {
        goto BB19;
    }
BB4:
    if (_3_found) {
        goto BB5;
    } else {
        goto BB7;
    }
BB19:
    if (_3_found) {
        goto BB20;
    } else {
        goto BB24;
    }
BB5:
    _4_n = 100;
BB7:
    if (_4_n == 6) {
        goto BB10;
    } else {
        goto BB14;
    }
BB20:
    _2_t13 = 15;
    goto BB23;
BB24:
    _2_t13 = 4;
    goto BB23;
BB10:
    _3_found = 1;
BB14:
    _4_n = _4_n + 1;
    goto BB1;
BB23:
    _2_$retval = _2_t13;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
