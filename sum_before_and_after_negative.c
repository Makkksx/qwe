#include "sum_before_and_after_negative.h"
int sum_before_and_after_negative(int mas[], int ssize, int sum)
{
	int t;
	t = sum - sum_between_negative(mas, ssize);
	return t;
}

