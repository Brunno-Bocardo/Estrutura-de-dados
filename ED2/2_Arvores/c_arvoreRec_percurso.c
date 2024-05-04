#include <stdio.h>
#include <stdlib.h>


typedef struct stNo{
	int info;
	struct stNo *esquerda;
	struct stNo *direita;
}tNo;


tNo* criarNo(int info){
	tNo* novoNo = (tNo*)malloc(sizeof(tNo));
	if (!novoNo) {
		printf("Sem memória\n"); exit(0);
	}
	novoNo->esquerda = NULL;
	novoNo->direita = NULL;
	novoNo->info = info;
	return novoNo;
}


tNo* subArvore(tNo *noPai, int info) {
    if (!noPai)
        return criarNo(info); 

    if (info < noPai->info)
        noPai->esquerda = subArvore(noPai->esquerda, info); 
    else if (info > noPai->info)
        noPai->direita = subArvore(noPai->direita, info); 

    return noPai; 
}


void preOrdem(tNo *no) {
    if(no) {
        printf("%d, ", no->info);
        preOrdem(no->esquerda);
        preOrdem(no->direita);
    }
}

void inOrdem(tNo *no) {
    if(no) {
        inOrdem(no->esquerda);
        printf("%d, ", no->info);
        inOrdem(no->direita);
    }
}

void posOrdem(tNo *no) {
    if(no) {
        posOrdem(no->esquerda);
        posOrdem(no->direita);
        printf("%d, ", no->info);
    }
}


int main(int argc, char *argv[]) {
	int num;
	tNo *raiz = NULL;
	do{
		printf("Insira um numero ou 0 para sair: ");
		scanf("%i", &num);
		if(num != 0){
			if(!raiz)
				raiz = subArvore(raiz,num);
			else
				subArvore(raiz,num);
		}
	}while(num != 0);
	
	printf("\nPre-ordem: ");
	preOrdem(raiz);
	
	printf("\nIn-ordem: ");
	inOrdem(raiz);
	
	printf("\nPós-ordem: ");
	posOrdem(raiz);
	
	return 0;
}