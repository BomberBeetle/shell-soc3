//Códigos de retorno de comando.
#define RESULT_EMPTY -2
#define RESULT_NOTFOUND -1
#define RESULT_SUCESS 0
#define RESULT_ERROR 1

//Struct de nó de árvore binária, para o armazenamento dos comandos.
struct CTree_Node{
  struct CTree_Node *childL, *childR;
  char *key;
  int (*cmd) (int, char**); 
};

//Typedef de árvore, só pra ficar bunitin.
typedef struct CommandTree{
  struct CTree_Node *root;
} CommandTree;

//Funções da árvore.
void ctree_insert(CommandTree *, char *, int (*) (int, char**));
int lookup_and_exec(CommandTree *, int, char**);