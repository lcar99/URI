#include <bits/stdc++.h>

using namespace std;

int n, polemico[101][101], dp[101][101];

int zap(int l, int c){
    int i;
    if (l == 0){
        return polemico[l][c];
    }
    if (dp[l][c] != -1){
        return dp[l][c];
    }
    int aux = 0;
    for(i = c; i < c + l + 1; ++i){
        aux += polemico[l][i];
    }
    return dp[l][c] = aux + min(zap(l - 1, c), zap(l - 1, c + 1));
}

int main(){

    int i, j, cont;
    memset(dp, -1, sizeof(dp));
    scanf ("%d", &n);
    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j){
            scanf("%d", &polemico[i][j]);
        }
    }
    cont = zap(n - 1, 0);
    printf("%d\n", cont);
    return 0;
}
//pos, lo, hi
