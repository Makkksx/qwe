#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i=0;
    int d=1;
    char c;
    char *s1=malloc(51*sizeof(char));

    while ((c=getchar()) != '!')
    {
      //  if (c == '\n')
      //      continue;
        s1[i++]=c;                                      //����
        if ((i%50)==0)
        {
            s1=realloc(s1,50*sizeof(char)*(++d)+sizeof(char));
        }
    }
    s1[i++]='!';
    s1[i]='\0';

 /*  char*begunok=s1;
    fgets(begunok,51,stdin);
    while(strchr(s1,'!') == NULL )
    {
        s1=realloc(s1,50*sizeof(char)*(++i)+sizeof(char));       //������ ����


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
            if ((!isspace(s1[i])) || (bil_probel))                              //�������� �������� � ������
                {
                    s_new[t++]=s1[i];
                    if (!bil_probel)
                        bil_probel=1;
                }
            i++;
        }
        s_new[t++]=s1[i++];
        s_new[t]='\0';
        for(t = 1; t < strlen(s_new); t++)
            if (isdigit(s_new[t]) && !isdigit(s_new[t-1]) && !isspace(s_new[t-1]) && !isspace(s_new[t+1]) && !(s_new[t+1]=='!') && !(s_new[t+1]==';') && !(s_new[t+1]=='.') && !(s_new[t+1]=='?'))
            {
                while(isdigit(s_new[t]))
                    t++;
                if (!isspace(s_new[t]) && !(s_new[t]=='!') && !(s_new[t]==';') && !(s_new[t]=='.') && !(s_new[t]=='?'))
                    {
                        b=1;            //b=1 - �� ���� �������� ������
                        break;
                    }              //�������� �� ����� ������
            }

        if (!b)
        {
            printf("%s\n",s_new);
            m++;
        }

        s_new=nachalo;
    }
    printf("���������� ����������� �� %d � ���������� ����������� ����� %d",n-1,m);
    free(s1);
    free(s_new);
    return 0;
}
