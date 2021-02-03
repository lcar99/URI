#include <cstdio>

using namespace std;

int main(){

	int i, zap, n = 69, cont0, cont1;
	while (scanf ("%d", &n), n != 0){
		cont0 = cont1 = 0;
		for (i = 0; i < n; ++i){
			scanf ("%d", &zap);
			if (zap == 0){
				++cont0;
			}else{
				++cont1;
			}
		}
		printf ("Mary won %d times and John won %d times\n", cont0, cont1);
	}
	return 0;
}
