#include "test_commands.h"

#include "command.h"
#include <stdio.h>

int test_success(int argc, char* argv[]){
    printf("Hello World!\n");
    return RESULT_SUCCESS;
}

int test_args(int argc, char* argv[]){
    printf("Argc: %d\n", argc);
    for(int i = 0; i < argc; i++){
        printf("[%s]\n", argv[i]);
    }
    return RESULT_SUCCESS;
}