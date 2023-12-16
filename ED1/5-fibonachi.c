int imprimirSequencia(int n) {
    int i, atual=0, anterior=1, resultado;
    for (i=0; i<n; i++) {
        printf("%d ", atual);
        resultado = anterior + atual;
        anterior = atual;
        atual = resultado;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Digite um numero");
    scanf("%d", &n);
    imprimirSequencia(n);
    return 0;
}