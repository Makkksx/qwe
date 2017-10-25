#include "index_last_negative.h"
#include "index_first_negative.h"
int index_last_negative(int mas[], int ssize)
{
	int i;
	i = ssize + 1 - index_first_negative(mas, ssize);
    return i;
}
