#include <stdio.h>
#include <string.h>

int main(){

	int i, j, n, k, a;
	scanf ("%d", &n);
	for (i = 0; i < n; ++i){
		scanf ("%d %d", &a, &k);
		j = a;
		for (j; j < k + 1; ++j){
			printf ("%d", j);
		}
		j = a;
		for (k; k > j - 1; --k){
			printf ("%d", k);
		}
		printf ("\n");
	}
}