#include <stdio.h>

int buscaBinariaRecursiva(int lista[], int valorDeBusca, int inferior, int superior) {
    if (inferior <= superior) {
        // verifica se ainda existem itens de busca 
        return -1; 
    }
    
    int meio = (inferior + superior) / 2;
    
    if (valorDeBusca == lista[meio])
        return meio;
    
    if (valorDeBusca > lista[meio])
        return buscaBinariaRecursiva(lista, valorDeBusca, meio + 1, superior);

    if (valorDeBusca < lista[meio])
        return buscaBinariaRecursiva(lista, valorDeBusca, inferior, meio + 1);
        
    // É passado "meio + 1", pois é desnecessário passar o meio na próxima sequencia de busca 
    // já que ele teve sua ilustre participação nesse escopo
}


int main(int argc, char *argv[]) {
	
	int lista[] = {0,1,2,3,4,5,6,7,8,9};
	int superior = 10;
	int valorDeBusca;
	int posicao;
	
	printf("Informe um valor: ");
	scanf("%d", &valorDeBusca);
	
	posicao = buscaBinariaRecursiva(lista, valorDeBusca, 0, superior);
	
	if(posicao < 0)
	    printf("Valor não encontrado");
	else
	    printf("Valor existe na posição: %d", posicao);
	
	
	return 0;
}
