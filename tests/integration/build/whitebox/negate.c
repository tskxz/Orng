/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935517134351891
#define ORNG_1688935517134351891

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _3_x;
	int64_t* _3_y;
	int64_t _2_t4;
	int64_t _2_t5;
	int64_t _2_t7;
	uint8_t _2_t3;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_3_x = 1;
	_3_y = &_3_x;
	_2_t4 = *_3_y;
	_2_t5 = -_2_t4;
	_2_t7 = -1;
	_2_t3 = _2_t5 == _2_t7;
	if (!_2_t3) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_2_t2 = 32;
	goto BB6;
BB6:
	_2_$retval = _2_t2;
	return _2_$retval;
BB9:
	_2_t2 = 10;
	goto BB6;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
