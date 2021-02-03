#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compara_nada(const void *x, const void *y){
	char a = *( char*)x;
	char b = *( char*)y;
	return a - b;
}

int main(){

	int i, j, n, s;
	char s1[30], s2[30];
	scanf ("%d", &n);
	for (i = 0; i < n; ++i){
		int cont = 0;
		scanf ("%d", &s);
		scanf ("%s", s1);
		strcpy (s2, s1);
		qsort (s1, s, sizeof(char), compara_nada);
		for (j = 0; j < s; ++j){
			if (s1[j] != s2[j]){
				++cont;
			}
		}
		if (cont <= 2){
			printf ("There are the chance.\n");
		}else{
			printf ("There aren't the chance.\n");
		}
	}
}