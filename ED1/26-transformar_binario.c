#include <stdio.h>

int dividirPorDois(int num) {
    if(num % 2 == 0)
        return 0;
    else 
        return 1;
}

int dec2Bin(int num) {
    int resultado;
    if (num <= 1) {
        printf("%d", dividirPorDois(num));
    } else {
        resultado = num/2;
        dec2Bin(resultado);
        printf("%d", dividirPorDois(num));
    }
}

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    dec2Bin(num);
    return 0;
}
