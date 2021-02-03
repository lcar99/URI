#include <stdio.h>

int main(){

	double n = 1, d = 1, x, cont = 0;
	while (n < 39){
		x = n/d;
		cont = cont + x;
		n = n + 2;
		d = d * 2;
	}
	printf ("%.2lf\n", cont);
	return 0;
}