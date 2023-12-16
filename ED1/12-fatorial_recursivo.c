#include <stdio.h>
#include <stdlib.h>

int recFatorial (int n) {
	int resp;
	if (n == 1) {
		return 1;
	} else {
		resp = recFatorial(n-1)*n;
		return resp;
	}
}

int main() {
	int n;
	printf("diga: ");
	scanf("%d", &n);
	printf("%d", recFatorial(n));
	return 0;
}