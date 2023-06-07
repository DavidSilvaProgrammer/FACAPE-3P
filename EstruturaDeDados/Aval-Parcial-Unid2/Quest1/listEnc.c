#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listEnc.h"

void criar(Lista* L){
    *L = NULL;
    printf("Fila de prioridade inicializada\n\n");
}

int vazia(Lista L){
    if(L == NULL){
        return 1;
    }else{
        return 0;
    }
}

void inserir(Lista* L, char nome[], int estado){
    inserirPrioridade(L, nome, estado);
    printf("%s foi adicionado a fila de prioridade\n", nome);
}

void mostrar(Lista L){
    printf("\nFila de prioridade:\n");
    while(L != NULL){
        printf("Nome: %s, Estado: %d\n", L->nome, L->estado);
        L = L->prox;
    }
    printf("\n");
}

void remover(Lista* L){
    if(vazia(*L)){
        printf("Impossivel remover: fila de prioridade vazia!\n");
    }else{
        Lista aux = *L;
        *L = (*L)->prox;
        free(aux);
        printf("Proximo paciente removido da fila de prioridade\n");
    }
}

void pesquisar(Lista L, char nome[]){
    if(vazia(L)){
        printf("Fila de prioridade vazia. Paciente nao encontrado!\n\n");
    }else{
        int encontrado = 0;
        while(L != NULL && !encontrado){
            if(strcmp(L->nome, nome) == 0){
                encontrado = 1;
            }
            L = L->prox;
        }
        if(encontrado){
            printf("Paciente %s esta na fila de prioridade\n\n", nome);
        }else{
            printf("Paciente %s nao esto na fila de prioridade\n\n", nome);
        }
    }
}

int prioridade(int estado){
    switch(estado){
        case 1: return 3;
        case 2: return 2;
        case 3: return 1;
        default: return 0;
    }
}

Lista criarNo(char nome[], int estado){
    Lista novo = (Lista)malloc(sizeof(struct no));
    strcpy(novo->nome, nome);
    novo->estado = estado;
    novo->prox = NULL;
    return novo;
}

void inserirPrioridade(Lista* L, char nome[], int estado){
    Lista novo = criarNo(nome, estado);

    if (vazia(*L) || prioridade(estado) > prioridade((*L)->estado)) {
        novo->prox = *L;
        *L = novo;
    } else {
        Lista atual = *L;
        while (atual->prox != NULL && prioridade(estado) <= prioridade(atual->prox->estado)) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}
