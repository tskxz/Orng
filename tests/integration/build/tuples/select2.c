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
} struct0;

typedef struct {
    struct0 _0;
    int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _113_main(void);
int64_t _115_f(struct1 _115_a);

/* Function definitions */
int64_t _113_main(void) {
    int64_t _113_t2;
    int64_t _113_t3;
    struct0 _113_t1;
    int64_t _113_t4;
    struct1 _114_x;
    function2 _113_t5;
    int64_t _113_t6;
    int64_t _113_$retval;
    _113_t2 = 50;
    _113_t3 = 150;
    _113_t1 = (struct0) {_113_t2, _113_t3};
    _113_t4 = 300;
    _114_x = (struct1) {_113_t1, _113_t4};
    _113_t5 = _115_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _113_t6 = _113_t5(_114_x);
    $line_idx--;
    _113_$retval = _113_t6;
    return _113_$retval;
}

int64_t _115_f(struct1 _115_a) {
    int64_t _115_$retval;
    _115_$retval = _115_a._1;
    return _115_$retval;
}

int main(void) {
  printf("%ld",_113_main());
  return 0;
}
