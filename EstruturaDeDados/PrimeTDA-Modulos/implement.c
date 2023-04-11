#include "inter.h"
#include <stdio.h>
#include <stdlib.h>


void TPilha_Inicia(TPilha *p){
    p->Topo=-1;
}

int TPilha_Vazia(TPilha *p){
    if(p->Topo == -1){
        return 1;
    }else{
        return 0;
    }
}

int TPilha_Cheia(TPilha *p){
    if(p->Topo == MAXTAM-1){
        return 1;
    }else{
        return 0;
    }
}

void TPilha_Insere(TPilha *p,int x){
    if(TPilha_Cheia(p)==1){
        printf("ERRO: Pilha cheia");
    }else{
        p->Topo++;
        p->Item[p->Topo]=x;
    }
}

int TPilha_Retira(TPilha *p){
    int aux;
    if(TPilha_Vazia(p)==1){
        printf("\nERRO: Pilha vazia");
        //coloquei para retorna aux=0 na lista vazia
        //para não ficar lixo de memória na variável aux
        aux=0;
        return aux;
    }else{
        aux=p->Item[p->Topo];
        p->Topo--;
        return aux;
    }
}
