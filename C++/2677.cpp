#include <bits/stdc++.h>

using namespace std;

int n, m, b[1234], pres[1234], dp[1234][1234][2];

int joga (int lo, int hi, int jogador){
	int u, v;
	if (lo == hi){
		if (b[lo] % 2 == 0){
			return 1;
		}else{
			return 0;
		}
	}
	if (dp[lo][hi][jogador] != -1){
		return dp[lo][hi][jogador];
	}else{
		if (b[lo] % 2 == 0){
			if (b[hi] % 2 == 0){
				u = ((pres[hi] - pres[lo - 1]) - joga(lo + 1, hi, (jogador + 1) % 2));
    			v = ((pres[hi] - pres[lo - 1]) - joga(lo, hi - 1, (jogador + 1) % 2));
				return dp[lo][hi][jogador] = max(u,v);
			}else{
				u = (pres[hi] - pres[lo - 1]) - joga (lo + 1, hi, (jogador + 1) % 2);
				return dp[lo][hi][jogador] = u;
			}
		}
		else if (b[hi] % 2 == 0){
			v = (pres[hi] - pres[lo - 1]) - joga (lo, hi - 1, (jogador + 1) % 2);
			return dp[lo][hi][jogador] = v;
		}else{
			u = ((pres[hi] - pres[lo - 1]) - joga(lo + 1, hi, (jogador + 1) % 2));
    		v = ((pres[hi] - pres[lo - 1]) - joga(lo, hi - 1, (jogador + 1) % 2));
			return dp[lo][hi][jogador] = max(u,v);
		}
	}
}

int is_even(int a){
	if (a % 2 == 0)
		return 1;
	return 0;
}

int main(){
	
	int i, cont, aux = 0;
	while (scanf ("%d", &n), n != 0){
		aux = 0;
		memset (b, 0, sizeof(b));
		memset (dp, -1, sizeof(dp));
		memset (pres, 0, sizeof(pres));
		n *= 2;
		for (i = 1; i <= n; ++i){
			scanf ("%d", &b[i]);
		}
		pres[1] = is_even(b[1]);
		for (i = 2; i <= n; ++i){
			pres[i] = pres[i - 1] + is_even(b[i]);
		}
		cont = joga(1, n, 0);
		printf("%d\n", cont);
	}
	return 0;
}