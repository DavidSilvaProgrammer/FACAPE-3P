#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 500
#include "interface.h"



void push(double valor) {
    if (topo == MAX_SIZE - 1) {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
    pilha[++topo] = valor;
}

double pop() {
    if (topo == -1) {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    return pilha[topo--];
}

int eh_operador(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

int precedencia(char ch) {
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}


char* infix_para_posfixa(char* expressao) {
    int i, j;
    char* posfixa = (char*)malloc(sizeof(char) * (strlen(expressao) + 1));
    char ch;
    for (i = 0, j = 0; expressao[i] != '\0'; i++) {
        ch = expressao[i];
        if (isdigit(ch)) {
            posfixa[j++] = ch;
            while (isdigit(expressao[++i])) {
                posfixa[j++] = expressao[i];
            }
            posfixa[j++] = ' '; // Adiciona espa�o ap�s o operando
            i--;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (topo != -1 && pilha[topo] != '(') {
                posfixa[j++] = pilha[topo--];
                posfixa[j++] = ' '; // Adiciona espa�o ap�s o operador
            }
            if (topo == -1) {
                printf("Express�o inv�lida!\n");
                exit(1);
            }
            topo--;
        }
        else {
            while (topo != -1 && precedencia(ch) <= precedencia(pilha[topo])) {
                posfixa[j++] = pilha[topo--];
                posfixa[j++] = ' '; // Adiciona espa�o ap�s o operador
            }
            push(ch);
        }
    }
    while (topo != -1) {
        if (pilha[topo] == '(') {
            printf("Express�o inv�lida!\n");
            exit(1);
        }
        posfixa[j++] = pilha[topo--];
        posfixa[j++] = ' '; // Adiciona espa�o ap�s o operador
    }
    posfixa[j - 1] = '\0'; // Remove espa�o em branco no final da string
    return posfixa;
}

double avaliar_posfixa(char* expressao) {
    int i;
    char ch;
    double val1, val2;
    for (i = 0; expressao[i]; i++) {
        ch = expressao[i];
        if (isdigit(ch))
            push(ch - '0');
        else if (eh_operador(ch)) {
            if (topo < 1) {
                printf("Erro: Pilha vazia ao avaliar a express�o\n");
                exit(EXIT_FAILURE);
            }
            val2 = pop();
            val1 = pop();
           
    if (ch == '+'){
        push(val1 + val2);
    }else if (ch == '-'){
        push(val1 - val2);
    }else if (ch == '*'){
        push(val1 * val2);
    }else if (ch == '/') {
        if (val2 == 0) {
printf("Erro: Divis�o por zero\n");
exit(EXIT_FAILURE);
        }
        push(val1 / val2);
        }
    }
}
    if (topo == 0){
        return pilha[topo];
        printf("Erro: Express�o inv�lida\n");
        exit(EXIT_FAILURE);
        }
}
