#include <stdio.h>

void exibir(int lista[], int tamanho, int indice) {
    if (indice >= tamanho) 
        return; // Condição de parada da recursão
    printf("%d ", lista[indice]);
    exibir(lista, tamanho, indice + 1); // Chamada recursiva para o próximo índice
    // se eu inverter o print e a função eu inverto a ordem de printar a lista
}

int main() {
    int lista[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    exibir(lista, 10, 0); // Inicia a recursão a partir do índice 0
    
    return 0;
}