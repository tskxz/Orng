/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _777_main(void);

/* Function definitions */
int64_t _777_main(void) {
    int64_t _777_t1;
    int64_t _777_t2;
    int64_t _777_t3;
    struct0 _777_t0;
    int64_t _778_a;
    int64_t _778_c;
    int64_t _777_$retval;
    _777_t1 = 100;
    _777_t2 = 300;
    _777_t3 = 56;
    _777_t0 = (struct0) {_777_t1, _777_t2, _777_t3};
    _778_a = _777_t0._0;
    _778_c = _777_t0._2;
    _777_$retval = $add_int64_t(_778_a, _778_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _777_$retval;
}

int main(void) {
  printf("%ld",_777_main());
  return 0;
}
