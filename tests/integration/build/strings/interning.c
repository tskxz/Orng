/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint8_t* _0;
    int64_t _1;
};

typedef int64_t(*function1)(struct struct0);

/* Interned Strings */
char* string_0 = "\x48\x65\x6C\x6C\x6F";

/* Function forward definitions */
int64_t _1495_main(void);
int64_t _1497_get_length(struct struct0 _1497_s);


/* Function definitions */
int64_t _1495_main(void){
    struct struct0 _1496_x;
    struct struct0 _1496_y;
    function1 _1495_t4;
    int64_t _1495_t5;
    function1 _1495_t6;
    int64_t _1495_t7;
    int64_t _1495_t8;
    int64_t _1495_t9;
    int64_t _1495_$retval;
    _1496_x = (struct struct0) {(uint8_t*)string_0, 5};
    _1496_y = (struct struct0) {(uint8_t*)string_0, 5};
    _1495_t4 = (function1) _1497_get_length;
    $lines[$line_idx++] = "tests/integration/strings/interning.orng:5:16:\n    get_length(x) + get_length(y) + 296\n              ^";
    _1495_t5 = _1495_t4(_1496_x);
    $line_idx--;
    _1495_t6 = (function1) _1497_get_length;
    $lines[$line_idx++] = "tests/integration/strings/interning.orng:5:32:\n    get_length(x) + get_length(y) + 296\n                              ^";
    _1495_t7 = _1495_t6(_1496_y);
    $line_idx--;
    _1495_t8 = $add_int64_t(_1495_t5, _1495_t7, "tests/integration/strings/interning.orng:5:20:\n    get_length(x) + get_length(y) + 296\n                  ^");
    _1495_t9 = 296;
    _1495_$retval = $add_int64_t(_1495_t8, _1495_t9, "tests/integration/strings/interning.orng:5:36:\n    get_length(x) + get_length(y) + 296\n                                  ^");
    return _1495_$retval;
}

int64_t _1497_get_length(struct struct0 _1497_s){
    int64_t _1497_$retval;
    goto BB1737;
BB1737:
    _1497_$retval = _1497_s._1;
    return _1497_$retval;
}


int main(void) {
  printf("%ld",_1495_main());
  return 0;
}
