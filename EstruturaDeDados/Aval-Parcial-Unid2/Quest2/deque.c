#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

struct no {
    int item;
    Deque prox;
    Deque ant;
};

void criarDeque(Deque* D) {
    *D = NULL;
    printf("Deque inicializado\n\n");
}

int vazioDeque(Deque D) {
    if (D == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void inserirInicio(Deque* D, int x) {
    Deque novo = (Deque) malloc(sizeof(struct no));
    novo->item = x;
    novo->prox = *D;
    novo->ant = NULL;
    if (!vazioDeque(*D)) {
        (*D)->ant = novo;
    }
    *D = novo;
    printf("%d foi inserido no inicio do Deque\n", x);
}

void inserirFim(Deque* D, int x) {
    Deque novo = (Deque) malloc(sizeof(struct no));
    novo->item = x;
    novo->prox = NULL;
    if (vazioDeque(*D)) {
        *D = novo;
        novo->ant = NULL;
    } else {
        Deque p = *D;
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = novo;
        novo->ant = p;
    }
    printf("%d foi inserido no fim do Deque\n", x);
}

int removerInicio(Deque* D) {
    if (vazioDeque(*D)) {
        printf("Impossivel remover: Deque vazio!\n");
        return -1;
    } else {
        int valor = (*D)->item;
        Deque aux = *D;
        *D = (*D)->prox;
        if (*D != NULL) {
            (*D)->ant = NULL;
        }
        free(aux);
        printf("Item removido do inicio do Deque: %d\n", valor);
        return valor;
    }
}

int removerFim(Deque* D) {
    if (vazioDeque(*D)) {
        printf("Impossivel remover: Deque vazio!\n");
        return -1;
    } else {
        int valor;
        Deque p = *D;
        if (p->prox == NULL) {
            valor = p->item;
            *D = NULL;
            free(p);
        } else {
            while (p->prox != NULL) {
                p = p->prox;
            }
            valor = p->item;
            p->ant->prox = NULL;
            free(p);
        }
        printf("Item removido do fim do Deque: %d\n", valor);
        return valor;
    }
}

void mostrarDeque(Deque D) {
    printf("[ ");
    while (D != NULL) {
        printf("%d ", D->item);
        D = D->prox;
    }
    printf("]\n");
}
