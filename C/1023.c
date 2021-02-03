#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int qtd, cons, conm;
}queijo;

int compara_nada (const void *a, const void *b){
	const queijo *x = a; const queijo *y = b;
	if (x->conm != y->conm){
		return x->conm - y->conm;
	}else{
		return y->qtd - x->qtd;
	}
}

int main(){

	int i, n, a, qtdt, ttcons, cont = 0;
	double constm;
	queijo v[100000];
	char banana[30];
	while (scanf ("%d", &n), n != 0){
		++cont;
		if (cont > 1){
			printf ("\n");
		}
		qtdt = 0;
		ttcons = 0;
		constm = 0;
		printf("Cidade# %d:\n", cont);
		for (i = 0; i < n; ++i){
			scanf ("%d %d", &v[i].qtd, &v[i].cons);
			v[i].conm = v[i].cons/v[i].qtd;
		}
		qsort (v, n, sizeof(queijo), compara_nada);
		for (i = 0; i < n; ++i){
			qtdt = qtdt + v[i].qtd;
			ttcons = ttcons + v[i].cons;
			printf ("%d-%d", v[i].qtd, v[i].conm);
			if (i < n - 1){
				printf (" ");
			}
		}
		printf ("\n");
		constm = (double)(ttcons)/(double)(qtdt);
		printf("Consumo medio: ");
		sprintf (banana, "%lf", constm);
		a = strlen (banana);
		for (i = 0; i < a; ++i){
			if (banana[i] == '.'){
				printf ("%c", banana[i]);
				printf ("%c", banana[i + 1]);
				printf ("%c", banana[i + 2]);
				break;
			}else{
				printf ("%c", banana[i]);
			}
		}
		printf(" m3.\n");
	}
	return 0;
}