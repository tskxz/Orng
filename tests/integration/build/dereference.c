/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685230411
#define ORNG_1685230411

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _9_t1;
	int64_t* _9_t2;
	int64_t* _9_t7;
	int64_t _9_t8;
	int64_t _9_$retval;
BB0: // 1
// Versions: 1
	_9_t1 = 29;
// Versions: 1
	_9_t2 = &_9_t1;
// Versions: 1
	_9_t7 = _9_t2;
// Versions: 1
	_9_t8 = *_9_t7;
// Versions: 1
	_9_$retval = _9_t8;
	goto end;
end:
	return _9_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
