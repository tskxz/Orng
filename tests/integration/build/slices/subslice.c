/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
    int64_t _4;
    int64_t _5;
} struct0;
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _2_main();
int64_t _4_sum_up(struct1 _4_xs);

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t* _2_t14;
    struct1 _3_y;
    int64_t _2_t16;
    int64_t* _2_t20;
    int64_t* _2_t21;
    struct1 _3_z;
    int64_t _2_t24;
    int64_t _2_t29;
    int64_t _2_$retval;
    _3_x = (struct0) {1, 15, 24, 4, 35, 6};
    _2_t14 = (int64_t*)&_3_x;
    _3_y = (struct1) {_2_t14, 6};
    _2_t16 = 1;
    _2_t20 = _3_y._0;
    _2_t21 = _2_t20 + _2_t16;
    _3_z = (struct1) {_2_t21, (5 - _2_t16)};
    _2_t24 = 2;
    if (_2_t24 >= _3_z._1) {
        goto BB9;
    } else {
        goto BB10;
    }
BB9:
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:6:7:\n    z[2] = 10\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB10:
    *((int64_t*)_3_z._0 + _2_t24) = 10;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _2_t29 = _4_sum_up(_3_z);
    $line_idx--;
    _2_$retval = _2_t29;
    return _2_$retval;
}

int64_t _4_sum_up(struct1 _4_xs) {
    int64_t _5_sum;
    int64_t _6_i;
    int64_t _4_$retval;
    _5_sum = 0;
    _6_i = 0;
BB1:
    if (_6_i < _4_xs._1) {
        goto BB2;
    } else {
        goto BB14;
    }
BB2:
    if (_6_i < 0) {
        goto BB5;
    } else {
        goto BB6;
    }
BB14:
    _4_$retval = _5_sum;
    return _4_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:13:19:\n        sum += xs[i]\n                 ^";
    fprintf(stderr, "panic: index is negative\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB6:
    if (_6_i >= _4_xs._1) {
        goto BB7;
    } else {
        goto BB8;
    }
BB7:
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:13:19:\n        sum += xs[i]\n                 ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB8:
    _5_sum = _5_sum + *((int64_t*)_4_xs._0 + _6_i);
    _6_i = _6_i + 1;
    goto BB1;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
