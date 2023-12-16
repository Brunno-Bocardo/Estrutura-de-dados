#include <stdio.h>
#include <stdlib.h>

float potencia(float, int);  //isso e um prototipo, a funcao so pode ficar abaixo do main se existir isso aqui

int lerInteiro(char *frase) {
	int val;
	printf("%s", frase);
	scanf("%d", &val);
	return val;
}

int parImpar(int numero) {
	return numero%2==0 ? 1 : 0;
	// return numero%2==0;   isso e a mesma coisa
}

int main() {
	float base;
	int expoente;
	float resultado;
	base = lerInteiro("Informe a base: ");
	expoente = lerInteiro("Informe o expoente: ");
	resultado = potencia(base, expoente);
	printf("%.2f elevado a %d = %.2f", base, expoente, resultado);
	
	return 0;
}

float potencia(float base, int expoente) {
	int i;
	float res = 1;
	for(i=0; i<expoente;i++) 
		res *= base;
	return res;
}


