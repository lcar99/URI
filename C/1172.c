#include <stdio.h>

int main(){

	int i, banana[15];
	for (i = 0; i < 10; ++i){
		scanf ("%d", &banana[i]);
		if (banana[i] <= 0){
			banana[i] = 1;
		}
	}
	for (i = 0; i < 10; ++i){
		printf ("X[%d] = %d\n", i, banana[i]);
	}
	return 0;
}