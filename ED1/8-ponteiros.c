int fatoracao(int *valor) {
    int i, resultado=1;
    
    for(i=valor;i>=1;i--) {
    	resultado *= i;
	}
}

int main() {
    int valor;
    printf("Digite um numero que nao sera um ponteiro: ");
    scanf("%d", &valor);
    fatoracao(&valor);
    printf("%d ", valor);
    return 0;
}