/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684895482
#define ORNG_1684895482

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	uint8_t _28_t0;
	uint8_t _28_t1;
	uint8_t _0;
BB0: // 1
	_28_t0 = 1;
	_28_t1 = !_28_t0;
	retval = _28_t1;
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