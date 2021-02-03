#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int i, j, n, q;
	char str1[22], str2[22];
	scanf ("%d", &n);
	for (i = 0; i < n; ++i){
		int flag = 1;
		scanf ("%d", &q);
		scanf ("%s", str1);
		for (j = 1; j < q; ++j){
			scanf ("%s", str2);
			if (strcmp(str1, str2) != 0){
				flag = 0;
			}
		}
		if (flag == 1){
			printf ("%s\n", str1);
		}else{
			printf ("ingles\n");
		}
	}
return 0;
}
