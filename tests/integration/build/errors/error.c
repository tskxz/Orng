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
        uint32_t _0;
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _287_main(void);

/* Function definitions */
int64_t _287_main(void) {
    int64_t _287_t0;
    struct0 _288_x;
    int64_t _287_$retval;
    _287_t0 = 117;
    _288_x = (struct0) {.tag=1, ._1=_287_t0};
    _287_$retval = _288_x._1;
    return _287_$retval;
}

int main(void) {
  printf("%ld",_287_main());
  return 0;
}
