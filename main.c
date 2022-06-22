#include <stdio.h>

#include "command.h"

#include "commands/ajuda.h"
#include "commands/criar.h"
#include "commands/datahora.h"
#include "commands/exit.h"
#include "commands/inserir.h"
#include "commands/limpar.h"
#include "commands/ver.h"
#include "commands/listar.h"
#include "commands/apagar.h"
#include "commands/renomear.h"
#include "commands/mover.h"

#include "commands/test_commands.h"

#define READ_LIMIT ARG_LIMIT*2

int main(int argc, char *argv[]){

    CommandTree commands = {NULL};

    //Inserir comandos aqui
    ctree_insert(&commands, "CRIAR", criar);
    ctree_insert(&commands, "INSERIR", inserir);
    ctree_insert(&commands, "SAIR", exit_shell);
    ctree_insert(&commands, "LIMPAR", limpar);
    ctree_insert(&commands, "DATA", data);
    ctree_insert(&commands, "HORA", hora);
    ctree_insert(&commands, "AJUDA", ajuda);
    ctree_insert(&commands, "VER", ver);
    ctree_insert(&commands, "LISTAR", listar);
    ctree_insert(&commands, "APAGAR", apagar);
    ctree_insert(&commands, "DELETAR", apagar);
    ctree_insert(&commands, "RENOMEAR", renomear);
    ctree_insert(&commands, "MOVER", mover);


    char in[READ_LIMIT];
    char* arg_buf[ARG_LIMIT];
    unsigned int arg_count = 0, last_index= 0;

    int space_before = 0;
    
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
                
                if(i != 0) space_before = (in[i-1] == ' ');
                else       space_before = 1;
                
                if(arg_count == 0){ //Checar espaços antes do comando
                    if(space_before){
                        last_index = i+1;
                        continue;
                    }
                }

                in[i]='\0'; //Adicionar terminador de string para separar o argumento do resto da string;
                arg_buf[arg_count] = &(in[last_index]); //Crie um ponteiro pro começo do argumento.
                arg_count++; //Incremente a contagem de argumentos.
                last_index = i+1; //Assinale o começo do próximo token para o próximo caractere da string.
            }
        }
        
    }
    return 0;
}