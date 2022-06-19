#include "../command.h"

#include <stdio.h>

int ajuda(int argc, char* argv[]){
    printf("AJUDA -> Mostra essa mensagem.\nDATA -> Mostra a data atual do sistema.\nHORA -> Mostra a hora atual do sistema\nVER nomedoarquivo -> Mostra os conteúdos de um arquivo.\nCRIAR (-d | -a) nome -> Cria um arquivo ou diretório vazio.\n INSERIR \"texto..\" nomedoarquivo -> Insere texto em um arquivo.\nMOVER pastaouarquivo novolugar -> Move um arquivo ou diretório.\nRENOMEAR pastaouarquivo nome -> Renomeia um arquivo ou diretório.\nAPAGAR nome - Apaga um arquivo ou diretório. Outros nomes para o comando: DELETAR.\nLISTAR (opcional:diretorio) -> Lista arquivos e subdiretórios em um diretório. Se não for dado um nome de diretório, será usado o diretório onde o programa foi iniciado.\nLIMPAR -> Limpa a tela.\nSAIR - Termina o programa.\n");
    return RESULT_SUCCESS;
}