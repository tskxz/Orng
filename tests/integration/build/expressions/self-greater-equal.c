/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _546_main(void);
uint8_t _551_f(int64_t _551_x);

/* Function definitions */
int64_t _546_main(void) {
    function0 _546_t1;
    int64_t _546_t3;
    uint8_t _546_t2;
    int64_t _546_t0;
    int64_t _546_$retval;
    _546_t1 = _551_f;
    _546_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _546_t2 = _546_t1(_546_t3);
    $line_idx--;
    if (_546_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _546_t0 = 227;
    goto BB4;
BB5:
    _546_t0 = 0;
    goto BB4;
BB4:
    _546_$retval = _546_t0;
    return _546_$retval;
}

uint8_t _551_f(int64_t _551_x) {
    uint8_t _551_$retval;
    (void)_551_x;
    _551_$retval = 1;
    return _551_$retval;
}

int main(void) {
  printf("%ld",_546_main());
  return 0;
}
