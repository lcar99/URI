#include <stdio.h>

int main(){

	int i, j, k, c1, c2, flag;
	double t1, t2;
	scanf ("%d", &k);
	for (j = 0; j < k; ++j){
		i = 0, flag = 0;
		scanf ("%d %d %lf %lf", &c1, &c2, &t1, &t2);
		t1 = t1 / 100;
		t2 = t2 / 100;
		while (c1 <= c2){
			c1 = c1 + c1 * t1;
			c2 = c2 + c2 * t2;
			++i;
			if (i > 100){
				flag = 1;
				break;
			} 
		}
		if (flag == 1){
			printf ("Mais de 1 seculo.\n");
		}else{
			printf("%d anos.\n", i);
		}
	}
	return 0;
}