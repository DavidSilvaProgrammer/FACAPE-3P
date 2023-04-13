#define MAX_SIZE 500
int topo = -1;
int pilha[MAX_SIZE];

void push(double valor);

double pop();

int eh_operador(char ch);

int precedencia(char ch);


char* infix_para_posfixa(char* expressao);

double avaliar_posfixa(char* expressao);
