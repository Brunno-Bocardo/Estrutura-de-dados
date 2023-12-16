#include <stdio.h>

int potencia(int val, int expo) {
    if (expo == 0) {
        return 1; // Qualquer número elevado a 0 é 1
    } else {
        return val * potencia(val, expo - 1); // Chamada recursiva
    }
}

int main() {
    int val, expo;

    printf("Digite um valor: ");
    scanf("%d", &val);

    printf("Elevado a: ");
    scanf("%d", &expo);

    int resultado = potencia(val, expo);
    printf("%d elevado a %d é igual a %d\n", val, expo, resultado);

    return 0;
}