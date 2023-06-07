typedef struct no* Lista;

struct no{
    char nome[50];
    int estado;
    struct no* prox;
};

void criar(Lista* L);
int vazia(Lista L);
void inserir(Lista* L, char nome[], int estado);
void mostrar(Lista L);
void remover(Lista* L);
void pesquisar(Lista L, char nome[]);
int prioridade(int estado);

Lista criarNo(char nome[], int estado);
void inserirPrioridade(Lista* L, char nome[], int estado);
