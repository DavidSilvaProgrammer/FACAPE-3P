#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserir(Aluno *map, int *n) {
	int i;
	
    if (*n == MAX_MAP) {
        printf("Nao eh possivel inserir mais alunos. Mapeamento cheio.\n");
        return;
    }
 
    Aluno novo;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &novo.matricula);
    printf("Digite o nome do aluno: ");
    scanf("%s", novo.nome);
 
    for (i = 0; i < *n; i++) {
        if (map[i].matricula == novo.matricula) {
            printf("Ja existe um aluno com esta matricula.\n");
            return;
        }
    }
 
    map[*n] = novo;
    (*n)++;
    printf("Aluno inserido com sucesso.\n");
}

void remover(Aluno *map, int *n) {
	int matricula;
	int posicao = -1;
	int i;
	
	if (*n == 0) {
    	printf("Nao eh possivel remover alunos. Mapeamento vazio.\n");
    	return;
	}
 
	printf("Digite a matricula do aluno a ser removido: ");
	scanf("%d", &matricula);
 
	for (i = 0; i < *n; i++) {
    	if (map[i].matricula == matricula) {
        	posicao = i;
        	break;
    	}
	}
 
	if (posicao == -1) {
    	printf("Aluno nao encontrado.\n");
    	return;
	}
 
	for (i = posicao; i < *n - 1; i++) {
    	map[i] = map[i+1];
	}
	(*n)--;
	printf("Aluno removido com sucesso.\n");
}

void procurar(Aluno *map, int n) {
	int matricula;
	int posicao = -1;
	int i;
	
	if (n == 0) {
    	printf("Nao ha alunos cadastrados.\n");
    	return;
	}
 
	printf("\nDigite a matricula do aluno a ser procurado: ");
	scanf("%d", &matricula);
 
	for (i = 0; i < n; i++) {
    	if (map[i].matricula == matricula) {
        	posicao = i;
        	break;
    	}
	}
 
	if (posicao == -1) {
    	printf("Aluno nao encontrado.\n");
    	return;
	}
 
	printf("Matricula: %d\n", map[posicao].matricula);
	printf("Nome: %s\n", map[posicao].nome);
}

void listar(Aluno *map, int n) {
	int i;
	
	if (n == 0) {
		printf("Nao ha alunos cadastrados.\n");
		return;
	}
	
	printf("Matricula\tNome\n");
	for (i = 0; i < n; i++) {
    	printf("%d\t\t%s\n", map[i].matricula, map[i].nome);
	}
}

void destruir(Aluno *map, int *n) {
	*n = 0;
	printf("Mapeamento de alunos destruido.\n");
}
