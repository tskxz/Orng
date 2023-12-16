/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

typedef struct {
    int64_t _0;
    int64_t _1;
} struct2;

typedef int64_t(*function1)(int64_t, int64_t);

/* Function forward definitions */
int64_t _940_main(void);
int64_t _942_fib(int64_t _942_n);
int64_t _947_add(int64_t _947_x,int64_t _947_y);

/* Function definitions */
int64_t _940_main(void){
    function0 _940_t0;
    int64_t _940_t2;
    int64_t _940_t1;
    int64_t _940_t3;
    int64_t _940_$retval;
    _940_t0 = _942_fib;
    _940_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _940_t1 = _940_t0(_940_t2);
    $line_idx--;
    _940_t3 = 10;
    _940_$retval = $sub_int64_t(_940_t1, _940_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _940_$retval;
}

int64_t _942_fib(int64_t _942_n){
    function1 _942_t7;
    function0 _942_t9;
    int64_t _942_t11;
    int64_t _942_t12;
    int64_t _942_t10;
    function0 _942_t13;
    int64_t _942_t15;
    int64_t _942_t16;
    int64_t _942_t14;
    int64_t _942_t8;
    int64_t _942_t0;
    int64_t _942_t1;
    uint8_t _942_t2;
    int64_t _942_t3;
    uint8_t _942_t4;
    int64_t _942_$retval;
    _942_t1 = 0;
    _942_t2 = _942_n == _942_t1;
    if (_942_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _942_t0 = 0;
    goto BB5;
BB6:
    _942_t3 = 1;
    _942_t4 = _942_n == _942_t3;
    if (_942_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _942_$retval = _942_t0;
    return _942_$retval;
BB8:
    _942_t0 = 1;
    goto BB5;
BB10:
    _942_t7 = _947_add;
    _942_t9 = _942_fib;
    _942_t11 = 1;
    _942_t12 = $sub_int64_t(_942_n, _942_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _942_t10 = _942_t9(_942_t12);
    $line_idx--;
    _942_t13 = _942_fib;
    _942_t15 = 2;
    _942_t16 = $sub_int64_t(_942_n, _942_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _942_t14 = _942_t13(_942_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _942_t8 = _942_t7(_942_t10, _942_t14);
    $line_idx--;
    _942_t0 = _942_t8;
    goto BB5;
}

int64_t _947_add(int64_t _947_x,int64_t _947_y){
    int64_t _947_$retval;
    _947_$retval = $add_int64_t(_947_x, _947_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _947_$retval;
}

int main(void) {
  printf("%ld",_940_main());
  return 0;
}
