/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(struct1);

typedef struct {
    int64_t _0;
} struct2;

/* Function forward definitions */
int64_t _1387_main(void);
int64_t _1389_first(struct1 _1389_xs);

/* Function definitions */
int64_t _1387_main(void){
    function0 _1387_t0;
    int64_t _1387_t3;
    int64_t _1387_t5;
    struct2 _1387_t4;
    int64_t _1387_t6;
    int64_t* _1387_t7;
    int64_t _1387_t8;
    struct1 _1387_t2;
    int64_t _1387_t1;
    int64_t _1387_$retval;
    _1387_t0 = _1389_first;
    _1387_t3 = 0;
    _1387_t5 = 233;
    _1387_t4 = (struct2) {_1387_t5};
    _1387_t6 = 1;
    $bounds_check(_1387_t3, _1387_t6, "tests/integration/slices/1-slice.orng:3:18:\n    first([](233,))\n                ^");
    _1387_t7 = ((int64_t*)&_1387_t4 + _1387_t3);
    _1387_t8 = 1;
    _1387_t2 = (struct1) {_1387_t7, _1387_t8};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1387_t1 = _1387_t0(_1387_t2);
    $line_idx--;
    _1387_$retval = _1387_t1;
    return _1387_$retval;
}

int64_t _1389_first(struct1 _1389_xs){
    int64_t _1389_t0;
    int64_t _1389_$retval;
    _1389_t0 = 0;
    $bounds_check(_1389_t0, _1389_xs._1, "tests/integration/slices/1-slice.orng:6:3:\nfn first(xs: []Int) -> Int {\n ^");
    _1389_$retval = *((int64_t*)_1389_xs._0 + _1389_t0);
    return _1389_$retval;
}

int main(void) {
  printf("%ld",_1387_main());
  return 0;
}
