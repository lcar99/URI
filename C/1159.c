#include <stdio.h>

int main(){

	int i, n, a, cont;
	while (scanf ("%d", &a), a != 0){
		n = 5;
		cont = 0;
		if (a % 2 == 0){
			cont = cont + a;
			--n;
		}
		for (i = 0; i < n; ++i){
			if (a % 2 != 0){
				--a;
			}
			a = a + 2;
			cont = cont + a;
		}
		printf ("%d\n", cont);
	}
	return 0;
}