/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688146807093997542
#define ORNG_1688146807093997542

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
	int64_t _4;
} struct1;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t3;
	int64_t _2_t4;
	int64_t _2_t5;
	struct1 _3_x;
	int64_t _2_t7;
	int64_t _2_t8;
	int64_t* _2_t9;
	int64_t _2_t10;
	struct3 _3_y;
	int64_t _2_t11;
	int64_t _2_t12;
	int64_t _2_t13;
	int64_t _2_t14;
	int64_t _2_$retval;
BB0:
	_2_t1 = 1;
	_2_t2 = 2;
	_2_t3 = 3;
	_2_t4 = 4;
	_2_t5 = 5;
	_3_x = (struct1) {_2_t1, _2_t2, _2_t3, _2_t4, _2_t5};
	_2_t7 = 0;
	_2_t8 = *(((int64_t*)(&_3_x))+_2_t7);
	_2_t9 = (((int64_t*)(&_3_x))+_2_t7);
	_2_t10 = 5;
	_3_y = (struct3) {_2_t9, _2_t10};
	_2_t11 = 2;
	_2_t12 = 81;
	*(((int64_t*)((&_3_y)->_0))+_2_t11) = _2_t12;
	_2_t13 = 2;
	_2_t14 = *(((int64_t*)((&_3_y)->_0))+_2_t13);
	_2_$retval = _2_t14;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
