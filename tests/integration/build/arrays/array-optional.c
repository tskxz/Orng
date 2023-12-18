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
} struct2;

typedef struct {
    struct2 _0;
    struct2 _1;
} struct1;

typedef struct {
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct4;

typedef struct {
    struct4 _0;
    struct4 _1;
    struct4 _2;
} struct3;

typedef struct3(*function0)(struct2, struct2);

typedef struct {
    int64_t _0;
    int64_t _1;
} struct6;

typedef struct4(*function5)(int64_t, int64_t);

/* Function forward definitions */
int64_t _49_main(void);
struct3 _51_safe_div_vec(struct2 _51_x,struct2 _51_y);
struct4 _66_safe_div(int64_t _66_x,int64_t _66_y);

/* Function definitions */
int64_t _49_main(void){
    function0 _49_t0;
    int64_t _49_t3;
    int64_t _49_t4;
    int64_t _49_t5;
    struct2 _49_t2;
    int64_t _49_t7;
    int64_t _49_t8;
    int64_t _49_t9;
    struct2 _49_t6;
    struct3 _49_t1;
    struct3 _50_res;
    int64_t _49_t10;
    int64_t _49_t11;
    uint64_t _49_t12;
    int64_t _49_$retval;
    _49_t0 = _51_safe_div_vec;
    _49_t3 = 216;
    _49_t4 = 432;
    _49_t5 = 648;
    _49_t2 = (struct2) {_49_t3, _49_t4, _49_t5};
    _49_t7 = 1;
    _49_t8 = 2;
    _49_t9 = 3;
    _49_t6 = (struct2) {_49_t7, _49_t8, _49_t9};
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:3:28:\n    let res = safe_div_vec((216, 432, 648), (1, 2, 3))\n                          ^";
    _49_t1 = _49_t0(_49_t2, _49_t6);
    $line_idx--;
    _50_res = _49_t1;
    _49_t10 = 1;
    _49_t11 = 3;
    $bounds_check(_49_t10, _49_t11, "tests/integration/arrays/array-optional.orng:4:12:\n    res[1].some\n          ^");
    _49_t12 = (*((struct4*)&_50_res + _49_t10)).tag;
    $bounds_check(_49_t10, _49_t11, "tests/integration/arrays/array-optional.orng:2:3:\nfn main() -> Int {\n ^");
    $tag_check(_49_t12, 1, "tests/integration/arrays/array-optional.orng:2:3:\nfn main() -> Int {\n ^");
    _49_$retval = (*((struct4*)&_50_res + _49_t10))._1;
    return _49_$retval;
}

struct3 _51_safe_div_vec(struct2 _51_x,struct2 _51_y){
    struct4 _51_t2;
    struct4 _51_t4;
    struct4 _51_t6;
    struct3 _61_retval;
    function5 _51_t7;
    int64_t _51_t9;
    int64_t _51_t10;
    int64_t _51_t11;
    int64_t _51_t12;
    struct4 _51_t8;
    int64_t _51_t13;
    int64_t _51_t14;
    function5 _51_t15;
    int64_t _51_t17;
    int64_t _51_t18;
    int64_t _51_t19;
    int64_t _51_t20;
    struct4 _51_t16;
    int64_t _51_t21;
    int64_t _51_t22;
    function5 _51_t23;
    int64_t _51_t25;
    int64_t _51_t26;
    int64_t _51_t27;
    int64_t _51_t28;
    struct4 _51_t24;
    int64_t _51_t29;
    int64_t _51_t30;
    struct3 _51_$retval;
    _51_t2 = (struct4) {.tag=0};
    _51_t4 = (struct4) {.tag=0};
    _51_t6 = (struct4) {.tag=0};
    _61_retval = (struct3) {_51_t2, _51_t4, _51_t6};
    _51_t7 = _66_safe_div;
    _51_t9 = 0;
    _51_t10 = 3;
    _51_t11 = 0;
    _51_t12 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^";
    $bounds_check(_51_t9, _51_t10, "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^");
    $bounds_check(_51_t11, _51_t12, "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^");
    _51_t8 = _51_t7(*((int64_t*)&_51_x + _51_t9), *((int64_t*)&_51_y + _51_t11));
    $line_idx--;
    _51_t13 = 0;
    _51_t14 = 3;
    $bounds_check(_51_t13, _51_t14, "tests/integration/arrays/array-optional.orng:9:12:\n    retval[0] = safe_div(x[0], y[0])\n          ^");
    *((struct4*)&_61_retval + _51_t13) = _51_t8;
    _51_t15 = _66_safe_div;
    _51_t17 = 1;
    _51_t18 = 3;
    _51_t19 = 1;
    _51_t20 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^";
    $bounds_check(_51_t17, _51_t18, "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^");
    $bounds_check(_51_t19, _51_t20, "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^");
    _51_t16 = _51_t15(*((int64_t*)&_51_x + _51_t17), *((int64_t*)&_51_y + _51_t19));
    $line_idx--;
    _51_t21 = 1;
    _51_t22 = 3;
    $bounds_check(_51_t21, _51_t22, "tests/integration/arrays/array-optional.orng:10:12:\n    retval[1] = safe_div(x[1], y[1])\n          ^");
    *((struct4*)&_61_retval + _51_t21) = _51_t16;
    _51_t23 = _66_safe_div;
    _51_t25 = 2;
    _51_t26 = 3;
    _51_t27 = 2;
    _51_t28 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^";
    $bounds_check(_51_t25, _51_t26, "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^");
    $bounds_check(_51_t27, _51_t28, "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^");
    _51_t24 = _51_t23(*((int64_t*)&_51_x + _51_t25), *((int64_t*)&_51_y + _51_t27));
    $line_idx--;
    _51_t29 = 2;
    _51_t30 = 3;
    $bounds_check(_51_t29, _51_t30, "tests/integration/arrays/array-optional.orng:11:12:\n    retval[2] = safe_div(x[2], y[2])\n          ^");
    *((struct4*)&_61_retval + _51_t29) = _51_t24;
    _51_$retval = _61_retval;
    return _51_$retval;
}

struct4 _66_safe_div(int64_t _66_x,int64_t _66_y){
    int64_t _66_t1;
    uint8_t _66_t3;
    int64_t _66_t6;
    struct4 _66_t0;
    struct4 _66_$retval;
    _66_t1 = 0;
    _66_t3 = _66_y == _66_t1;
    if (_66_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _66_t0 = (struct4) {.tag=0};
    goto BB6;
BB7:
    _66_t6 = $div_int64_t(_66_x, _66_y, "tests/integration/arrays/array-optional.orng:19:21:\n        .some <- x / y\n                   ^");
    _66_t0 = (struct4) {.tag=1, ._1=_66_t6};
    goto BB6;
BB6:
    _66_$retval = _66_t0;
    return _66_$retval;
}

int main(void) {
  printf("%ld",_49_main());
  return 0;
}
