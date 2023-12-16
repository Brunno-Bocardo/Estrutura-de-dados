#include <stdio.h>

int encontrarMaior(int vetor[], int tamanho) {
    // Caso base: Se o tamanho do vetor for 1, o maior valor é o próprio elemento
    if (tamanho == 1) {
        return vetor[0];
    } else {
        // aqui ele chama a recursividade.
        //o que ele faz é analisar dentro do vetor a partir da próxima posição
        //ele faz isso até o vetor só ter a posição 0
        int maiorNoSubvetor = encontrarMaior(vetor + 1, tamanho - 1);
        
        // quando ele for retornando, ele compara o valor com a nova posição 0 que apareceu
        if (vetor[0] > maiorNoSubvetor) {
            return vetor[0];
        } else {
            return maiorNoSubvetor;
        }
    }
}

int main() {
    int vetor[] = {100, 5, 72, 2, 8};
    int tamanho = 5;  // Tamanho do vetor
    int maior = encontrarMaior(vetor, tamanho);
    printf("O maior valor no vetor é: %d\n", maior);
    return 0;
}
