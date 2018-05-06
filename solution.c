#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define Len 500

int isValid(char* str)
{
    return  !strcmp( str+1 , ".txt" );
}

void search(char* dir_name , char simv)
{
    DIR* dir = opendir(dir_name);
    if (!dir)
        return;
    char* nextdir = (char*)malloc(sizeof(char)*Len);
    strcpy(nextdir , dir_name);
    struct dirent *de = readdir(dir);
    while(de)
    {
        if(de->d_type == DT_DIR && strcmp(de->d_name , ".") != 0 && strcmp(de->d_name , "..") != 0)
        {
            int leng = strlen(nextdir);
            strcat(nextdir , "/");
            strcat(nextdir , de->d_name);
            search(nextdir , simv);
            nextdir[leng] = '\0';
        }
        if(de->d_type == DT_REG)
        {
            int leng = strlen(nextdir);
            strcat(nextdir , "/");
            strcat(nextdir , de->d_name);
            if(simv == de->d_name[0] && isValid(de->d_name))
            {
                FILE* file = fopen("result.txt" , "a");
                fprintf( file , "%s\n" , nextdir);
                fclose(file);
            }
            nextdir[leng] = '\0';
        }
        de = readdir(dir);
    }
    free(nextdir);
    closedir(dir);
}

int main()
{
    char* str = (char*)malloc(sizeof(char)*Len);
    fgets(str , Len , stdin);
    for(int i=0; i<strlen(str); i++)
        search("./tmp" , str[i]);
    free(str);
    return 0;
}

