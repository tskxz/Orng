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
uint8_t _1376_main(void);

/* Function definitions */
uint8_t _1376_main(void){
    struct0 _1377_x;
    int64_t _1376_t1;
    uint8_t _1376_$retval;
    _1377_x = (struct0) {(uint8_t*)string_0, 5};
    _1376_t1 = 4;
    $bounds_check(_1376_t1, _1377_x._1, "tests/integration/strings/string-dquote.orng:2:3:\nfn main() -> Byte {\n ^");
    _1376_$retval = *((uint8_t*)_1377_x._0 + _1376_t1);
    return _1376_$retval;
}

int main(void) {
  printf("%u",_1376_main());
  return 0;
}
