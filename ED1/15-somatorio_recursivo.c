#include <stdio.h>

int somatorio(int val) {
    if (val == 1) {
        return 1;
    } else {
        return val + somatorio(val - 1);
    }
}

int main() {
    int val, resultado;

    printf("Digite um valor: ");
    scanf("%d", &val);

    resultado = somatorio(val);
    printf("A soma de 1 ate %d e igual a %d\n", val, resultado);

    return 0;
}