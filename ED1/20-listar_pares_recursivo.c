#include <stdio.h>

int verificarPar(int val) {
    return (val % 2 == 0) ? 1 : 0;
}

int listaPares(int lista[], int tamanho, int indice) {
    if (indice == tamanho) {
        if (verificarPar(lista[indice]) == 1) {
            printf("%d", lista[indice]);
        }
    } else {
        if (verificarPar(lista[indice]) == 1) {
            printf("%d, ", lista[indice]);
            listaPares(lista, tamanho, indice + 1);
        } else {
            listaPares(lista, tamanho, indice + 1);
        }
    }
}

int main() {
    int indice = 0;
    int tamanho = 5;
    int lista[6] = {1, 2, 3, 4, 5, 6};
    
    listaPares(lista, tamanho, indice);

    return 0;
}