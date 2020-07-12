#include "multi_before_and_after_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"
#include <math.h>
int multi_before_and_after_negative(int mas[], int ssize)
{
	int i,t=1;
	for (i = 0; i < index_first_negative(mas, ssize); i++)
		t *= mas[i];
	for (i = index_last_negative(mas,ssize); i < ssize; i++)
		t *= mas[i];
	return t;
}
