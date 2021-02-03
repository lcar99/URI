#include <stdio.h>

int main(){

	double i, cont = 0;

	for (i = 1; i < 101; ++i){
		cont = cont + 1/i;
	}
	printf ("%.2lf\n", cont);


	return 0;
}