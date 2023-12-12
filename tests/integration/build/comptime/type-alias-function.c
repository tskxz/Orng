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
} struct1;

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _151_main(void);
int64_t _153_add(int64_t _153_x,int64_t _153_y);

/* Function definitions */
int64_t _151_main(void) {
    function0 _152_f;
    int64_t _151_t2;
    int64_t _151_t3;
    int64_t _151_t1;
    int64_t _151_$retval;
    _152_f = _153_add;
    _151_t2 = 200;
    _151_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _151_t1 = _152_f(_151_t2, _151_t3);
    $line_idx--;
    _151_$retval = _151_t1;
    return _151_$retval;
}

int64_t _153_add(int64_t _153_x,int64_t _153_y) {
    int64_t _153_$retval;
    _153_$retval = $add_int64_t(_153_x, _153_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _153_$retval;
}

int main(void) {
  printf("%ld",_151_main());
  return 0;
}