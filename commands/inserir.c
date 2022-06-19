#include "inserir.h"
#include "../command.h"

#include <stdio.h>
#include <string.h>

//TODO: Args handling + input stiching

int stitch_insert_text(char* dest, int argc, char* argv[]){

    unsigned char reading = 0; //I don't want to include stdbool.h, so unsigned char will do.

    for(int i = 1; i < argc; i++){
     if(argv[i][0] != '\"' && !reading) continue;
     else if(!reading){
         reading = 1;
         if(strlen(argv[i]) < 2){
             strcat(&(argv[i])[1], dest); //&(argv[i])[1] is terrible. it will eventually segfault. however, i do not care
         }
     }
     else{
         if(argv[i][strlen(argv[i])-1] == '\"'){
             reading = 0;
             strcat(" ", dest);
             strcat(argv[i], dest);
         }
         else{
             strcat(" ", dest);
             strcat(argv[i], dest);
         }
     }
    }
    return reading?RESULT_ERROR:RESULT_SUCCESS;
}

int inserir(int argc, char * argv[])
{
    if(argc < 3){
        printf("Uso: INSERIR nomedoarquivo \"Escrever entrada aqui.\"\n");
        return RESULT_ERROR;
    }

    char text[ARG_LIMIT] = "\0";
    int stich_code = stitch_insert_text(text, argc, argv);

    if(stich_code == RESULT_ERROR){
        printf("Erro de sintaxe: não fechou/abriu aspas.\n");
        return RESULT_ERROR;
    }

    char* File_Path = argv[argc-1];

    FILE *arq = fopen(File_Path,"r");
    if(arq == NULL)
    {
        printf("Erro ao Abrir Arquivo");
        fclose(arq);
        return RESULT_ERROR;

    }
    else
    {

        fclose(arq);
        arq = fopen(File_Path,"a");
                 
                 //printf("\nDigite o Texto a ser Inserido no Arquivo:\n$ ");
        
                 //getchar();scanf("%[^\n]",text);
        fprintf(arq,"%s\n",text);
        fclose(arq);
        printf("\nGravacao no Arquivo Feita com Sucesso!\n");
        return RESULT_SUCCESS;
    }    
}