#include <stdio.h>

int buscaSeq(int lista[], int valorDeBusca, int valorSuperior) {
    int i;
    for(i=0; i<valorSuperior; i++)
        if(lista[i] == valorDeBusca)
            return i;
    return -1;
}


int main(int argc, char *argv[]) {
	
	int lista[] = {0,1,2,3,4,5,6,7,8,9};
	int valorDeBusca;
	int posicao;
	
	printf("Informe um valor: ");
	scanf("%d", &valorDeBusca);
	
	posicao = buscaSeq(lista, valorDeBusca, 10);
	
	if(posicao < 0)
	    printf("Valor não encontrado");
	else
	    printf("Valor existe na posição: %d", posicao);
	
	
	return 0;
}
