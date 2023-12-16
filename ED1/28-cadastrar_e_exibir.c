#include <stdio.h>
#define MAX 10

typedef struct {
    char nome[50];
    int notaSemestre;
    int notaEspecial;
} Registro;

Registro cadastrar(Registro turma[MAX], int cadastros) {
    system("clear");
    printf("Nome: ");
    getchar();
    fgets(turma[cadastros].nome, sizeof(turma[cadastros].nome), stdin);
    printf("Nota do semestre: ");
    scanf("%d", &turma[cadastros].notaSemestre);
    printf("Nota especial: ");
    scanf("%d", &turma[cadastros].notaEspecial);
    getchar();
}

Registro exibir(Registro turma[MAX], int cadastros) {
    int i;
    system("clear");
    float media;
    for (i=0; i<cadastros; i++) {
        media = turma[i].notaSemestre + turma[i].notaEspecial;
        printf("\n\n%s", turma[i].nome);
        printf("%d", turma[i].notaSemestre);
        printf("\n%d", turma[i].notaEspecial);
        printf("\nMedia: %.2f", media/2);
        getchar();
    }
}

int main() {
    int op;
    Registro turma[MAX];
    int cadastros=0;
    do {
        printf("\nEscolha uma opcao: ");
        printf("\n\t1 - Registrar aluno");
	    printf("\n\t2 - Exibir dados");
	    printf("\n\t2 - Sair\n");
	    scanf("\n%d", &op);
	    
        switch(op) {
            case 1:
                cadastrar(turma, cadastros);
                cadastros++;
                break;
            case 2:
                exibir(turma, cadastros);
                break;
            case 3:
                break;
            default:
                printf("Invalido");
                break;
        }
    } while (op != 3);
    return 0;
}
