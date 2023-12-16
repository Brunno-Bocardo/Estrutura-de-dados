#include <stdio.h>

int exibirCrescente(int val, int aux) {
    if (aux == val) {
        return printf("%d", val);
    } else {
        printf("%d, ", aux);
        return exibirCrescente(val, aux + 1);
    }
}

int main() {
    int val;
    int aux = 0;
    
    printf("Digite um numero inteiro positivo qualquer: \n");
    scanf("%d", &val);

    exibirCrescente(val, aux);

    return 0;
}