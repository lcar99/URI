#include <stdio.h>
#include <string.h>

int main(){

	int i, n, a, j, cont;
	char led[1000];
	scanf ("%d", &n);
	for (i = 0; i < n; ++i){
		cont = 0;
		scanf ("%s", led);
		a = strlen (led);
		for (j = 0; j < a; ++j){
			if (led[j] == '1'){
				cont = cont + 2;
			}
			else if (led[j] == '2'|| led[j] == '3'|| led[j] == '5'){
				cont = cont + 5;
			}
			else if (led[j] == '4'){
				cont = cont + 4;
			}
			else if (led[j] == '6'|| led[j] == '9'|| led[j] == '0'){
				cont = cont + 6;
			}else if (led[j] == '7'){
				cont = cont + 3;
			}else{
				cont = cont + 7;
			}
		}
		printf ("%d leds\n", cont);
	}
	return 0;
}