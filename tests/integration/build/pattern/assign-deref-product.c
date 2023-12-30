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
} struct0;

/* Function forward definitions */
int64_t _1114_main(void);

/* Function definitions */
int64_t _1114_main(void){
    int64_t _1114_t1;
    int64_t _1114_t2;
    int64_t _1114_t3;
    struct0 _1115_x;
    int64_t _1114_t4;
    int64_t _1114_t5;
    int64_t* _1115_a;
    int64_t _1114_t7;
    int64_t _1114_t8;
    int64_t* _1115_b;
    int64_t _1114_t10;
    int64_t _1114_t11;
    int64_t* _1115_c;
    int64_t _1114_t14;
    int64_t _1114_t15;
    int64_t _1114_t16;
    struct0 _1114_t13;
    int64_t _1114_t17;
    int64_t _1114_$retval;
    _1114_t1 = 0;
    _1114_t2 = 0;
    _1114_t3 = 0;
    _1115_x = (struct0) {_1114_t1, _1114_t2, _1114_t3};
    _1114_t4 = 0;
    _1114_t5 = 3;
    $bounds_check(_1114_t4, _1114_t5, "tests/integration/pattern/assign-deref-product.orng:4:14:\n    let a = &mut x[0]\n            ^");
    _1115_a = ((int64_t*)&_1115_x + _1114_t4);
    _1114_t7 = 1;
    _1114_t8 = 3;
    $bounds_check(_1114_t7, _1114_t8, "tests/integration/pattern/assign-deref-product.orng:5:14:\n    let b = &mut x[1]\n            ^");
    _1115_b = ((int64_t*)&_1115_x + _1114_t7);
    _1114_t10 = 2;
    _1114_t11 = 3;
    $bounds_check(_1114_t10, _1114_t11, "tests/integration/pattern/assign-deref-product.orng:6:14:\n    let c = &mut x[2]\n            ^");
    _1115_c = ((int64_t*)&_1115_x + _1114_t10);
    _1114_t14 = 100;
    _1114_t15 = 30;
    _1114_t16 = 30;
    _1114_t13 = (struct0) {_1114_t14, _1114_t15, _1114_t16};
    *_1115_a = _1114_t13._0;
    *_1115_b = _1114_t13._1;
    *_1115_c = _1114_t13._2;
    _1114_t17 = $add_int64_t(*_1115_a, *_1115_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1114_$retval = $add_int64_t(_1114_t17, *_1115_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1114_$retval;
}

int main(void) {
  printf("%ld",_1114_main());
  return 0;
}
