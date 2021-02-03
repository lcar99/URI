#include <stdio.h>

int main(){

	int i, h1, m1, h2, m2;
	while (1){
		scanf ("%d %d %d %d", &h1, &m1, &h2, &m2);
		if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0){
			break;
		}
		m1 = m1 + h1 * 60;
		m2 = m2 + h2 * 60;
		if (m1 > m2){
			m2 = m2 + 1440;
		}
		printf ("%d\n", m2 - m1);
	}
}