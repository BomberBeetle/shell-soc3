#include <stdlib.h>
#include "../command.h"

int exit_shell(int argc, char * argv[]){
    exit(0);
    return RESULT_SUCCESS; //Isso nunca vai acontecer.
}