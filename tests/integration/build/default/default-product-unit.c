/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _255_main(void);

/* Function definitions */
int64_t _255_main(void) {
    int64_t _255_t2;
    struct0 _256_x;
    struct0* _256_y;
    int64_t _255_t5;
    int64_t _255_$retval;
    _255_t2 = 0;
    _256_x = (struct0) {_255_t2, };
    _256_y = &_256_x;
    _255_t5 = 140;
    _255_$retval = $add_int64_t(_255_t5, (*_256_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _255_$retval;
}

int main(void) {
  printf("%ld",_255_main());
  return 0;
}
