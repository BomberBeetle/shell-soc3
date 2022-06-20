#include "../command.h"
#include <stdio.h>

int ver(int argc, char*argv[]){
    if(argc < 2){
        printf("Uso: VER nomedoarquivo\n");
        return RESULT_ERROR;
    }
    else{
        FILE* arq = fopen(argv[1], "r");
        if(arq){
            char c = fgetc(arq);
            while (c != EOF)
                {
                    printf ("%c", c);
                    c = fgetc(arq);
                }
            printf("\n");
            return RESULT_SUCCESS;
        }
        else{
            printf("Arquivo não encontrado.\n");
            return RESULT_ERROR;
        }
    }
}