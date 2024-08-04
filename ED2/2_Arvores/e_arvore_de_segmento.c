#include <stdio.h>

#define MAX_TAMANHO 1000

// Árvore de segmentos global
int arvoreSegmentos[MAX_TAMANHO];

// Função para construir a árvore de segmentos
void construirArvoreSegmentos(int vetor[], int no, int inicio, int fim) 
{
    if (inicio == fim) { // restou apenas um elemento 
        arvoreSegmentos[no] = vetor[inicio];
        return;
    }
    
    int meio = (inicio + fim) / 2;
    
    construirArvoreSegmentos(vetor, 2 * no, inicio, meio);
    construirArvoreSegmentos(vetor, 2 * no + 1, meio + 1, fim);
    
    arvoreSegmentos[no] = arvoreSegmentos[2 * no] + arvoreSegmentos[2 * no + 1];
}

// Função para consultar a árvore de segmentos
int consultarArvore(int no, int inicio, int fim, int intervaloInicio, int intervaloFim) {
    // Se o intervalo consultado está fora do intervalo do nó
    if (intervaloFim < inicio || fim < intervaloInicio) {
        return 0;
    }
    // Se o intervalo do nó está completamente dentro do intervalo consultado
    if (intervaloInicio <= inicio && fim <= intervaloFim) {
        return arvoreSegmentos[no];
    }
    int meio = (inicio + fim) / 2;
    // Consultar os dois filhos do nó
    return consultarArvore(2 * no, inicio, meio, intervaloInicio, intervaloFim)
           + consultarArvore(2 * no + 1, meio + 1, fim, intervaloInicio, intervaloFim);
}

// Função para atualizar a árvore de segmentos
void atualizarArvore(int no, int inicio, int fim, int indice, int valor) {
    // Se o nó é uma folha
    if (inicio == fim) {
        arvoreSegmentos[no] = valor;
        return;
    }
    int meio = (inicio + fim) / 2;
    // Atualizar o filho adequado
    if (indice <= meio) {
        atualizarArvore(2 * no, inicio, meio, indice, valor);
    } else {
        atualizarArvore(2 * no + 1, meio + 1, fim, indice, valor);
    }
    // Atualizar o valor do nó atual
    arvoreSegmentos[no] = arvoreSegmentos[2 * no] + arvoreSegmentos[2 * no + 1];
}


// Código principal
int main() {
    int vetor[] = { 1, 3, 5, 7, 9, 11 };
    int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);
    
    // Construir a árvore de segmentos
    construirArvoreSegmentos(vetor, 1, 0, tamanhoVetor - 1);
    
    // Consultar a soma dos elementos no intervalo [1, 3]
    printf("Soma dos elementos no intervalo [1, 3] é %d\n", consultarArvore(1, 0, tamanhoVetor - 1, 1, 3));
    
    // Atualizar o valor no índice 2 para 10
    atualizarArvore(1, 0, tamanhoVetor - 1, 2, 10);
    
    // Consultar a soma dos elementos no intervalo [1, 3] após a atualização
    printf("Soma dos elementos no intervalo [1, 3] após a atualização é %d\n", consultarArvore(1, 0, tamanhoVetor - 1, 1, 3));
    
    return 0;
}
