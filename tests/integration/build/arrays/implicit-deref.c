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
    int64_t _3;
    int64_t _4;
} struct0;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    struct0* _2_y;
    int64_t _1_$retval;
    _2_x = (struct0) {1, 2, 3, 4, 5};
    _2_y = &_2_x;
    _1_$retval = $add_int64_t(*((int64_t*)_2_y + 2), 77, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
