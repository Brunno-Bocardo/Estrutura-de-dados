#include <stdio.h>
#include <math.h>

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


// Função para deletar uma folha e ajustar a árvore
void deletarFolha(int no, int inicio, int fim, int indice, int valor) 
{
    if (inicio == fim) {  // Caso base: nó folha
        arvoreSegmentos[no] = 0;  // Remove a folha
        return;
    }

    int meio = (inicio + fim) / 2;
    
    if (indice <= meio) {  // Se o índice está no intervalo do filho esquerdo
        deletarFolha(2 * no, inicio, meio, indice, valor);
    } else {  // Se o índice está no intervalo do filho direito
        deletarFolha(2 * no + 1, meio + 1, fim, indice, valor);
    }

    // Subtrai o valor removido ao subir na árvore
    arvoreSegmentos[no] -= valor;

    // Se após a subtração, o nó se torna igual a um dos filhos e o outro filho é 0,
    // o nó atual é transformado na nova folha.
    if (arvoreSegmentos[2 * no] == 0 && arvoreSegmentos[2 * no + 1] != 0) {
        arvoreSegmentos[no] = arvoreSegmentos[2 * no + 1];
        arvoreSegmentos[2 * no + 1] = 0; // Zera o nó filho que foi promovido
    } else if (arvoreSegmentos[2 * no + 1] == 0 && arvoreSegmentos[2 * no] != 0) {
        arvoreSegmentos[no] = arvoreSegmentos[2 * no];
        arvoreSegmentos[2 * no] = 0; // Zera o nó filho que foi promovido
    }
}


void atualizarArvore(int no, int inicio, int fim, int indice, int valor) 
{
    // Se o nó é uma folha
    if (inicio == fim) {
        if (arvoreSegmentos[no] == 0) {
            printf("Valor no índice %d não existe mais.\n", indice);
            return;
        }
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


// Função para imprimir a árvore de segmentos em formato de árvore binária
void imprimirArvoreBinaria(int altura) 
{
    int espaco = (int)pow(2, altura) - 1; // Espaço máximo de largura
    int nivelAtual = 1;
    int indice = 1;
    
    // NOTA: pow(base, expoente)  |  é usado para calcular expoentes

    while (nivelAtual <= altura) {
        int nosPorNivel = (int)pow(2, nivelAtual - 1);
        int espacoEntreNos = espaco / nosPorNivel;

        // Espaçamento inicial para alinhar o primeiro nó
        for (int i = 0; i < espacoEntreNos / 2; i++) {
            printf("   ");
        }

        // Imprime todos os nós do nível atual
        for (int i = 0; i < nosPorNivel; i++) {
            if (indice < MAX_TAMANHO && arvoreSegmentos[indice] != 0) {
                printf("%3d", arvoreSegmentos[indice]);
            } else {
                printf("   ");
            }
            indice++;

            // Espaçamento entre os nós
            for (int j = 0; j < espacoEntreNos; j++) {
                printf("   ");
            }
        }

        printf("\n\n");
        nivelAtual++;
    }
}


// Código principal
int main() {
    int vetor[] = { 1, 3, 5, 7, 9, 11 };
    int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);
    
    // Construir a árvore de segmentos
    construirArvoreSegmentos(vetor, 1, 0, tamanhoVetor - 1);
    
    // Calcular a altura da árvore de segmentos
    int altura = (int)ceil(log2(tamanhoVetor)) + 1;
    
    // Imprimir a árvore de segmentos em formato de árvore binária
    imprimirArvoreBinaria(altura);
    
    // Deletar a folha de valor 2
    deletarFolha(1, 0, tamanhoVetor - 1, 1, 3);
    
    printf("\nApos remocao:\n\n");
    
    // Imprimir a árvore de segmentos em formato de árvore binária
    imprimirArvoreBinaria(altura);
    
    printf("\nApos update:\n\n");
    
    // Atualizar o valor no índice 2 para 10
    atualizarArvore(1, 0, tamanhoVetor - 1, 4, 4);
    
    // Imprimir a árvore de segmentos em formato de árvore binária
    imprimirArvoreBinaria(altura);
    
    return 0;
}
