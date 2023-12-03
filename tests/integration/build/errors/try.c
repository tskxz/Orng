/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
    };
} struct1;

typedef struct1(*function0)(uint8_t);

typedef struct1(*function2)(void);

/* Function forward definitions */
int64_t _361_main(void);
struct1 _363_f(uint8_t _363_fail);
struct1 _368_g(void);

/* Function definitions */
int64_t _361_main(void) {
    function0 _361_t1;
    uint8_t _361_t3;
    struct1 _361_t2;
    uint64_t _361_t4;
    int64_t _361_t0;
    function0 _361_t7;
    uint8_t _361_t9;
    struct1 _361_t8;
    uint64_t _361_t10;
    int64_t _361_t6;
    int64_t _361_$retval;
    _361_t1 = _363_f;
    _361_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _361_t2 = _361_t1(_361_t3);
    $line_idx--;
    _361_t4 = _361_t2.tag;
    if (_361_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _361_t0 = 122;
    goto BB2;
BB7:
    _361_t0 = _361_t2._0;
    goto BB2;
BB2:
    _361_t7 = _363_f;
    _361_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _361_t8 = _361_t7(_361_t9);
    $line_idx--;
    _361_t10 = _361_t8.tag;
    if (_361_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _361_t6 = 122;
    goto BB4;
BB6:
    _361_t6 = _361_t8._0;
    goto BB4;
BB4:
    _361_$retval = $add_int64_t(_361_t0, _361_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _361_$retval;
}

struct1 _363_f(uint8_t _363_fail) {
    function2 _363_t1;
    struct1 _363_t2;
    uint64_t _363_t3;
    struct1 _363_$retval;
    int64_t _363_t5;
    struct1 _363_t0;
    int64_t _366_x;
    if (_363_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _363_t1 = _368_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _363_t2 = _363_t1();
    $line_idx--;
    _363_t3 = _363_t2.tag;
    if (_363_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _363_t5 = 0;
    _363_t0 = (struct1) {.tag=0, ._0=_363_t5};
    goto BB7;
BB2:
    _363_$retval = _363_t2;
    return _363_$retval;
BB4:
    _366_x = _363_t2._0;
    _363_t0 = (struct1) {.tag=0, ._0=_366_x};
    goto BB7;
BB7:
    _363_$retval = _363_t0;
    return _363_$retval;
}

struct1 _368_g(void) {
    struct1 _368_$retval;
    _368_$retval = (struct1) {.tag=1};
    return _368_$retval;
}

int main(void) {
  printf("%ld",_361_main());
  return 0;
}
