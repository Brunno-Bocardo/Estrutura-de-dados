#include <stdio.h>
#include <string.h>
#define MAX 6

typedef struct {
    char nomeChapa[50];
    char nomeResponsavel[50];
    int votos;
} Chapa;

void cadastrarChapa(Chapa chapa[], int numeroChapa) {
    if(numeroChapa == 2) {
        printf("Chapas lotadas");
    } else {
        printf("Nome da chapa: ");
        getchar();
        fgets(chapa[numeroChapa].nomeChapa, sizeof(chapa->nomeChapa), stdin);
        printf("Nome do Responsável: ");
        getchar();
        fgets(chapa[numeroChapa].nomeResponsavel, sizeof(chapa->nomeResponsavel), stdin);
    }
}

void votar(Chapa chapa[]) {
    int escolha, i;
    for(i=1; i<=MAX; i++) {
        system("clear\n");
        printf("voto numero %d: \n", i);
        printf("Escolha: \n");
        printf("1- chapa %s ", chapa[0].nomeChapa);
        printf("2- chapa %s ", chapa[1].nomeChapa);
        scanf("%d", &escolha);
        if(escolha==1)  
            chapa[0].votos++;
        else
            chapa[1].votos++;
    }
    system("clear\n");
    if(chapa[0].votos > chapa[1].votos) {
        printf("O vencedor e %s \n", chapa[0].nomeChapa);
        printf("Com: %d \n", chapa[0].votos);
        printf("Parabens: %s \n", chapa[0].nomeResponsavel);
    } else if(chapa[0].votos == chapa[1].votos) {
        printf("Chapas empatadas com %d votos\n", chapa[0].votos);
    } else {
        printf("O vencedor e %s \n", chapa[1].nomeChapa);
        printf("Com: %d \n", chapa[1].votos);
        printf("Parabens: %s \n", chapa[1].nomeResponsavel);
    }
}

int main() {
    Chapa chapa[2];
    int op;
    int numeroChapa = 0;

    do {
        printf("Escolha: \n");
        printf("1- Cadastrar chapa\n");
        printf("2- Votar\n");
        printf("0- Sair\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrarChapa(chapa, numeroChapa);
                numeroChapa++;
                break;
            case 2:
                votar(chapa);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (op != 0);

    return 0;
}
