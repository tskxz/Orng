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
    int64_t _4_x;
    int64_t _2_$retval;
    _4_x = 0;
BB1:
    if (_4_x < 10) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _4_x = _4_x + 1;
    _4_x = _4_x + 1;
    goto BB1;
BB8:
    _2_$retval = _4_x;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
