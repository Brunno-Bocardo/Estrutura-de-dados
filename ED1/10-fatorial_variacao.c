#include <stdio.h>
#include <stdlib.h>

int fatorial(int valor) {
    int i;
	int resultado=1;   // 0! = 1
    
    for(i=valor; i>0; i--) {
    	resultado *= i;
	}
	return resultado;
}

float serie(int n) {
	int i;
	float soma = 1;
	for(i=1; i<=n; i++) {
		soma += 1.0/fatorial(i);
	}
	return soma;
}

int main() {
    int valor; 
    printf("Informe o valor: ");
    scanf("%d", &valor);
    printf("\nResultado = %.5f", serie(valor));
    
    return 0;
}