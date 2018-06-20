#include <stdio.h>
#include <stdlib.h>

void add_int(void*a, const void *b)
{
    *(int*)a+=*(int*)b;
    return;
}

void add_char(void *a,const void *b)
{
    *(int*)a+=*(char*)b;
    return;
}

void sum(void *narray, size_t size, size_t elem_size, void* init, void (*add)(void *,const void *))
{
    int i;
    for(i = 0; i < size; i++)
        add(init,narray + i * elem_size);
}

int main()
{
    int N = 20;
    int i = 0;
    int type;
    scanf("%d\n",&type);
    int res=0;
    if (type==4)
    {
        int *arr = (int*) malloc(N*sizeof(int));
        for (i=0;i<N;i++)
            scanf(" %d",&arr[i]);
        sum(arr,N,sizeof(int), &res, add_int);
        printf("%d",res);
    }
    if (type==1)
    {
        char *arr = (char*) malloc(N*sizeof(char));
        for (i=0;i<N;i++)
            scanf(" %c",&arr[i]);
        sum(arr,N,sizeof(char),&res, add_char);
        printf("%d",res);

    }
    return 0;
}
