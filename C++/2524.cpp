#include <bits/stdc++.h>

using namespace std;

int n, m, b[1234], dp[1234][1234];

int somax (int soma, int pos){
	if (pos == n){
		if (soma % m == 0){
			return 0;
		}else{
			return -1e9;
		}
	}
	if (dp[soma][pos] != -1){
		return dp[soma][pos];
	}else{
		int u = somax(soma % m, pos + 1);
		int v = somax((soma + b[pos])%m, pos + 1) + 1;
		return dp[soma][pos] = max(u, v);
	}
}

int main(){
	
	int i, cont;
	while (scanf ("%d%d", &m, &n) != EOF){
		memset (b, 0, sizeof(b));
		memset (dp, -1, sizeof(dp));
		for (i = 0; i < n; ++i){
			scanf ("%d", &b[i]);
			b[i] %= m;
		}
		cont = somax(0, 0);
		printf("%d\n", cont);
	}
	return 0;
}
