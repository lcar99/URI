#include <stdio.h>

int main(){

	int i, j, k, a, n, cont;
	scanf ("%d", &k);
	for (j = 0; j < k; ++j){
		cont = 0;
		scanf ("%d %d", &a, &n);
		if (a % 2 != 0){
			cont = cont + a;
			--n;
		}
		for (i = 0; i < n; ++i){
			if (a % 2 == 0){
				--a;
			}
			a = a + 2;
			cont = cont + a;
		}
		printf ("%d\n", cont);
	}
	return 0;
}