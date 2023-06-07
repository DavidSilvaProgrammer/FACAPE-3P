typedef struct no* Deque;

void criarDeque(Deque* D);
int vazioDeque(Deque D);
void inserirInicio(Deque* D, int x);
void inserirFim(Deque* D, int x);
int removerInicio(Deque* D);
int removerFim(Deque* D);
void mostrarDeque(Deque D);
