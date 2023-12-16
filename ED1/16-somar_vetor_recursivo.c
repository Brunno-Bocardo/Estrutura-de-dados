#include <stdio.h>

int somarVetor(int lista[], int quantidade) {
    int indice;
    indice = quantidade;
    
    if (indice == 0) {
        return lista[0];
    } else {
        return lista[indice] + somarVetor(lista, quantidade - 1);
    }
}

int main() {
    int resultado;
    int lista[5];
    int quantidade = 5;

    for (int i = 0; i < quantidade; i++) {
        printf("Digite o valor %d de %d: ", i + 1, quantidade);
        scanf("%d", &lista[i]);
    }

    resultado = somarVetor(lista, quantidade);
    printf("A soma do vetor e: %d", resultado);

    return 0;
}