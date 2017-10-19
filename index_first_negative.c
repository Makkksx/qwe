#include "index_first_negative.h"

int index_first_negative(int mas[], int ssize)
{
    for(int i=0;i<ssize;i++)
    {
        if (mas[i]<0)
        {
            return i;
        }
    }
    return -1;
}
