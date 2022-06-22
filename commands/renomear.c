#include "../command.h"
#include <stdio.h>

int renomear(int argc, char* argv[]){
            if(argc < 3){
                printf("Uso: RENOMEAR nomeAntigo nomeNovo\n");               
            }
            int check = rename(argv[1],argv[2]);
            if(check==0)
            {
                printf("\nModificado com Sucesso!");
                return RESULT_SUCCESS;
            }
            else{
                printf("\nErro ao Modificar");
                return RESULT_ERROR;
            }
}