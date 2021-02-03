#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

int main(){

	int i;
	char s[100000];
	scanf ("%[^\n]%*c", s);
	if (strcasestr(s, "zelda") != NULL){
		printf ("Link Bolado\n");
	}else{
		printf ("Link Tranquilo\n");
	}
	
}