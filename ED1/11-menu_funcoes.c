#include <stdio.h>
#include <stdlib.h>

int lerInteiroPositivo(char *texto) {
	int n;
	do {
		printf("\n%s", texto);
		scanf("%d", &n);
		if(n<0)
			printf("\nNumero invalido");
	} while(n<0);
	return n;
}

int menu() {
	printf("\n1 - primos ate n");
	printf("\n2 - area do quadrado");
	printf("\n3 - somatoria ate n");
	printf("\n4 - multiplo de 5");
	printf("\n5 - sair");
	int op = lerInteiroPositivo("Informe a opcao desejada: ");
}

int primo(int n) {
	int i = 2;
	while(i <= n/2)
		if(n % i++ == 0)
			return 0;
	return 1;
}

void ex1() {
	int m = lerInteiroPositivo("Informe m: ");
	int i;
	for (i=2; i<m; i++)
		if(primo(i))
			printf("\n%d e primo.", i);
}

void ex2() {
	int lado = lerInteiroPositivo("Informe o lado: ");
	printf("\nA area do quadrado e: %d", lado*lado);
}

int somatoriaAteN(int n) {
	int soma = 0;
	while(n > 0) {
		soma+=n--;
	}
	return soma;
}

void ex3() {
	int n = lerInteiroPositivo("informe N: ");
	printf("O samatorio de %d = %d", n, somatoriaAteN(n));
}

void ex4() {
	int n = lerInteiroPositivo("Informe N: ");
	int i;
	for(i=0; i<= n; i++)
		if(i % 5 == 0)
			printf("\n%d eh multiplo de 5", i);
		
}

int main() {
	int op;
	do {
		op = menu();
		switch(op) {
			case 1:
				ex1();
				break;
			case 2:
				ex2();
				break;
			case 3:
				ex3();
				break;
			case 4:
				ex4();
				break;
			case 5:
				printf("Ate logo!");
				break;
			default:
				printf("Opcao invalida!");
				break;
		}
	} while(op != 5);
	
	return 0;
}