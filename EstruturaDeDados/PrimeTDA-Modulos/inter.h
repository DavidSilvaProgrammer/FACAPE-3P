#define MAXTAM 100

typedef struct{
    int Item[MAXTAM];
    int Topo;
} TPilha;

void TPilha_Inicia(TPilha *p);

int TPilha_Vazia(TPilha *p);

int TPilha_Cheia(TPilha *p);

void TPilha_Insere(TPilha *p,int x);

int TPilha_Retira(TPilha *p);
