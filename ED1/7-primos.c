#include <stdio.h>

int primo(int n) {
	int i=2;
	while(i <= n/2) {
		if(n % i++ == 0)       // colocar o 'i++' no if significa que ele vai fazer a condição
			return 0;          // com o valor de i original, e só depois vai incrementar
	}	                       // poderia fazer ++i, para incrementar antes de executar
	return 1;
}

int main() {
    int val;
    
    printf("Fala tu: ");
    scanf("%d", &val);
    
    if(primo(val))
    	printf("%d eh primo", val);
    else
    	printf("%d nao eh primo", val);
    
    return 0;
}
