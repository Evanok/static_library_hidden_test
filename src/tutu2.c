#include "tutu2.h"

static void unused_static_tutu2_function (float value)
{
	float new_value = 42.32;

	printf ("super static useless unused function: %f\n", new_value * value);
}

void unused_tutu2_function (float value)
{
	float new_value = 42.32;

	printf ("super useless unused function: %f\n", new_value * value);
}