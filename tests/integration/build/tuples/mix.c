/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;
struct struct3;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

struct struct2 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

typedef struct struct2(*function0)(int64_t, int64_t);

struct struct3 {
    int64_t _0;
    int64_t* _1;
};

/* Function forward definitions */
int64_t _1888_main(void);
struct struct2 _1890_get_array(int64_t _1890_a, int64_t _1890_b);


/* Function definitions */
int64_t _1888_main(void){
    function0 _1888_t0;
    int64_t _1888_t2;
    int64_t _1888_t3;
    int64_t _1889_z;
    int64_t* _1888_t9;
    struct struct3 _1889_y;
    int64_t _1888_$retval;
    _1888_t0 = (function0) _1890_get_array;
    _1888_t2 = 15;
    _1888_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1888_t0(_1888_t2, _1888_t3);
    $line_idx--;
    _1889_z = 64;
    _1888_t9 = &_1889_z;
    _1889_y = (struct struct3) {_1889_z, _1888_t9};
    _1888_$retval = _1889_y._0;
    return _1888_$retval;
}

struct struct2 _1890_get_array(int64_t _1890_a, int64_t _1890_b){
    struct struct2 _1890_$retval;
    _1890_$retval = (struct struct2) {_1890_a, _1890_b, _1890_a, _1890_b};
    return _1890_$retval;
}


int main(void) {
  printf("%ld",_1888_main());
  return 0;
}
