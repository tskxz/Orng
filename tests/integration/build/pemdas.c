/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682995710
#define ORNG_1682995710

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int _1;
	int _2;
	int _3;
	int _4;
	int _5;
	int _6;
	int _7;
	int _8;
	int _9;
	int _10;
	int _11;
	int _12;
BB0:;
	_0 = 4;
	_1 = 7;
	_2 = _0 + _1;
	_3 = 4;
	_4 = 2;
	_5 = _3 / _4;
	_6 = _2 * _5;
	_7 = 3;
	_8 = 3;
	_9 = powf(_8, _7);
	_10 = 4;
	_11 = _9 % _10;
	_12 = _6 - _11;
	retval = _12;
	goto end;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
