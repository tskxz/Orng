/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(struct1);

/* Interned Strings */
char* string_0 = "\x6D\x61\x6B\x65\x20\x73\x75\x72\x65\x20\x79\x6F\x75\x20\x73\x61\x6E\x69\x74\x69\x7A\x65\x20\x6D\x65\x21\x0A";

/* Function forward definitions */
int64_t _1210_main(void);
int64_t _1212_f(struct1 _1212_x);

/* Function definitions */
int64_t _1210_main(void) {
    function0 _1210_t0;
    struct1 _1210_t2;
    int64_t _1210_t1;
    int64_t _1210_$retval;
    _1210_t0 = _1212_f;
    _1210_t2 = (struct1) {(uint8_t*)string_0, 27};
    $lines[$line_idx++] = "tests/integration/whitebox/sanitize.orng:3:7:\n    f(\"make sure you sanitize me!\\n\")\n     ^";
    _1210_t1 = _1210_t0(_1210_t2);
    $line_idx--;
    _1210_$retval = _1210_t1;
    return _1210_$retval;
}

int64_t _1212_f(struct1 _1212_x) {
    (void)_1212_x;
    $lines[$line_idx++] = "tests/integration/whitebox/sanitize.orng:8:16:\n    unreachable\n              ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1210_main());
  return 0;
}
