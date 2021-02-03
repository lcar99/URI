#include <bits/stdc++.h>

using namespace std;

int n, k, radar[1234567], bonoros[1234567], dp[1234567];

int zap(int pos){
	int u, v;
	if (pos > radar[n - 1]){
		return 0;
	}
	if (dp[pos] != -1){
		return dp[pos];
	}
	u = zap(pos + k);
	v = zap(pos + 1);
	return dp[pos] = max(u + bonoros[pos], v);
}

int main(){

	int i, t, cont, aux;
	scanf ("%d", &t);
	while(t--){
		memset(radar, 0, sizeof(radar));
		memset(bonoros, 0, sizeof(radar));
		memset(dp, -1, sizeof(radar));
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; ++i){
			scanf("%d", &radar[i]);
		}
		/*
		for (i = 0; i < n; ++i){
			printf("%d ", radar[i]);
		}
		printf("\n");
		*/
		for (i = 0; i < n; ++i){
			scanf("%d", &aux);
			bonoros[radar[i] - 1] = max(bonoros[radar[i] - 1], aux);
		}
		/*
		for (i = 0; i < radar[n - 1]; ++i){
			printf("%d ", bonoros[i]);
		}
		printf("\n");
		*/
		cont = zap(0);
		printf("%d\n", cont);
	}
	return 0;
}
/*
.Pegar ou não pegar:
	Se pegar -> soma += bonoros[radar[pos]] e pos += k
	Se não pegar -> soma = soma e pos += k 
	*/