/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1413_main(void);

/* Function definitions */
int64_t _1413_main(void){
    int64_t _1413_t0;
    struct0 _1414_x;
    uint64_t _1413_t2;
    int64_t _1413_$retval;
    _1413_t0 = 102;
    _1414_x = (struct0) {.tag=0, ._0=_1413_t0};
    _1413_t2 = 0;
    $tag_check(_1413_t2, 0, "tests/integration/sums/default.orng:4:3:\nfn main() -> Int {\n ^");
    _1413_$retval = _1414_x._0;
    return _1413_$retval;
}

int main(void) {
  printf("%ld",_1413_main());
  return 0;
}
