#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

int pergunta() {
    int i;
    printf("Digite um valor: ");
    scanf("%d", &i);
    return i;
}

// Inicializando a Lista
Lista* inicializa (void) {
    return NULL;
}

// Imprimindo a Lista  -  FOR
void imprime_For (Lista* l) {
    Lista* p;
    for (p=l; p!=NULL; p= p->prox)
        printf("info = %d\n", p->info);
}

// Imprimindo a Lista  -  RECURSÃO
void imprime_Rec (Lista* l) {
    if (l != NULL) {
        printf("info = %d\n", l->info);  // imprime o nó da lista
        imprime_Rec(l->prox);  // chama a função para o proximo nó da lista
    }
}

// Busca - FOR 
Lista* busca_For (Lista* l, int v) {
    Lista* p;
    for (p=l; p!=NULL; p=p->prox)
        if (p->info == v)
            return p;
        return NULL; // NÃO ACHOU O ELEMENTO
}

// Busca Recursiva
Lista* busca_Rec(Lista* l, int v) {
    if(l != NULL) {
        if(l->info == v) {
            return l;
        }
        else
            return busca_Rec(l->prox, v);
    }
    return NULL;
}

// Inserindo em uma Lista
Lista* insere (Lista* l, int i) {
    
    Lista* novo;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

// Verificando se a Lista está vazia
int vazia (Lista* l) {
    if (l == NULL)
        return 1; // vazia
    else 
        return 0; // não vazia
}

Lista* sair(Lista* l) {
    if(l != NULL) {
        if(l->prox == NULL) {
            free(l);
            return NULL;
        }
        else
            return sair(l->prox);
    }
    return NULL;
}

Lista* apaga(Lista* l, int v) {
    Lista* ant = NULL;
    Lista* p = l;
    
    while(p != NULL && p->prox != v) {
        ant = p;
        p = p->prox;
    }
    
    if (p==NULL)
        return l; // n achou, retorna lista original
    if (ant==NULL) 
        l = p->prox; // retira o 1º ELEMENTO
    else
        ant->prox = p->prox;
    
    free(p);
    return l;
}


int main() {
    int op;
    char continua;
    Lista* l;
    int test, i;
    
    do {
		system("clear");
		
		printf("\n\nSelecione uma operação: ");
		printf("\n\t[1] Inserir novo numero");
		printf("\n\t[2] Remover um numero");
		printf("\n\t[3] Exibir lista");
		printf("\n\t[4] Buscar numero");
		printf("\n\t[5] Sair");
		printf("\n\nOpção: ");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
			    i = pergunta();
			    test = busca_Rec(l, i);
			    if(test != NULL) {
                    printf("Este valor ja foi inserido");
                    break;
			    } else 
			        l = insere(l, i);
				    break;
			//--------------------------------------------------------------------
			case 2:
			    i = pergunta();
			    test = busca_Rec(l, i);
			    if(test == NULL) {
                    printf("Este valor nao existe");
                    break;
			    } else {
			        l = apaga(l, i);
				    break;
			    }
			        
			//-------------------------------------------------------------------- 
			case 3:
			    if (vazia(l) == 1)
			        printf("Nao tem nada na lista :c");
			    else
			        imprime_For(l);
				break;
			//--------------------------------------------------------------------	
			case 4:
			    if (vazia(l) == 1) {
			        printf("Nao tem nada na lista :c");
				    break;
			    }
			    else {
			        i = pergunta();
			        test = busca_Rec(l, i);
			        if(test == NULL) {
			            printf("Nao esta na lista");
			        }
			        else {
			            printf("Esta na lista");			            
			        }
			        break;
			    }
			//--------------------------------------------------------------------
			case 5:
			    sair(l);
				break;
			default:
				printf("\nINVALIDO!");
		}
		if (op != 7) {
            printf("\n\nDesejas continuar? (S/N)");
            scanf(" %c", &continua);
        }
	} while ((continua == 's') || (continua == 'S'));

    return 0;
}
