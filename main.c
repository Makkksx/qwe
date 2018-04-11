#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int comp_int(const void*a, const void *b)
{
    return *(int*)b-*(int*)a;
}
int comp_float(const void *b,const void *a)
{
    float eps = 0.000001;
    if (fabs(*(float*)b-*(float*)a) < eps)
        return 0;
    if ((*(float*)a-*(float*)b) > 0)
        return 1;
    else
        return -1;
  //  return ((*(const float *)b < *(const float *)a) -
        //    (*(const float *)a < *(const float * )b));
}
int comp_str(const void*b, const void *a)
{
    int c = strcmp(*(char**)a,*(char**)b);
    int d = strlen(*(char **)a) - strlen(*(char **)b);
    return (d == 0 ? c : d);
}
void swap1(const void *a, const void *b)
{
    int c =*(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = c;
    return;
}
void swap2(const void *a, const void *b)
{
    float c =*(float*)a;
    *(float*)a = *(float*)b;
    *(float*)b = c;
    return;
}
void swap3(const void *a, const void *b)
{
    char *s = (char*)malloc(50*sizeof(char));
    strcpy(s,*(char**)a);
    strcpy(*(char**)a,*(char**)b);
    strcpy(*(char**)b,s);
    return;
}
void sort( const void* arr, int n, size_t size, int (*comp)(const void *a,const void *b), void (*swap)(const void *a, const void *b))
{
    const char * array = (const char *)arr;
    for(int i = 0 ; i < n - 1; i++) {
        for(int j = 0 ; j < n - i - 1 ; j++)
            if(comp(array+j*size, array + (j+1)*size) < 0)
                swap(array+j*size,array+(j+1)*size);
    }
    return;
}

int main()
{
    int N = 5;
    int i = 0;
    int type; //  1-int 2-float 3-char*
    scanf("%d\n",&type);
    if (type==1)
    {
        int *arr = (int*) malloc(N*sizeof(int));
        for (i=0;i<N;i++)
            scanf(" %d",&arr[i]);
        sort(arr,N,sizeof(int),comp_int,swap1);
        for (i=0;i<N;i++)
            printf("%d\n",arr[i]);
    }
    if (type==2)
    {
        float *arr = (float*)malloc(N*sizeof(float));
        for (i=0;i<N;i++)
            scanf(" %f",&arr[i]);
        sort(arr,N,sizeof(float),comp_float,swap2);
        for (i=0;i<N;i++)
            printf("%g\n",arr[i]);
    }
    if (type==3)
    {
        char **arr = (char**) malloc(N*sizeof(char*));
        char str[10];
      //  getchar();
        for (i=0;i<N;i++)
        {
            arr[i] = (char*)malloc(50*sizeof(char));
            fgets(arr[i],50,stdin);
            arr[i][strlen(arr[i]) - 1] = '\0';
        }
        sort(arr,N,sizeof(char*),comp_str,swap3);
       // printf("\n");
        for (i=0;i<N;i++)
            printf("%s ",arr[i]);

    }
    return 0;
}
