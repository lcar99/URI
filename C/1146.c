#include <stdio.h>

int main(){


	int i, n;
	while (scanf ("%d", &n), n != 0){
		for (i = 1; i <= n; ++i){
			printf("%d", i);
			if (i < n){
				printf (" ");
			}
		}
		printf ("\n");
	}
	return 0;
}