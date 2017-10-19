#include <stdio.h>
#include <stdlib.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "sum_between_negative.h"
#include <math.h>

int main()
{
    int n;
    char t,y;
    int array[100];
    int i=1;
    scanf("%d%c",&n,&y);
    scanf("%d",&array[0]);
    t = getchar();
    while (t!= '\n')
    {
        scanf("%d%c",&array[i],&t);
        i++;
    }
    int sum=0;
    for (int j=0;j<i;j++)
        sum+=abs(array[j]);
    switch (n)
    {
    case 0:
        printf("%d",index_first_negative(array,i));
        break;
    case 1:
        printf("%d",index_last_negative(array,i));
        break;
    case 2:
        printf("%d",sum_between_negative(array,i));
        break;
    case 3:
        printf("%d",sum-sum_between_negative(array,i));
        break;
    default:
        printf("Данные неккоректны");
    }
    return 0;
}
