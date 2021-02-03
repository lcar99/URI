#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int i, j, n, c;
	char str[51];
	scanf ("%d", &n);
	for (i = 0; i < n; ++i){
		scanf ("%s", str);
		scanf ("%d", &c);
		int l = strlen(str);
		for (j = 0; j < l; ++j){
			str[j] = str[j] - c;
			if (str[j] < 65){
				str[j] = str[j] + 26;
			}
		}
		printf ("%s\n", str);
	}
return 0;
}
