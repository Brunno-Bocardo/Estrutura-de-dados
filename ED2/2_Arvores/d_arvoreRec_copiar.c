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


tNo *copiarArvore(tNo *no) {
    if(!no)
        return NULL;
    tNo *noCopia = criarNo(no->info);
    noCopia->esquerda = copiarArvore(no->esquerda);
    noCopia->direita = copiarArvore(no->direita);
    return noCopia;
}


void print_arvore(tNo *no, int espaco){
	int i;
	if(!no)
		return;
	print_arvore(no->direita, espaco +1);
	for(i=0; i < espaco; ++i)
		printf("  ");
	printf("%i\n", no->info);
	print_arvore(no->esquerda, espaco +1);
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
	
	tNo *raizCopia = copiarArvore(raiz);
	print_arvore(raizCopia, 0);
	
	return 0;
}