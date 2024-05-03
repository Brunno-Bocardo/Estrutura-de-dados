#include <stdio.h>
#include <stdlib.h> 

typedef struct stNo {
    int info;
    struct stNo *esq;
    struct stNo *dir;
} tNo;

// Função para criar um nó
tNo* cria_no() {
    tNo *p = (tNo *) malloc(sizeof(tNo));
    if (!p)
        return NULL;
    p->esq = NULL;
    p->dir = NULL;
    return p;
}

// Função para criar uma árvore com um valor inicial
tNo* cria_arvore(int x) {
    tNo *p = cria_no();
    if (p) {
        p->info = x;
        return p;
    } else {
        printf("Não foi possível alocar o nó :(\n");
        exit(1);
    }
}

// Função para inserir à esquerda
void pos_esq(tNo *p, int x) {
    if (p->esq)
        printf("Já existe um valor na esquerda\n");
    else {
        p->esq = cria_arvore(x);
    }
}

// Função para inserir à direita
void pos_dir(tNo *p, int x) {
    if (p->dir)
        printf("Já existe um valor na direita\n");
    else {
        p->dir = cria_arvore(x);
    }
}

int main() {
    tNo *raiz = NULL, *p, *q;
    int num;

    do {
        printf("\nInsira um número (0 para sair): ");
        scanf("%d", &num);
        if (num == 0) break;

        if (!raiz)
            raiz = cria_arvore(num);
        else {
            q = raiz;
            p = raiz;

            while (num != p->info && q != NULL) {
                p = q;
                if (num < p->info)
                    q = p->esq;
                else
                    q = p->dir;
            }

            if (num == p->info)
                printf("O número %d já existe na árvore\n", num);
            else if (num < p->info)
                pos_esq(p, num);
            else
                pos_dir(p, num);
        }
    } while (1);

    return 0;
}
