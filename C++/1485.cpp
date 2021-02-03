#include <bits/stdc++.h>

using namespace std;

int s, b, roleta[256], bolas[128], sum[128];

int zap(int pos, int bola){
	int u, v;
	if (pos >= s){
		if (bola == b - 1){
			return 0;
		}else{
			return -1e9;
		}
	}
	//printf("%d %d\n", pos, bola);
	u = zap(pos + 1, bola + 1) + (sum[pos] * bolas[bola]);
	v = zap(pos + 1, bola);
	return max(u, v);

}

int main(){
	
	int i;
	while(scanf("%d%d", &s, &b), s != 0 and b != 0){
		for (i = 0; i < s; ++i){
			scanf("%d", &roleta[i]);
		}
		for (i = 0; i < b; ++i){
			scanf("%d", &bolas[i]);	
		}
		sum[0] = roleta[s - 1] + roleta[0];
		for(i = 0; i < s - 1; ++i){
			sum[i + 1] = roleta[i] + roleta[i + 1];
		}
		///*
		for(i = 0; i < s; ++i){
			printf("%d ", sum[i]);
		}
		printf("\n");
		//*/
		int cont = zap(0, 0);
		printf("%d\n", cont);
	}
	return 0;
}