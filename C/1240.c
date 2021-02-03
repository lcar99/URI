#include <stdio.h>
#include <string.h>

int main(){

	int i, n;
	char s1[100], s2[100];
	scanf ("%d", &n);
	for (i = 0; i < n; ++i){
		scanf ("%s %s", s1, s2);
		int j, k = 0, flag = 0, s1l= strlen(s1), s2l = strlen(s2);
		j = s1l - s2l;
		for (j; j < s1l; ++j, ++k){
			if (s1[j] != s2[k]){
				//printf ("%c %c", s1[j], s2[k]);
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			printf ("encaixa\n");
		}else{
			printf ("nao encaixa\n");
		}
	}
	return 0;
}