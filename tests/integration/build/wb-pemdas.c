/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685256120
#define ORNG_1685256120

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _23_t1;
	int64_t* _24_y;
	int64_t _23_t6;
	int64_t _23_t7;
	uint8_t _23_t4;
	int64_t _26_z;
	int64_t _23_t12;
	int64_t _23_t15;
	int64_t _23_t17;
	int64_t _23_t18;
	int64_t _23_t19;
	int64_t _23_t21;
	int64_t _23_t22;
	int64_t _23_t24;
	int64_t _23_t25;
	int64_t _23_t26;
	int64_t _23_t27;
	int64_t _23_t3;
	int64_t _23_$retval;
BB0:
	_23_t1 = 0;
	_24_y = &_23_t1;
	_23_t6 = *_24_y;
	_23_t7 = 0;
	_23_t4 = _23_t6 == _23_t7;
	if (!_23_t4) {
		goto BB6;
	} else {
		goto BB1;
	}
BB1:
	_26_z = *_24_y;
	_23_t12 = _26_z + _26_z;
	_23_t15 = _26_z * _26_z;
	_23_t17 = 1;
	_23_t18 = _26_z + _23_t17;
	_23_t19 = _23_t15 / _23_t18;
	_23_t21 = 1;
	_23_t22 = _26_z + _23_t21;
	_23_t24 = 1;
	_23_t25 = _26_z + _23_t24;
	_23_t26 = powf(_23_t25, _23_t22);
	_23_t27 = _23_t19 % _23_t26;
	_23_t3 = _23_t12 - _23_t27;
	goto BB4;
BB4:
	_23_$retval = _23_t3;
	return _23_$retval;
BB6:
	_23_t3 = 1000;
	goto BB4;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif