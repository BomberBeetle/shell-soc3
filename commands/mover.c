#include "../command.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int mover(int argc, char* argv[]){
    if(argc < 3){
        printf("Uso: MOVER nome novodiretorio");
    }
    char strMove[263]= "move ";
    strcat(strMove,argv[1]);
    strcat(strMove," ");
    strcat(strMove,argv[2]);
    system(strMove);
    return RESULT_SUCCESS;
}