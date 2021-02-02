#include <stdio.h>
 
int main() {
 
	char NOME;
	scanf("%s", &NOME);
	double SF;
	scanf("%lf", &SF);
	double VNDS;
	scanf("%lf", &VNDS);
	double TOTAL = SF + (0.15*VNDS);
	printf("TOTAL = R$ %.2lf\n", TOTAL);
 	
 
    return 0;
}
