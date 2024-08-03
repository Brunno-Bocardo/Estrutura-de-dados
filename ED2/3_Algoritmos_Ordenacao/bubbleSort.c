#include <stdio.h>

void passagem(int n, int *v, int tamanhoVetor)
{
    printf("Passagem %i: ", n);
    for(int i=0; i<tamanhoVetor; i++)
        printf(" %i ", v[i]);
    printf("\n");
}


void bubbleSort(int *v, int tamanhoVetor) 
{
    int troca = 0; //verifica se houve troca
    int aux, i, j;
    
    for(i=tamanhoVetor - 1; i>0; i--) { // aqui, é i>0 pois não faz sentido comparar o ultimo com o proximo
        troca = 0; //reset do valor
        for(j=0; j<i; j++) {
            if(v[j] > v[j + 1]) { //se a próxima posição é menor que a atual -> TROCA
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                troca = 1;
            }
        }
        passagem(tamanhoVetor-i, v, tamanhoVetor);
        if(troca==0) // Se não houve troca, já ta ordenado
            break;
    }
}


int main() 
{
    int v[] = {25, 57, 48, 37, 12, 92, 86, 33, 100};
    int tamanhoVetor = (sizeof(v) / sizeof(int));
    passagem(0, v, tamanhoVetor);
    bubbleSort(v, tamanhoVetor);

    return 0;
}