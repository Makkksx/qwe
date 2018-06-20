#include <stdio.h>
#include <ctype.h>
int function(){
    int rn,b=0;
    scanf("%d",&rn);
    if(rn==1)
        b++;
    if(rn==0)
    {
        scanf("%d",&rn);
        if(rn==0)
            return 0;
        if(rn==1)
            b++;
    }
    b+=function();
    return b;
}

int main(){
    printf("%d",function());
    return 0;
}
