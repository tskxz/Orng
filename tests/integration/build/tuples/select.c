/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1574_main(void);

/* Function definitions */
int64_t _1574_main(void){
    int64_t _1574_t1;
    int64_t _1574_t2;
    struct struct0 _1575_x;
    int64_t _1574_$retval;
    _1574_t1 = 50;
    _1574_t2 = 5;
    _1575_x = (struct struct0) {_1574_t1, _1574_t2};
    _1574_$retval = $add_int64_t(_1575_x._0, _1575_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _1574_$retval;
}

int main(void) {
  printf("%ld",_1574_main());
  return 0;
}
