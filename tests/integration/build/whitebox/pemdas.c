/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1987_main(void);


/* Function definitions */
int64_t _1987_main(void){
    int64_t _1988_x;
    int64_t* _1988_y;
    int64_t _1987_t5;
    uint8_t _1987_t7;
    int64_t _1987_t4;
    int64_t _1987_$retval;
    int64_t _1990_z;
    int64_t* _1987_t10;
    int64_t _1987_t13;
    int64_t _1987_t14;
    int64_t _1987_t16;
    int64_t _1987_t17;
    int64_t _1987_t20;
    _1988_x = 0;
    _1988_y = &_1988_x;
    _1987_t5 = 0;
    _1987_t7 = *_1988_y==_1987_t5;
    if (_1987_t7) {
        goto BB2185;
    } else {
        goto BB2189;
    }
BB2185:
    _1990_z = *_1988_y;
    _1987_t10 = &_1990_z;
    *_1987_t10 = $add_int64_t(_1990_z, _1990_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1990_z = $sub_int64_t(_1990_z, _1990_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1990_z = $mult_int64_t(_1990_z, _1990_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1987_t13 = 1;
    _1987_t14 = $add_int64_t(_1990_z, _1987_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1990_z = $div_int64_t(_1990_z, _1987_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1987_t16 = 1;
    _1987_t17 = $add_int64_t(_1990_z, _1987_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1990_z = $mod_int64_t(_1990_z, _1987_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1987_t20 = -1;
    _1990_z = $mult_int64_t(_1990_z, _1987_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1987_t4 = $mult_int64_t(_1990_z, _1987_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2188;
BB2189:
    _1987_t4 = 1000;
    goto BB2188;
BB2188:
    _1987_$retval = _1987_t4;
    return _1987_$retval;
}


int main(void) {
  printf("%ld",_1987_main());
  return 0;
}
