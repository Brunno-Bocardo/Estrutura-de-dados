#include <stdio.h>

int ehPar(int n) {
	int par;
//	return (n % 2 == 0) ?  1 :  0;
//	return n % 2 == 0;
	return !(n%2);	
}

int main() {
    int val;
    
    printf("Fala tu: ");
    scanf("%d", &val);
    
    if(ehPar(val))
    	printf("%d eh par", val);
    else
    	printf("%d nao eh par(cero)", val);
    
    return 0;
}
