#include <stdio.h>

// O segredo dessa função está em realizar a busca de trás pra frente
// Ao chamar novamente a função, ela será passada com um tamanhoDoVetor menor
// Fazendo com que o elemento de foco seja o anterior

int buscaSequencialRecursiva(int lista[], int tamanhoDoVetor, int valorDeBusca) {
        
    if (tamanhoDoVetor == 0)
        //não tem + o que buscar
        return -1;  
    
    else if (lista[tamanhoDoVetor-1] == valorDeBusca)
        // encontrou o valor
        return tamanhoDoVetor - 1;
        
    else
        // ainda tem o que buscar -> chama novamente
        return buscaSequencialRecursiva(lista, tamanhoDoVetor - 1, valorDeBusca);
}


int main(int argc, char *argv[]) {
	
	int lista[] = {0,1,2,3,4,5,6,7,8,9};
	int valorDeBusca;
	int posicao;
	
	printf("Informe um valor: ");
	scanf("%d", &valorDeBusca);
	
	posicao = buscaSequencialRecursiva(lista, 10, valorDeBusca);
	
	if(posicao < 0)
	    printf("Valor não encontrado");
	else
	    printf("Valor existe na posição: %d", posicao);
	
	
	return 0;
}
