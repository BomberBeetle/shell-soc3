#if defined (_WIN32)
    #include <windows.h>
#elif defined (unix)
    #include <sys/stat.h>
#endif

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../command.h"

void stitch_entry_name(char* dest, int argc, char* argv[]){
    dest[0] = '\0';
    for(int i = 2; i < argc; i++){
        if(i == 2){
            strcat(dest, argv[i]);
        }
        else{
            strcat(dest, " ");
            strcat(dest, argv[i]);
        }
    }
}

int criar(int argc, char* argv[]){

    if(argc < 3){
        printf("Argumentos insuficientes. Uso: %s (-a/-d) nome\n", argv[0]);
        return RESULT_ERROR;
    }
    else{

        if(!strcmp(argv[1], "-d")){

            char ent_name[ARG_LIMIT*2];
            stitch_entry_name(ent_name, argc, argv);  

            #if defined (_WIN32)
                bool bDir = CreateDirectoryA(ent_name,NULL);
             if(bDir==false)
             {
                 int error = GetLastError();
                 if(error == 183)
                 {
                     printf("\n Falha na Criacao: Diretorio Ja Existente!\n");
                    return RESULT_ERROR;
                 }
                 else{
                    printf("\n Falha na Criacao de Diretorio - Erro No.%d\n",GetLastError()); 
                    return RESULT_ERROR;
                 }


             }
             else{
                printf("\nDiretorio %s Criado com Sucesso!\n",dir);
                return RESULT_SUCESS;
             }
            #elif defined(unix)
                printf("\n Comando não implementado para UNIX.");
                return RESULT_ERROR;
            #endif

            
            
        }

        else if(!strcmp(argv[1], "-a")){
            char ent_name[ARG_LIMIT*2];
            stitch_entry_name(ent_name, argc, argv);
            #if defined(_WIN32)
                int return_code = RETURN_ERROR;
                HANDLE New_File = CreateFileA(ent_name,
               GENERIC_READ|GENERIC_WRITE,
               FILE_SHARE_READ,
               NULL,
               CREATE_NEW,
               FILE_ATTRIBUTE_NORMAL,
               NULL);
               if(New_File == INVALID_HANDLE_VALUE)
               {
                   int file_error = GetLastError();
                   if(file_error==80)
                   {
                       printf("Falha na Criacao do Arquivo: Arquivo Ja Existente");    
                       
                   }

                   else{
                        printf("\nFalha na Criacao do Arquivo - Erro No.%d\n",GetLastError());
                        

                   }




               }
               else{
                printf("\nArquivo %s Criado com Sucesso!",File_Path);
                return_code = RETURN_SUCESS
               }
               CloseHandle(New_File);

               return return_code;
            #elif defined(unix)
                printf("lol.");
                return RESULT_NOTFOUND;
            #endif

        }

        else{
            printf("Opção não reconhecida: %s\n", argv[1]);
            return RESULT_ERROR;
        }

    }
}

