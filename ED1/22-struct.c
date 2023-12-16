#include <stdio.h>
#include <stdlib.h>
#define MAX 40

typedef struct {
    int ra;
    char nome[50];
    char curso[50];
    float notas[4];
    int anoInicio;
    int idade;
} Aluno;


void novoAluno(int contador, Aluno alunos[MAX]) {
    system("clear");
    if(contador >= MAX) {
        printf("\n\nLista de alunos cheia :(");
    } else {
        printf("\n\nCerto, vamos cadastrar um novo aluno!");
        
        printf("\n\tRA: ");
        scanf("%d", &alunos[contador].ra);
        printf("\tNome: ");
        getchar();
        fgets(alunos[contador].nome, sizeof(alunos[contador].nome), stdin);
        printf("\tCurso: ");
        fgets(alunos[contador].curso, sizeof(alunos[contador].curso), stdin);
        printf("\tNotas (4): ");
        scanf("%f %f %f %f", &alunos[contador].notas[0], &alunos[contador].notas[1], &alunos[contador].notas[2], &alunos[contador].notas[3]);
        printf("\tAno de inicio: ");
        scanf("%d", &alunos[contador].anoInicio);
        printf("\tIdade: ");
        scanf("%d", &alunos[contador].idade);
        
        printf("\n\nAluno cadastrado com sucesso!");
    }
}

void listarAlunos(int contador, Aluno alunos[MAX]) {
    if (contador > 0) {
        system("clear");
        printf("\n\nListagem de todos os alunos cadastrados:\n");
    
        for (int i = 0; i < contador; i++) {
            printf("\nAluno %d:\n", i + 1);
            printf("\tRA: %d\n", alunos[i].ra);
            printf("\tNome: %s", alunos[i].nome);
            printf("\tCurso: %s", alunos[i].curso);
            printf("\tNotas: %.2f %.2f %.2f %.2f\n", alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].notas[3]);
            printf("\tAno de inicio: %d\n", alunos[i].anoInicio);
            printf("\tIdade: %d\n", alunos[i].idade);
        }
    } else {
        system("clear");
        printf("\nO sistema ainda não possui alunos cadastrados");
    }
}

void buscarAluno(int contador, Aluno alunos[MAX]) {
    if (contador > 0) {
        int busca;
        system("clear");
        printf("\n\nQual é o RA: ");
        scanf("%d", &busca);
    
        for (int i = 0; i < contador; i++) {
            if(busca == alunos[i].ra) {
                printf("\nAluno %d:\n", i + 1);
                printf("\tRA: %d\n", alunos[i].ra);
                printf("\tNome: %s", alunos[i].nome);
                printf("\tCurso: %s", alunos[i].curso);
                printf("\tNotas: %.2f %.2f %.2f %.2f\n", alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].notas[3]);
                printf("\tAno de inicio: %d\n", alunos[i].anoInicio);
                printf("\tIdade: %d\n", alunos[i].idade);
            }      
        }
    } else {
        system("clear");
        printf("\nO sistema ainda não possui alunos cadastrados");
    }
}

void maiorMedia(int contador, Aluno alunos[MAX]) {
    if (contador > 0) {
        int maior = 0;
        int aluno;
        for (int i = 0; i < contador; i++) {
            int media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3]);
            if(media > maior) {
                maior = media;
                aluno = i;
            }
        }
        system("clear");
        printf("\nO aluno com maior media é o %sSua media e: %d", alunos[aluno].nome, (maior)/4);
    } else {
        system("clear");
        printf("\nO sistema ainda não possui alunos cadastrados");
    }
}

void mediaTotal(int contador, Aluno alunos[MAX]) {
    if (contador > 0) {
        float soma = 0;
        float media = 0;
        for (int i = 0; i < contador; i++) {
            soma = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3])/4;
            media += soma;
        }
        system("clear");
        printf("\nA media dos alunos (%d alunos) e: %f", contador, media/contador);
        
    } else {
        system("clear");
        printf("\nO sistema ainda não possui alunos cadastrados");
    }
}

void excluirAluno(int contador, Aluno alunos[MAX]) {
    if (contador > 0) {
        int encontrado = 0; 
        int op;
        system("clear");
        printf("\nDigite o RA do aluno que deseja excluir: ");
        scanf("%d", &op);
    
        for (int i = 0; i < contador; i++) {
            if (alunos[i].ra == op) {
                encontrado = 1;
                
                for (int j = i; j < contador - 1; j++) {
                    alunos[j] = alunos[j + 1];
                }
                
                printf("Aluno com RA %d foi excluído com sucesso.\n", op);
                break;
            }
        }
        if (!encontrado) 
            printf("Aluno com RA %d não encontrado.\n", op);
    } else {
        system("clear");
        printf("\nO sistema ainda não possui alunos cadastrados");
    }
}


int main() {
    int op;
    char continua;
    Aluno alunos[MAX];
    int contadorCadastro = 0;
    do {
		system("clear");
		
		printf("\n\nSelecione uma operação: ");
		printf("\n\t[1] Cadastrar novo aluno");
		printf("\n\t[2] Listar todos os alunos");
		printf("\n\t[3] Buscar aluno pelo RA");
		printf("\n\t[4] Exibir o aluno com a maior média");
		printf("\n\t[5] Exibir a média das médias");
		printf("\n\t[6] Excluir um aluno pelo RA");
		printf("\n\t[7] Sair ");
		printf("\n\nOpção: ");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				novoAluno(contadorCadastro, alunos);
				contadorCadastro++;
				break;
			case 2:
			    listarAlunos(contadorCadastro, alunos);
				break;
			case 3:
			    buscarAluno(contadorCadastro, alunos);
				break;
			case 4:
			    maiorMedia(contadorCadastro, alunos);
				break;
			case 5:
			    mediaTotal(contadorCadastro, alunos);
				break;
			case 6:
			    excluirAluno(contadorCadastro, alunos);
			    contadorCadastro--;
				break;
			case 7:
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
