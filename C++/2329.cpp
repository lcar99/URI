#include <bits/stdc++.h>

using namespace std;

int pao[12345];

int main(){

	int i, n, k, r;
	scanf ("%d%d", &n, &k);
	for (i = 0; i < k; ++i){
		scanf("%d", &pao[i]);
	}
	int s, m, e, acum;
	s = 0;
	e = 1e4;
	while(s != e - 1){
		acum = 0;
		m = (s + e)/2;
		for (i = 0; i < k; ++i){
			acum += pao[i]/m;
		}
		if (acum < n){
			e = m;
		}
		else if (acum > n){
			s = m;
		}else{
			r = 0;
            for (i = 0; i < k; ++i){
                r += pao[i]/(m + 1);
            }
            if (acum == r){
                s = m;
            }else{
                printf ("%d\n", m);
                break;
            }
		}
	}
	acum = 0;
	if (s == e - 1){
        for (i = 0; i < k; ++i){
            acum += pao[i]/s;
        }
        if (acum > n){
            printf("%d\n", s);
        }else{
            printf("%d\n", e);
        }
    }
	return 0;
}
