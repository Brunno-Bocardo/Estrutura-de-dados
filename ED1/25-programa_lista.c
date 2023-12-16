#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
	struct aluno* prox;
    int ra;
    char nome[50];
    char curso[50];
    float notas[4];
    int anoInicio;
    int idade;
};

typedef struct aluno Aluno;

// Inicializando a Lista
Aluno* inicializa (void) {
    return NULL;
}

// Pergunta o RA 
int saberRA() {
    int ra;
    printf("Didite o RA do aluno: ");
    scanf("%d", &ra);
    return ra;
}

// Usado quando for pra exibir um aluno
void printarInfos(Aluno* l) {
    printf("\n\n\tRA: %d", l->ra);
    printf("\n\tNome: %s", l->nome);
    printf("\tIdade: %d", l->idade);
    printf("\n\tCurso: %s", l->curso);
    for (int i=1; i<=4; i++)
        printf("\n\tNota %d: %f", i, l->notas[i]);
}

// Inserindo aluno na lista
Aluno* novoAluno (Aluno* l) {
	Aluno* novo;
	novo = (Aluno*) malloc(sizeof(Aluno));
	
	system("clear");
	printf("\n\nCerto, vamos cadastrar um novo aluno!");
        
    printf("\n\n\tRA: ");
    scanf("%d", &novo->ra);
    printf("\tNome: ");
	getchar();
    fgets(novo->nome, sizeof(novo->nome), stdin);
    printf("\tIdade: ");
    scanf("%d", &novo->idade);
    printf("\tCurso: ");
	getchar();
    fgets(novo->curso, sizeof(novo->curso), stdin);
    printf("\tAno de inicio: ");
    scanf("%d", &novo->anoInicio);
    for (int i = 1; i<=4; i++) {
    	printf("\tNota %d: ", i);
    	scanf("%f", &novo->notas[i]);
	}
    printf("\n\nAluno cadastrado com sucesso!");
    
    if (l == NULL || strcmp(novo->nome, l->nome) < 0) {
        // Insere no início ou antes do primeiro aluno
        novo->prox = l;
        return novo;
    }

    Aluno* atual = l;
    Aluno* anterior = NULL;

    while (atual != NULL && strcmp(novo->nome, atual->nome) > 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Insere entre dois alunos ou no final da lista
    novo->prox = atual;
    anterior->prox = novo;

    return l;
}


// Exibindo alunos - recursivo
void listarAlunos(Aluno* l) {
    if (l != NULL) {
        printarInfos(l);
        
        listarAlunos(l->prox);
    } 
}


// Buscar aluno - recursivo
void buscarAluno(Aluno* l, int ra) {
    if(l != NULL) {
        if(l->ra == ra)
            printarInfos(l);
        else
            return buscarAluno(l->prox, ra);
    }
    return;
}


// Maior media
void maiorMedia(Aluno* l) {
    float maior = 0;
    char nomeAluno[50];
    
    while (l != NULL) {
        float media = 0;

        for (int i=0; i<=4; i++)
            media += l->notas[i];
        
        media /= 4; 
        
        if (media > maior) {
            maior = media;
            strcpy(nomeAluno, l->nome);
        }

        l = l->prox;
    } 
    
    printf("\nO aluno com a maior media e: %s", nomeAluno);
    printf("\nSua media e: %.2f", maior);   
}


// Media das medias
void mediaTotal(Aluno* l) {
    float mediaDasMedias = 0;
    int contador = 0;

    while (l != NULL) {
        float media = 0;

        for (int i=0; i<=4; i++)
            media += l->notas[i];
        
        media /= 4; 
        mediaDasMedias += media;
        contador++;
        l = l->prox;
    }
    
    printf("\nA media da turma e: %.2f", mediaDasMedias/contador);
}


// Excluir aluno pelo RA
Aluno* excluirAluno(Aluno* l, int ra) {
    if (l==NULL)   
        return NULL;
    
    else if (l->ra == ra) {
        Aluno* aux = l->prox;
        free(l);
        printf("\nAluno removido\n");
        return aux;
    }
    
    else {
        l->prox = excluirAluno(l->prox, ra);
        return l;
    }
}


// Liberar memoria - recursivo
void sair(Aluno* l) {
    if (l == NULL)
        return;
    
    Aluno* proxima = l->prox;
    free(l);
    sair(proxima);
}


int main() {
    int op, ra;
    char continua;
    Aluno* l;
    
    l = inicializa(); // inicializa a lista  :D
    
    do {
		system("clear");
		
		printf("\n\nSelecione uma operacao: ");
		printf("\n\t[1] Cadastrar novo aluno");
		printf("\n\t[2] Listar todos os alunos");
		printf("\n\t[3] Buscar aluno pelo RA");
		printf("\n\t[4] Exibir o aluno com a maior media");
		printf("\n\t[5] Exibir a media das medias");
		printf("\n\t[6] Excluir um aluno pelo RA");
		printf("\n\t[7] Sair (liberando a memoria  c; )");
		printf("\n\nOpcao: ");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				l = novoAluno(l);
				break;
			case 2:
			    listarAlunos(l);
				break;
			case 3:
			    ra = saberRA();
			    buscarAluno(l, ra);
				break;
			case 4:
			    maiorMedia(l);
				break;
			case 5:
			    mediaTotal(l);
				break;
			case 6:
			    ra = saberRA();
			    l  = excluirAluno(l, ra);
				break;
			case 7:
			    sair(l);
			    continua = 'n';
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