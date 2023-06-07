#include <stdio.h>
#include "listEnc.h"

int main() {
    Lista fila;
    criar(&fila);

    inserir(&fila, "Joao", 2);
    inserir(&fila, "Joseph", 3);
    inserir(&fila, "Carlos", 1);

    mostrar(fila);

    remover(&fila);

    mostrar(fila);

    pesquisar(fila, "Carlos");

    return 0;
}
