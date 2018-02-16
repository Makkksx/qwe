#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comp(const void *a, const void *b)
{
    return ( *(int*)b - *(int*)a );
}
int main()
{
    int N=1000;
    int a[N];
    for (int i=0;i<N;i++)
        scanf("%d",&a[i]);
    time_t t=time(NULL);
    qsort(a,N,sizeof(int),comp);
    int p=t-time(NULL);

    for (int i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("%d",p);
    return 0;
}
