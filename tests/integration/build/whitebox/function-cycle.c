/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_a(int64_t _3_n);
int64_t _5_b(int64_t _5_n);
int64_t _7_c(int64_t _7_n);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    $line_idx--;
    _1_$retval = _3_a(47);
    return _1_$retval;
}

int64_t _3_a(int64_t _3_n) {
    int64_t _3_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    $line_idx--;
    _3_$retval = _5_b(_3_n);
    return _3_$retval;
}

int64_t _5_b(int64_t _5_n) {
    int64_t _5_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    $line_idx--;
    _5_$retval = _7_c(_5_n);
    return _5_$retval;
}

int64_t _7_c(int64_t _7_n) {
    int64_t _7_t0;
    int64_t _7_$retval;
    if (_7_n == 47) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _7_t0 = 47;
    goto BB4;
BB5:
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    $line_idx--;
    _7_t0 = _3_a(_7_n);
BB4:
    _7_$retval = _7_t0;
    return _7_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
