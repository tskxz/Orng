/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686626622
#define ORNG_1686626622

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef struct {
	int64_t _0;
	int64_t _1;
} struct4;
typedef int64_t(*function3)(int64_t, int64_t);

/* Function forward definitions */
int64_t _211_main();
int64_t _212_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _211_main() {
	function3 _211_t0;
	function3 _211_t2;
	int64_t _211_t4;
	int64_t _211_t5;
	int64_t _211_t3;
	function3 _211_t6;
	int64_t _211_t8;
	int64_t _211_t9;
	int64_t _211_t7;
	int64_t _211_$retval;
BB0:
	_211_t0 = _212_add;
	_211_t2 = _212_add;
	_211_t4 = 47;
	_211_t5 = 1;
	_211_t3 = _211_t2(_211_t4, _211_t5);
	_211_t6 = _212_add;
	_211_t8 = 1;
	_211_t9 = 1;
	_211_t7 = _211_t6(_211_t8, _211_t9);
	_211_$retval = _211_t0(_211_t3, _211_t7);
	return _211_$retval;
}

int64_t _212_add(int64_t x,int64_t y) {
	int64_t _212_$retval;
BB0:
	_212_$retval = x + y;
	return _212_$retval;
}


int main()
{
  printf("%ld",_211_main());
  return 0;
}

#endif
