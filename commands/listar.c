#include "../command.h"

#include <dirent.h>
#include <stdio.h>

int listar (int argc, char* argv[]){
  if(argc < 2){

    struct dirent *dir;
    DIR *d = opendir("."); 

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }

    return RESULT_SUCCESS;
  }
  else {
    struct dirent *dir;
    DIR *d = opendir(argv[1]); 

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
        return RESULT_SUCCESS;
    }
    else{
        printf("Diretório não encontrado.\n");
        return RESULT_ERROR;
    }
  }
}