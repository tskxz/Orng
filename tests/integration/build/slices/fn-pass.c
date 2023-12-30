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
        int64_t _2;
        int64_t _3;
} struct0;

typedef struct {
        int64_t* _0;
        int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _1295_main(void);
int64_t _1297_f(struct1 _1297_x);

/* Function definitions */
int64_t _1295_main(void){
    int64_t _1295_t1;
    int64_t _1295_t2;
    int64_t _1295_t3;
    int64_t _1295_t4;
    struct0 _1296_x;
    int64_t _1295_t6;
    int64_t _1295_t7;
    int64_t* _1295_t8;
    int64_t _1295_t9;
    struct1 _1296_y;
    function2 _1295_t10;
    int64_t _1295_t11;
    int64_t _1295_$retval;
    _1295_t1 = 1;
    _1295_t2 = 2;
    _1295_t3 = 3;
    _1295_t4 = 4;
    _1296_x = (struct0) {_1295_t1, _1295_t2, _1295_t3, _1295_t4};
    _1295_t6 = 0;
    _1295_t7 = 4;
    $bounds_check(_1295_t6, _1295_t7, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1295_t8 = ((int64_t*)&_1296_x + _1295_t6);
    _1295_t9 = 4;
    _1296_y = (struct1) {_1295_t8, _1295_t9};
    _1295_t10 = _1297_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1295_t11 = _1295_t10(_1296_y);
    $line_idx--;
    _1295_$retval = _1295_t11;
    return _1295_$retval;
}

int64_t _1297_f(struct1 _1297_x){
    int64_t _1297_t0;
    int64_t _1297_t1;
    int64_t _1297_$retval;
    _1297_t0 = 1;
    _1297_t1 = 80;
    $bounds_check(_1297_t0, _1297_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1297_$retval = $add_int64_t(*((int64_t*)_1297_x._0 + _1297_t0), _1297_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1297_$retval;
}

int main(void) {
  printf("%ld",_1295_main());
  return 0;
}
