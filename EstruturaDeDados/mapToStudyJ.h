#define MAX_NOME 50
#define MAX_MAP 100


typedef struct {
    int matricula;
    char nome[MAX_NOME];
} Aluno;

void inserir(Aluno *map, int *n);
void remover(Aluno *map, int *n);
void procurar(Aluno *map, int n);
void listar(Aluno *map, int n);
void destruir(Aluno *map, int *n);
