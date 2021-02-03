#include <bits/stdc++.h>

using namespace std;

int remendo[1234567], local[1234567], dp[1234567], n, c, t1, t2;

int pneu(int pos){
	int u, v;
	if (pos > local[n - 1]){
		return 0;
	}
	if (dp[pos] != -1){
		return dp[pos];
	}
	if (remendo[pos] == 0){
		return dp[pos] = pneu(pos + 1);
	}
	u = t1 + pneu(pos + t1 + 1);
	v = t2 + pneu(pos + t2 + 1);
	return dp[pos] = min(u, v);
}

int main(){

	int i;
	while(scanf("%d %d %d %d", &n, &c, &t1, &t2) != EOF){
		memset(remendo, 0, sizeof(remendo));
		memset(dp, -1, sizeof(remendo));
		for (i = 0; i < n; ++i){
			scanf ("%d", &local[i]);
		}
		for (i = 0; i < n; ++i){
			remendo[local[i]] = 1;
		}
		printf("%d\n", pneu(1));
	}
	return 0;
}