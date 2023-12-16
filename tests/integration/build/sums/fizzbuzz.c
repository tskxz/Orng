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
} struct2;

typedef struct {
    uint64_t tag;
    union {
        struct2 _0;
        int64_t _1;
    };
} struct1;

typedef struct1(*function0)(int64_t);

/* Interned Strings */
char* string_0 = "\x66\x69\x7A\x7A\x62\x75\x7A\x7A";
char* string_1 = "\x62\x75\x7A\x7A";
char* string_2 = "\x66\x69\x7A\x7A";

/* Function forward definitions */
struct2 _1406_main(void);
struct1 _1409_fizzbuzz(int64_t _1409_n);

/* Function definitions */
struct2 _1406_main(void){
    function0 _1406_t0;
    int64_t _1406_t2;
    struct1 _1406_t1;
    struct2 _1406_$retval;
    _1406_t0 = _1409_fizzbuzz;
    _1406_t2 = 30;
    $lines[$line_idx++] = "tests/integration/sums/fizzbuzz.orng:3:14:\n    fizzbuzz(30).string\n            ^";
    _1406_t1 = _1406_t0(_1406_t2);
    $line_idx--;
    _1406_$retval = _1406_t1._0;
    return _1406_$retval;
}

struct1 _1409_fizzbuzz(int64_t _1409_n){
    int64_t _1409_t1;
    int64_t _1409_t2;
    int64_t _1409_t3;
    uint8_t _1409_t4;
    struct1 _1409_t0;
    struct2 _1409_t13;
    struct2 _1409_t15;
    struct2 _1409_t11;
    int64_t _1409_t8;
    int64_t _1409_t9;
    uint8_t _1409_t10;
    struct1 _1409_$retval;
    int64_t _1409_t5;
    int64_t _1409_t6;
    uint8_t _1409_t7;
    _1409_t1 = 0;
    _1409_t2 = 15;
    _1409_t3 = $mod_int64_t(_1409_n, _1409_t2, "tests/integration/sums/fizzbuzz.orng:12:13:\n        {n % 15} => .string <- \"fizzbuzz\"\n           ^");
    _1409_t4 = _1409_t1 == _1409_t3;
    if (_1409_t4) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _1409_t11 = (struct2) {(uint8_t*)string_0, 8};
    _1409_t0 = (struct1) {.tag=0, ._0=_1409_t11};
    goto BB6;
BB7:
    _1409_t5 = 5;
    _1409_t6 = $mod_int64_t(_1409_n, _1409_t5, "tests/integration/sums/fizzbuzz.orng:13:13:\n        {n % 5}  => .string <- \"buzz\"\n           ^");
    _1409_t7 = _1409_t1 == _1409_t6;
    if (_1409_t7) {
        goto BB10;
    } else {
        goto BB11;
    }
BB6:
    _1409_$retval = _1409_t0;
    return _1409_$retval;
BB10:
    _1409_t13 = (struct2) {(uint8_t*)string_1, 4};
    _1409_t0 = (struct1) {.tag=0, ._0=_1409_t13};
    goto BB6;
BB11:
    _1409_t8 = 3;
    _1409_t9 = $mod_int64_t(_1409_n, _1409_t8, "tests/integration/sums/fizzbuzz.orng:14:13:\n        {n % 3}  => .string <- \"fizz\"\n           ^");
    _1409_t10 = _1409_t1 == _1409_t9;
    if (_1409_t10) {
        goto BB14;
    } else {
        goto BB16;
    }
BB14:
    _1409_t15 = (struct2) {(uint8_t*)string_2, 4};
    _1409_t0 = (struct1) {.tag=0, ._0=_1409_t15};
    goto BB6;
BB16:
    _1409_t0 = (struct1) {.tag=1, ._1=_1409_n};
    goto BB6;
}

int main(void) {
  printf("%s",_1406_main()._0);
  return 0;
}
