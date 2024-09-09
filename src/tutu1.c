#include "tutu3.h"
#include "tutu2.h"
#include "common.h"
#include "tutu1.h"

void __attribute__ ((visibility ("default"))) this_is_the_only_public_function_tutu1 (int input)
{	
	int new_value = input + normal_tutu3_function();
	printf ("value is %d\n", new_value);
}