#include "command.h"
#include <stdlib.h>
#include <string.h>

//Método de inserção de comandos para a árvore.
//Args: Arvore, chave do comando, function pointer do comando (Assinatura: int comando(int argc, char** argv))

void ctree_insert(CommandTree *tree, char *ckey, int (*ncmd) (int, char*[])){
  //struct CTree_Node newNode = {.childL = NULL, .childR = NULL, .cmd = ncmd};
  struct CTree_Node *newNode = malloc(sizeof(struct CTree_Node));
  strcpy(newNode->key, ckey);
  newNode->childL = NULL;
  newNode->childR = NULL;
  newNode->cmd = ncmd;

  //Se a raiz da árvore for nula, faça ela ser o nó do novo comando.

  if(tree->root == NULL){
    tree->root = newNode;
    return;
  }

  //Algoritmo de inserção em árvore binária.

  else{
    struct CTree_Node *curNode = tree->root;
    while(1){
      if(strcmp(curNode->key, newNode->key) > 0){
        if(curNode->childR != NULL){
          curNode = curNode->childR;
        }
        else{
          curNode->childR = newNode;
          break;
        }
      }
      else{
        if(curNode->childL != NULL){
          curNode = curNode->childL;
        }
        else{
          curNode->childL = newNode;
          break;
        }
      }
    }
    
  }
}

//Procurar por chave e executar.
//Args: arvore, numero de argumentos de comando, valor dos argumentos de comando.

int exec_command(CommandTree tree, int argc, char* argv[]){

  //Se nao houverem argumentos (ou se o argv[0] for nulo...), retorne o código de comando vazio

  if(argc < 1 || !(strcmp(argv[0],""))){
    return RESULT_EMPTY;
  }


  //Algoritmo de procura de elemento em árvore binária.

  else{
    struct CTree_Node *curNode = tree.root;
    while(1){

      //Se não for achado o elemento, retorne o código de comando não achado. lol
      if(curNode == NULL){
        return RESULT_NOTFOUND;
      }
      
      int diff_keys = strcmp(curNode->key, argv[0]);


      //Se for achado, execute o comando e retorne o código de retorno que for passado pelo mesmo.
      if(diff_keys == 0){
        return curNode->cmd(argc, argv);
      }

      if(strcmp(curNode->key, argv[0]) > 0){
          curNode = curNode->childR;
      }
      else{
          curNode = curNode->childL;
      }
    }
  }
};