/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685916327
#define ORNG_1685916327

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _65_x;
	int64_t _63_t4;
	uint8_t _63_t2;
	int64_t _63_t6;
	int64_t _63_t10;
	int64_t _63_$retval;
BB0:
	_65_x = 0;
	goto BB1;
BB1:
	_63_t4 = 10;
	_63_t2 = _65_x < _63_t4;
	if (!_63_t2) {
		goto BB11;
	} else {
		goto BB2;
	}
BB2:
	_63_t6 = 1;
	_65_x = _65_x + _63_t6;
	_63_t10 = 1;
	_65_x = _65_x + _63_t10;
	goto BB1;
BB11:
	_63_$retval = _65_x;
	return _63_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
