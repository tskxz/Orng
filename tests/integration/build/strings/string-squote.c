/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct0;

/* Interned Strings */
char* string_0 = "\x0A\x0D\x09\x27\x22";

/* Function forward definitions */
uint8_t _1039_main(void);

/* Function definitions */
uint8_t _1039_main(void) {
    struct0 _1040_x;
    int64_t _1039_t1;
    uint8_t _1039_$retval;
    _1040_x = (struct0) {(uint8_t*)string_0, 5};
    _1039_t1 = 3;
    _1039_$retval = *((uint8_t*)_1040_x._0 + _1039_t1);
    return _1039_$retval;
}

int main(void) {
  printf("%d",_1039_main());
  return 0;
}
