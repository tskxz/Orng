/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
    };
};

/* Function forward definitions */
int64_t _1497_main(void);


/* Function definitions */
int64_t _1497_main(void){
    int64_t _1497_t0;
    struct struct0 _1498_x;
    uint64_t _1497_t3;
    int64_t _1497_$retval;
    _1497_t0 = 101;
    _1498_x = (struct struct0) {.tag=0, ._0=_1497_t0};
    _1497_t3 = 0;
    $tag_check(_1497_t3, 0, "tests/integration/sums/inferred.orng:2:3:\nfn main() -> Int {\n ^");
    _1497_$retval = _1498_x._0;
    return _1497_$retval;
}


int main(void) {
  printf("%ld",_1497_main());
  return 0;
}
