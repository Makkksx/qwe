#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main()
{
    int i=0;
    int d=1;
    char c;
    char *s1=malloc(51*sizeof(char));
 //  char*begunok=s1;
    while ((c=getchar()) != '!')
    {
        if (c == '\n')
            continue;
        s1[i++]=c;                                      //ВВОД
        if ((i%50)==0)
        {
            s1=realloc(s1,50*sizeof(char)*(++d)+sizeof(char));
        //    printf("k");
        }
    }
    s1[i++]='!';
    s1[i]='\0';
    //printf("%s",s1);


   /* fgets(begunok,51,stdin);
    while(strchr(s1,'!') == NULL )
    {
        s1=realloc(s1,50*sizeof(char)*(++i)+sizeof(char));       //СТАРЫЙ ВВОД


        begunok=s1+(i-1)*50;
        fgets(begunok,51,stdin);
    }
    s1[strlen(s1)-1]='\0';*/
    i=0;
    int bil_probel,t,b;
    char *s_new=malloc(strlen(s1)*sizeof(char));
    char*nachalo=s_new;
    int n=0;
    int m=0;
    while(s1[i]!='\0')
    {
     //   m++;
        n++;
        b=t=bil_probel=0;
        while ((s1[i]!=';') && (s1[i]!='.') && (s1[i] != '?') && (s1[i] != '!'))
        {
            if ((!isspace(s1[i])) || (bil_probel))                              //УДАЛЕНИЕ ПРОБЕЛОВ В НАЧАЛЕ
                {
                    s_new[t++]=s1[i];
                    if (!bil_probel)
                        bil_probel=1;
                }
            i++;
        }
    s_new[t++]=s1[i++];
    s_new[t]='\0';
    for(t = 0; t < strlen(s_new); t++)
        if (isdigit(s_new[t]) && (t!=0))
            if (!isspace(s_new[t-1]) && !isspace(s_new[t+1]) && !(s_new[t+1]=='!') && !(s_new[t+1]==';') && !(s_new[t+1]=='.') && !(s_new[t+1]=='?'))
            {
                b=1;                   //ПРОВЕРКА НА ЦИФРУ ВНУТРИ
            }

   // printf("%c\n",s1[i-1]);
    if (!b)
    {
        printf("%s\n",s_new);
        m++;
    }

    s_new=nachalo;
    }
    printf("Количество предложений до %d и количество предложений после %d",n-1,m);
    free(s1);
    free(s_new);
    return 0;
}
