#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int start, end, delta;
}Tempo;

int dp[1234][4000], n;
Tempo pedra[1234];

int compara_nada(const void *a, const void *b){
    Tempo *x = (Tempo *)a;
    Tempo *y = (Tempo *)b;
    return x->start - y->start;
}

int zap(int pos, int hora){
    int u, v;
    if (pos == n){
        return 0;
    }
    if (dp[pos][hora] != -1){
        return dp[pos][hora];
    }
    if (pedra[pos].start < hora){
        return dp[pos][hora] = zap(pos + 1, hora);
    }
    u = zap(pos + 1, pedra[pos].end);
    v = zap(pos + 1, hora); 
    return dp[pos][hora] = max(u + pedra[pos].delta, v);
}

int main(){

    int i, in, fim, cont;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (i = 0; i < n; ++i){
        scanf("%d%d", &pedra[i].start, &pedra[i].end);
        pedra[i].delta = pedra[i].end - pedra[i].start;
    }
    qsort (pedra, n, sizeof(Tempo), compara_nada);
    cont = zap(0, 0);
    printf("%d\n", cont);
    return 0;
}
