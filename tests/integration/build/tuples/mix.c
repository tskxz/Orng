/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1693029152386386103
#define ORNG_1693029152386386103

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
struct0 _4_get_array(int64_t _4_a,int64_t _4_b);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	struct0 _2_t0;
	struct0 _3_x;
	int64_t _2_$retval;
BB0:
	_2_t1 = 15;
	_2_t2 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)";
	_2_t0 = _4_get_array(_2_t1, _2_t2);
	_3_x = _2_t0;
	_2_$retval = 64;
	return _2_$retval;
}

struct0 _4_get_array(int64_t _4_a,int64_t _4_b) {
	struct0 _4_$retval;
BB0:
	_4_$retval = (struct0) {_4_a, _4_b, _4_a, _4_b};
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif