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
    };
} struct0;

/* Function forward definitions */
int64_t _1456_main(void);

/* Function definitions */
int64_t _1456_main(void){
    int64_t _1456_t0;
    struct0 _1457_x;
    uint64_t _1456_t10;
    int64_t _1456_$retval;
    _1456_t0 = 210;
    _1457_x = (struct0) {.tag=0, ._0=_1456_t0};
    _1456_t10 = 0;
    $tag_check(_1456_t10, 0, "tests/integration/sums/sum-equality.orng:4:7:\n    if x == .none {\n     ^");
    _1456_$retval = _1457_x._0;
    return _1456_$retval;
}

int main(void) {
  printf("%ld",_1456_main());
  return 0;
}
