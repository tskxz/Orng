/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _1;
} struct1;

typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1255_main(void);
int64_t _1257_f(int64_t _1257_x);

/* Function definitions */
int64_t _1255_main(void) {
    function0 _1255_t0;
    int64_t _1255_t3;
    int64_t _1255_t1;
    int64_t _1255_$retval;
    _1255_t0 = _1257_f;
    _1255_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1255_t1 = _1255_t0(_1255_t3);
    $line_idx--;
    _1255_$retval = _1255_t1;
    return _1255_$retval;
}

int64_t _1257_f(int64_t _1257_x) {
    int64_t _1257_$retval;
    _1257_$retval = _1257_x;
    return _1257_$retval;
}

int main(void) {
  printf("%ld",_1255_main());
  return 0;
}
