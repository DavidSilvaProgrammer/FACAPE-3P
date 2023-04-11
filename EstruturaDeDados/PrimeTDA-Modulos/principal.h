#include "inter.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    TPilha *p=(TPilha*)malloc(sizeof(TPilha));
    TPilha_Inicia(p);
    
    TPilha_Insere(p,1);
    TPilha_Insere(p,2);
    TPilha_Insere(p,3);
    
    int aux;
    
    aux=TPilha_Retira(p);
    printf("\n SAIU! %d", aux);
    aux=TPilha_Retira(p);
    printf("\n SAIU! %d", aux);
    aux=TPilha_Retira(p);
    printf("\n SAIU! %d", aux);
    aux=TPilha_Retira(p);
    printf("\n SAIU! %d", aux);
    
    
    
    
    return 0;
}
