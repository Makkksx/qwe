#include <stdio.h>
#include <string.h>



int main() {
    int n;
    scanf("%d ", &n);
    char str[100];
    fgets(str,100,stdin);
    for (int i=0;i<100;i++)
    {
        printf("%c",(26-n%26+str[i]-'a')%26 + 'a');
        if (i == strlen(str)-2)
            return 0;
    }
    return 0;
}
