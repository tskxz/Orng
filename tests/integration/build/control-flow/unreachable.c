/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1692153840433787011
#define ORNG_1692153840433787011

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
BB0:
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable.orng:3:16:\n    unreachable + 4";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif