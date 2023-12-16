#include <stdio.h>
#include <stdlib.h>

#define MAX 10
// DEFINE A LISTA COM MAX DE 10

int main() {
	int vet[MAX]; //  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i, menor, maior, val;
	for (i=0; i<MAX; i++) {
		printf("Informe o %d o valor: ", i+1);
		scanf("%d", &vet[i]);
		
		if (i==0) {
			maior = vet[i];
			menor = vet[i];
		} else {
			if (vet[i] > maior)
				maior = vet[i];
			if (vet[i] < menor)
				menor = vet[i];
		}
	}
	
	printf("\nMaior: %d", maior);
	printf("\nMenor: %d", menor);
	
	return 0;
}