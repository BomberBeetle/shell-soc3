#pragma once


//Tamanho limite de um argumento.
#define ARG_LIMIT 1024

//Códigos de retorno de comando.

#define RESULT_EMPTY -2
#define RESULT_NOTFOUND -1
#define RESULT_SUCCESS 0
#define RESULT_ERROR 1

//Struct de nó de árvore binária, para o armazenamento dos comandos.

struct CTree_Node{
  struct CTree_Node *childL, *childR;
  char key[ARG_LIMIT];
  int (*cmd) (int, char*[]); 
};

//Typedef de árvore, só pra ficar bunitin.

typedef struct CommandTree{
  struct CTree_Node *root;
} CommandTree;

//Funções da árvore.

void ctree_insert(CommandTree *, char *, int (*) (int, char*[]));
int exec_command(CommandTree, int, char*[]);