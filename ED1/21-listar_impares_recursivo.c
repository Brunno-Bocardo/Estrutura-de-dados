#include <stdio.h>

int verificarImpar(int val) {
    return (val % 2 == 0) ? 0 : 1;
}

int listaImpares(int lista[], int indice) {
    if (indice == 0) {
        if (verificarImpar(lista[indice]) == 1) {
            printf("%d", lista[indice]);
        }
    } else {
        if (verificarImpar(lista[indice]) == 1) {
            printf("%d, ", lista[indice]);
            listaImpares(lista, indice - 1);
        } else {
            listaImpares(lista, indice - 1);
        }
    }
}

int main() {
    int indice = 5;
    int lista[6] = {1, 2, 3, 4, 5, 6};
    listaImpares(lista, indice);
    return 0;
}