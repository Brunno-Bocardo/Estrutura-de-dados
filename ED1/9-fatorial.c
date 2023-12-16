int fatorial(int *valor) {
    int i;
	int resultado=1;   // 0! = 1
    
    for(i=valor; i>0; i--) {
    	resultado *= i;
	}
	return resultado;
}

int main() {
    int valor;
    
    printf("Informe o valor: ");
    scanf("%d", &valor);
    
    printf("%d! = %d", valor, fatorial(valor));
    
    return 0;
}