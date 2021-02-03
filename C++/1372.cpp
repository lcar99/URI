#include <bits/stdc++.h>

using namespace std;

int m, n, doce[100010], maior[100010], dp1[100010], dpg[100010];

int zap(int pos, int arr[], int dp[]){
    if (pos >= n){
        return 0;
    }
    if (dp[pos] != -1){
        return dp[pos];
    }
    int u, v;
    u = arr[pos] + zap(pos + 2, arr, dp);
    v = zap(pos + 1, arr, dp);
    return dp[pos] = max(u, v);
}

int main(){

    int i, j, cont;
    while (scanf ("%d %d", &m, &n), n != 0 and m != 0){
        cont = 0;
        memset (dpg, -1, sizeof(doce));
        for (i = 0; i < m; ++i){
            for (j = 0; j < n; ++j){
                scanf("%d", &doce[j]);
            }
            memset (dp1, -1, sizeof(doce));
            maior[i] = zap(0, doce, dp1);
        }
        n = m;
        cont = zap(0, maior, dpg);
        printf("%d\n", cont);
    }
    return 0;
}
