#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main() {
    Aluno map[MAX_MAP];
    int n = 0;
    char opcao;
 
    do {
        printf("Escolha uma opcao:\n");
        printf("(I)nserir\n");
        printf("(R)emover\n");
        printf("(P)rocurar\n");
        printf("(L)istar\n");
        printf("(D)estruir\n");
        printf("(S)air\n");
        
 		printf("\nDigite a opcao: ");
        scanf(" %c", &opcao);
        printf("\n");
 
        switch (opcao) {
            case 'I':
            case 'i':
                inserir(map, &n);
                break;
            case 'R':
            case 'r':
                remover(map, &n);
                break;
            case 'P':
            case 'p':
                procurar(map, n);
                break;
            case 'L':
            case 'l':
                listar(map, n);
                break;
            case 'D':
            case 'd':
                destruir(map, &n);
                break;
            case 'S':
            case 's':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
 
        printf("\n");
    } while (opcao != 'S' && opcao != 's');
 
    return 0;
}
