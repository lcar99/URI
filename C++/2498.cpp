#include <bits/stdc++.h>

using namespace std;

int i, n, c, lixo = 0;
int livro[1123][2], dp[1123][1123];

int zap(int pos, int peso){
    int u, v;
    if (pos == n or peso > c){
        if (peso <= c){
            return 0;
        }else{
            return -1e9;
        }
    }
    if (dp[pos][peso] != -1){
        return dp[pos][peso];
    }
    u = zap(pos + 1, peso + livro[pos][0]) + livro[pos][1];
    v = zap(pos + 1, peso);
    return dp[pos][peso] = max(u, v);
}

int main(){

    while (scanf("%d%d", &n, &c), n != 0 and c != 0){
        memset(livro, 0, sizeof(livro));
        memset(dp, -1, sizeof(dp));
        ++lixo;
        for (i = 0; i < n; ++i){
            scanf("%d", &livro[i][0]);
            scanf("%d", &livro[i][1]);
        }
        int incrivel = zap(0,0);
        printf("Caso %d: ", lixo);
        printf("%d\n", incrivel);
    }
    return 0;
}
