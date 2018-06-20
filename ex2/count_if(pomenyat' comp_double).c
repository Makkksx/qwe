#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int intparity(const void* n)
{
    if((*(int*)n)%2==0) return 1;
    else return 0;
}
int doubleparity(const void* n)
{
    if( (int)*(double*)n % 2 == 0 && fabs( *(double*)n - (int)*(double*)n ) < 1e-6 )
        return 1;
    else return 0;
}
int count_if(void *base, size_t num, size_t size, int (*pred)(const void*)){
    int i, counter=0;
    for(i=0;i<num;i++)
        counter+=pred(base+size*i);
    return counter;
}
int main(){
    size_t size;
    scanf("%d", &size);
    char * format_string;
    int (*pred)(const void *);
    void * array;
    switch (size) {
    case 4:
        array = malloc(20 * sizeof(int));
        format_string = " %d";
        pred = intparity;
        break;
    case 8:
        array = malloc(20 * sizeof(double));
        format_string = " %lf";
        pred = doubleparity;
        break;
    }
    int i;
    for (i = 0; i < 5; ++i)
        scanf(format_string, array + i * size);
    printf("%d",count_if(array,5,size,pred));
    return 0;

}
