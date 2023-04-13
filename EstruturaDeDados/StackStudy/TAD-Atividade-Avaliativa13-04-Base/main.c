#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 500
#include "interface.h"


int main() {
char expressao[MAX_SIZE];
printf("Digite uma expressão aritmética em notação infixada: ");
fgets(expressao, MAX_SIZE, stdin);
expressao[strcspn(expressao, "\n")] = '\0'; // Remove o caractere '\n' do final da string
char* posfixa = infix_para_posfixa(expressao);
printf("Notação posfixa: %s\n", posfixa);
double resultado = avaliar_posfixa(posfixa);
printf("Resultado da expressão: %0.2lf\n", resultado);
free(posfixa);
return 0;
}
