/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686980573
#define ORNG_1686980573

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _307_main();

/* Function definitions */
int64_t _307_main() {
	int64_t _307_t1;
	int64_t _307_t2;
	struct1 _308_x;
	int64_t _307_t3;
	int64_t _307_t4;
	int64_t _307_$retval;
BB0:
	_307_t1 = 20;
	_307_t2 = 3;
	_308_x = (struct1) {_307_t1, _307_t2};
	_307_t3 = _308_x._0;
	_307_t4 = _308_x._1;
	_307_$retval = _307_t3 * _307_t4;
	return _307_$retval;
}


int main()
{
  printf("%ld",_307_main());
  return 0;
}

#endif
