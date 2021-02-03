#include <bits/stdc++.h>

using namespace std;

int n, menor_altura, rect[1234567];
long long dp[1234567];

long long zap(int pos, int qtd, int menor_altura, int flag){
	long long u, v;
	if(pos >= n){
		return menor_altura * qtd;
	}
	if (dp[pos] != -1){
		return dp[pos];
	}
	if (flag == 1){
		v = zap(n + 1, qtd, menor_altura, 0);	
	}else{
		v = zap(pos + 1, qtd, menor_altura, 0);
	}
	menor_altura = min(rect[pos], menor_altura);
	u = zap(pos + 1, qtd + 1, menor_altura, 1);
	return dp[pos] = max(u, v);
}

int main(){

	int i;
	long long area;
	while(scanf("%d", &n), n != 0){
		memset(dp, -1, sizeof(dp));
		for (i = 0; i < n; ++i){
			scanf("%d", &rect[i]);
		}
		area = zap(0,0,1e9+1, 0);
		printf("%lld\n", area);
	}
	return 0;
}