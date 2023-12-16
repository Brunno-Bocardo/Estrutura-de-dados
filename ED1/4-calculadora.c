#include <stdio.h>

void calcular(float num1, float num2, char operador) {
    float resultado;

    switch (operador) {
        case '+':
            printf("Resultado: %.2f\n", num1 + num2);
            break;
        case '-':
            printf("Resultado: %.2f\n", num1 - num2);
            break;
        case '*':
            printf("Resultado: %.2f\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Resultado: %.2f\n", num1 / num2);
            } else {
                printf("Nao e possivel realizar a divisao por zero.\n");
                return 0.0; 
            }
            break;
        default:
            printf("Operador invalido.\n");
            return 0; 
    }
    
}

int main() {
    float num1, num2, resultado;
    char operador;

    printf("Digite um numero: ");
    scanf("%f", &num1);

    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &operador); 
    
    printf("Digite outro numero: ");
    scanf("%f", &num2);

    calcular(num1, num2, operador);
    return 0;
}
