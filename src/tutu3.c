#include "tutu3.h"

static int my_static_tutu3_function (void)
{
	return 42 + MY_SUPER_ARRAY[2];
}


int normal_tutu3_function (void)
{
	int var = 2 * my_static_tutu3_function();
	return var;
}