#include <stdio.h>
#include "deque.h"

int main() {
    Deque deque;
    criarDeque(&deque);

    inserirInicio(&deque, 1);
    inserirInicio(&deque, 2);
    inserirFim(&deque, 3);
    inserirFim(&deque, 4);

    mostrarDeque(deque);

    int removidoInicio = removerInicio(&deque);
    int removidoFim = removerFim(&deque);

    printf("Item removido do inicio: %d\n", removidoInicio);
    printf("Item removido do fim: %d\n", removidoFim);

    mostrarDeque(deque);

    return 0;
}
