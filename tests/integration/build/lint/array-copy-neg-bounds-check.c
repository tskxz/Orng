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
} struct0;

typedef int64_t(*function1)(void);

/* Function forward definitions */
int64_t _2_main(void);
int64_t _8_f(void);

/* Function definitions */
int64_t _2_main(void){
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_t4;
    struct0 _3_x;
    function1 _2_t6;
    int64_t _2_t7;
    int64_t _2_t8;
    int64_t _2_$retval;
    _2_t1 = 0;
    _2_t2 = 0;
    _2_t3 = 0;
    _2_t4 = 0;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
    _2_t6 = _8_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-neg-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _2_t7 = _2_t6();
    $line_idx--;
    _2_t8 = 4;
    $bounds_check(_2_t7, _2_t8, "tests/integration/lint/array-copy-neg-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_3_x + _2_t7) = 0;
    _2_$retval = 0;
    return _2_$retval;
}

int64_t _8_f(void){
    int64_t _8_$retval;
    _8_$retval = -100;
    return _8_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}
