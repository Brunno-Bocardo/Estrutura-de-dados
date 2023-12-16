#include <stdio.h>

int exibirDecrescente(int val) {
    if (val == 0) {
        return printf("%d", val);
    } else {
        printf("%d, ", val);
        return exibirDecrescente(val - 1);
    }
}

int main() {
    int val;
    
    printf("Digite um numero inteiro positivo qualquer: \n");
    scanf("%d", &val);
    
    exibirDecrescente(val);

    return 0;
}