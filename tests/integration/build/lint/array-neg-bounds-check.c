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
int64_t _20_main(void);
int64_t _26_f(void);

/* Function definitions */
int64_t _20_main(void){
    int64_t _20_t1;
    int64_t _20_t2;
    int64_t _20_t3;
    int64_t _20_t4;
    struct0 _21_x;
    function1 _20_t5;
    int64_t _20_t6;
    int64_t _20_t7;
    int64_t _20_$retval;
    _20_t1 = 0;
    _20_t2 = 0;
    _20_t3 = 0;
    _20_t4 = 0;
    _21_x = (struct0) {_20_t1, _20_t2, _20_t3, _20_t4};
    _20_t5 = _26_f;
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _20_t6 = _20_t5();
    $line_idx--;
    _20_t7 = 4;
    $bounds_check(_20_t6, _20_t7, "tests/integration/lint/array-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _20_$retval = *((int64_t*)&_21_x + _20_t6);
    return _20_$retval;
}

int64_t _26_f(void){
    int64_t _26_$retval;
    _26_$retval = -100;
    return _26_$retval;
}

int main(void) {
  printf("%ld",_20_main());
  return 0;
}
