/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _100_main(void);

/* Function definitions */
int64_t _100_main(void) {
    int64_t _101_x;
    int64_t* _101_y;
    int64_t _100_$retval;
    _101_x = 242;
    _101_y = &_101_x;
    _100_$retval = *_101_y;
    return _100_$retval;
}

int main(void) {
  printf("%ld",_100_main());
  return 0;
}
