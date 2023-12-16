#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // lib boladona   :D

#define MAX 10
// DEFINE A LISTA COM MAX DE 10

int main() {
	int vet[MAX];
	int i, pos;
	float media;
	
	for(i=0; i<MAX; i++) {
		printf("Informe o %d o valor: ", i+1);
		scanf("%d", &vet[i]);
		media += (float)vet[i]/MAX;  // converte o valor de vet, outrora inteiro, para float 
	}
	
	printf("\nMedia: %.2f", media);
	pos = 0;
	
	for(i=1; i<MAX; i++) {
		if(fabs(vet[i] - media) < fabs(vet[pos] - media)) {   // fabs deixa as coisas em módulo. PARA USAR PRECISA DA LIB
			pos = i;
		}
	}
		
	
	printf("\n O valor mais proximo da media %.2f eh: %d", media, vet[pos]);

	
	return 0;
}