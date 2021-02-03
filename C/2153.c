#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int i, j, a, t;
	char text[35], text1[35], text2[35];
	while (scanf ("%s", text) != EOF){
		t = strlen (text);
		a = 0;
		for (i = 0; i < t; ++i){
			text1[i] = text[i];
			j = i + 1;
			text1[i + 1] = '\0';
			for (a = 0; a < t; ++a){
				text2[a] = text[j];
				++j;
			}
			text2[a + 1] = '\0';
			if (strstr (text1, text2) != NULL){
				//printf ("%s\n", text1);
				break;
			}
		}
		printf ("%s\n", text1);
	}


	return 0;
}