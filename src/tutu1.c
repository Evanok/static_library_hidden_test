#include "tutu1.h"

void this_is_the_only_public_function_tutu1 (int input)
{	
	int new_value = input + normal_tutu3_function();
	printf ("value is %d\n", new_value);
}