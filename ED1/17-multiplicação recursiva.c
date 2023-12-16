#include <stdio.h>

int multiplicar(int num1, int num2) {
    if (num2 == 0) {
        return 0;
    } else {
        return num1 + multiplicar(num1, num2 - 1);
    }
}

int main() {
    int resultado, num1, num2;
    
    printf("Digite o primeiro e o segundo numero: \n");
    scanf("%d %d", &num1, &num2);

    resultado = multiplicar(num1, num2);
    printf("%d x %d = %d", num1, num2, resultado);

    return 0;
}