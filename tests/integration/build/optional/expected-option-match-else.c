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
    };
};

/* Function forward definitions */
int64_t _1160_main(void);


/* Function definitions */
int64_t _1160_main(void){
    int64_t _1160_t10;
    struct struct0 _1161_x;
    uint64_t _1160_t13;
    int64_t _1160_$retval;
    goto BB1331;
BB1331:
    _1160_t10 = 128;
    _1161_x = (struct struct0) {.tag=0, ._0=_1160_t10};
    _1160_t13 = 0;
    $tag_check(_1160_t13, 0, "tests/integration/optional/expected-option-match-else.orng:2:8:\nfn main() -> Int {\n      ^");
    _1160_$retval = _1161_x._0;
    return _1160_$retval;
}


int main(void) {
  printf("%ld",_1160_main());
  return 0;
}
