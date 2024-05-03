#include <stdio.h>

int buscaBinaria(int lista[], int valorDeBusca, int tamanhoDoVetor) {
    int inferior = 0;
    int superior = tamanhoDoVetor - 1;
    int meio;
    
    while(inferior <= superior) {
        meio = (superior + inferior) / 2;
        if (valorDeBusca == lista[meio])
            // valor encontrado :D
            return meio;
            
        if (valorDeBusca < lista[meio])
            // o valor de busca é menor. Busca apenas na metade inferior
            superior = meio - 1;
            
        else
            // o valor de busca é maior. Busca apenas na metade superior
            inferior = meio + 1;
    }
    // valor não encontrado
    return -1;
}


int main(int argc, char *argv[]) {
	
	int lista[] = {0,1,2,3,4,5,6,7,8,9};
	int tamanhoDoVetor = 10;
	int valorDeBusca;
	int posicao;
	
	printf("Informe um valor: ");
	scanf("%d", &valorDeBusca);
	
	posicao = buscaBinaria(lista, valorDeBusca, tamanhoDoVetor);
	
	if(posicao < 0)
	    printf("Valor não encontrado");
	else
	    printf("Valor existe na posição: %d", posicao);
	
	
	return 0;
}
