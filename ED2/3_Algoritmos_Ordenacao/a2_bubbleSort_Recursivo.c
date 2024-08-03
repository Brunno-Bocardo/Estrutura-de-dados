#include <stdio.h>

void passagem(int n, int *v, int tamanhoVetor)
{
    printf("Passagem %i: ", n);
    for(int i=0; i<tamanhoVetor; i++)
        printf(" %i ", v[i]);
    printf("\n");
}


void Rec_bubbleSort(int *v, int tamanhoVetor) 
{
    int troca = 0;
    int aux;
    
    for (int j=0; j<tamanhoVetor - 1; j++) 
        if (v[j] > v[j + 1]) { 
            aux = v[j];
            v[j] = v[j + 1];
            v[j + 1] = aux;
            troca = 1;
        }

    passagem(tamanhoVetor, v, tamanhoVetor); // TODO: corrigir o print
    if (troca == 0)
        return; 
    else
        Rec_bubbleSort(v, tamanhoVetor - 1);
}


int main() 
{
    int v[] = {25, 57, 48, 37, 12, 92, 86, 33, 100};
    int tamanhoVetor = (sizeof(v) / sizeof(int));
    passagem(0, v, tamanhoVetor);
    Rec_bubbleSort(v, tamanhoVetor - 1);
    
    for(int i=0; i<tamanhoVetor; i++)
        printf(" %i ", v[i]);

    return 0;
}