#include <stdio.h>

#include "command.h"

#include "test_commands.h"

#define READ_LIMIT ARG_LIMIT*2

int main(int argc, char *argv[]){

    CommandTree commands = {NULL};

    ctree_insert(&commands, "args", test_args);
    ctree_insert(&commands, "args_alias", test_args);
    ctree_insert(&commands, "test", test_success);

    char in[READ_LIMIT];
    char* arg_buf[ARG_LIMIT];
    unsigned int arg_count = 0, last_index= 0;
    
    arg_buf[0] = NULL;

    while(1){
        printf(">>");
        fgets(in, READ_LIMIT, stdin);
         
        arg_count = 0;
        last_index = 0;

        for(unsigned int i = 0; in[i]!='\0'; i++){

            if(in[i] == '\n'){

                in[i]='\0';
                arg_buf[arg_count] = &(in[last_index]);
                arg_count++;

                if(arg_count != 0){

                    int result = exec_command(commands, arg_count, arg_buf);

                    if(result == RESULT_NOTFOUND){
                        printf("Comando não encontrado.\n");
                    }

                }
                
            } 

            else if(in[i] == ' '){

                in[i]='\0'; //Adicionar terminador de string para separar o argumento do resto da string;
                arg_buf[arg_count] = &(in[last_index]); //Crie um ponteiro pro começo do argumento.
                last_index = i+1; //Assinale o começo do próximo token para o próximo caractere da string.
                arg_count++; //Incremente a contagem de argumentos.

            }
        }
        
    }
    return 0;
}