#include <bits/stdc++.h>

using namespace std;

int v[23], zap[23];

int fib(int x){
    if (x == 1){
        return 1;
    }
    if (x == 2){
        return 2;
    }
    int res = fib(x - 1) + fib(x - 2);
    return v[x] = res;
}


int main(){

    int i, n, j, km, resto;
    v[1] = 1;
    v[2] = 2;
    fib(22);
    scanf("%d", &n);
    for(i = 0; i < n; ++i){
        scanf("%d", &km);
        resto = km;
        memset(zap, 0, sizeof(zap));
        for (j = 22; j > 0; --j){
            if (resto >= v[j]){
                zap[j] = 1;
                resto -= v[j];
            }
        }
        for (j = 22; j > 0; --j){
            if (zap[j] == 1){
                zap[j - 1] = 1;
                zap[j] = 0;
                --j;
            }
        }
        int acum = 0;
        for (j = 22; j > 0; --j){
            if (zap[j] == 1){
                acum += v[j];
            }
        }
        printf("%d\n", acum);
    }

    return 0;
}
