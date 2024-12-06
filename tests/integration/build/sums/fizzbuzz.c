/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
struct struct2 {
    uint8_t* _0;
    int64_t _1;
};

struct struct1 {
    uint64_t tag;
    union {
        struct struct2 _0;
        int64_t _1;
    };
};

typedef struct struct1(*function0)(int64_t);

/* Interned Strings */
char* string_0 = "\x66\x69\x7A\x7A\x62\x75\x7A\x7A";
char* string_1 = "\x62\x75\x7A\x7A";
char* string_2 = "\x66\x69\x7A\x7A";

/* Function forward definitions */
struct struct2 _1536_main(void);
struct struct1 _1539_fizzbuzz(int64_t _1539_n);


/* Function definitions */
struct struct2 _1536_main(void){
    function0 _1536_t0;
    int64_t _1536_t2;
    struct struct1 _1536_t1;
    uint64_t _1536_t3;
    struct struct2 _1536_$retval;
    _1536_t0 = (function0) _1539_fizzbuzz;
    _1536_t2 = 30;
    $lines[$line_idx++] = "tests/integration/sums/fizzbuzz.orng:3:14:\n    fizzbuzz(30).string\n            ^";
    _1536_t1 = _1536_t0(_1536_t2);
    $line_idx--;
    _1536_t3 = _1536_t1.tag;
    $tag_check(_1536_t3, 0, "tests/integration/sums/fizzbuzz.orng:2:8:\nfn main()-> String {\n      ^");
    _1536_$retval = _1536_t1._0;
    return _1536_$retval;
}

struct struct1 _1539_fizzbuzz(int64_t _1539_n){
    int64_t _1539_t1;
    int64_t _1539_t2;
    int64_t _1539_t3;
    uint8_t _1539_t4;
    struct struct1 _1539_t0;
    struct struct2 _1539_t13;
    struct struct2 _1539_t15;
    struct struct2 _1539_t11;
    int64_t _1539_t8;
    int64_t _1539_t9;
    uint8_t _1539_t10;
    struct struct1 _1539_$retval;
    int64_t _1539_t5;
    int64_t _1539_t6;
    uint8_t _1539_t7;
    _1539_t1 = 0;
    _1539_t2 = 15;
    _1539_t3 = $mod_int64_t(_1539_n, _1539_t2, "tests/integration/sums/fizzbuzz.orng:12:13:\n        {n % 15} => .string(\"fizzbuzz\")\n           ^");
    _1539_t4 = _1539_t1==_1539_t3;
    if (_1539_t4) {
        goto BB1764;
    } else {
        goto BB1767;
    }
BB1764:
    _1539_t11 = (struct struct2) {(uint8_t*)string_0, 8};
    _1539_t0 = (struct struct1) {.tag=0, ._0=_1539_t11};
    goto BB1766;
BB1767:
    _1539_t5 = 5;
    _1539_t6 = $mod_int64_t(_1539_n, _1539_t5, "tests/integration/sums/fizzbuzz.orng:13:13:\n        {n % 5}  => .string(\"buzz\")\n           ^");
    _1539_t7 = _1539_t1==_1539_t6;
    if (_1539_t7) {
        goto BB1770;
    } else {
        goto BB1771;
    }
BB1766:
    _1539_$retval = _1539_t0;
    return _1539_$retval;
BB1770:
    _1539_t13 = (struct struct2) {(uint8_t*)string_1, 4};
    _1539_t0 = (struct struct1) {.tag=0, ._0=_1539_t13};
    goto BB1766;
BB1771:
    _1539_t8 = 3;
    _1539_t9 = $mod_int64_t(_1539_n, _1539_t8, "tests/integration/sums/fizzbuzz.orng:14:13:\n        {n % 3}  => .string(\"fizz\")\n           ^");
    _1539_t10 = _1539_t1==_1539_t9;
    if (_1539_t10) {
        goto BB1774;
    } else {
        goto BB1776;
    }
BB1774:
    _1539_t15 = (struct struct2) {(uint8_t*)string_2, 4};
    _1539_t0 = (struct struct1) {.tag=0, ._0=_1539_t15};
    goto BB1766;
BB1776:
    _1539_t0 = (struct struct1) {.tag=1, ._1=_1539_n};
    goto BB1766;
}


int main(void) {
  printf("%s",_1536_main()._0);
  return 0;
}
