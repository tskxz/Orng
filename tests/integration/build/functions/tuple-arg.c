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
} struct1;

typedef int64_t(*function0)(struct1);

/* Function forward definitions */
int64_t _717_main(void);
int64_t _719_add(struct1 _719_x);

/* Function definitions */
int64_t _717_main(void) {
    function0 _717_t0;
    int64_t _717_t3;
    int64_t _717_t4;
    int64_t _717_t5;
    struct1 _717_t2;
    int64_t _717_t1;
    int64_t _717_$retval;
    _717_t0 = _719_add;
    _717_t3 = 100;
    _717_t4 = 90;
    _717_t5 = 7;
    _717_t2 = (struct1) {_717_t3, _717_t4, _717_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _717_t1 = _717_t0(_717_t2);
    $line_idx--;
    _717_$retval = _717_t1;
    return _717_$retval;
}

int64_t _719_add(struct1 _719_x) {
    int64_t _719_t0;
    int64_t _719_t1;
    int64_t _719_t2;
    int64_t _719_t3;
    int64_t _719_$retval;
    _719_t0 = 0;
    _719_t1 = 1;
    _719_t2 = $add_int64_t(*((int64_t*)&_719_x + _719_t0), *((int64_t*)&_719_x + _719_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _719_t3 = 2;
    _719_$retval = $add_int64_t(_719_t2, *((int64_t*)&_719_x + _719_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _719_$retval;
}

int main(void) {
  printf("%ld",_717_main());
  return 0;
}
