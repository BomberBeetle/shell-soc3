#include "../command.h"

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#if defined (_WIN32)
    #include "windows.h"
#endif

int apagar(int argc, char* argv[]){

    if(argc < 2){
        printf("Uso do comando: %s [nome]\n", argv[0]);
        return RESULT_EMPTY;
    }

    DIR* directory = opendir(argv[1]);
    if(directory != NULL){
        char strRemove[265]="rmdir /s ";
        strcat(strRemove,argv[1]);
        system(strRemove);
        printf("Deletado.\n");
        return RESULT_SUCCESS;
    }
    else if(errno == ENOTDIR){
        #if defined (_WIN32)
        DeleteFileA(argv[1]);
        printf("Deletado.\n");
        return RESULT_SUCCESS;
        #else
        printf("Não implementado.\n");
        #endif

    }
    else{
        printf("Arquivo ou diretório não encontrado.\n");
    }


    return RESULT_SUCCESS;
}