#include <bits/stdc++.h>

using namespace std;

long long int mintemp[112345];

int main(){

    long long int i, n, m, c, aux, j;
    while(scanf("%lld%lld", &n, &m), n != -1 and m != -1){
        memset(mintemp, 0, sizeof(mintemp));
        for (i = 1; i <= n; ++i){
            scanf("%lld", &aux);
            mintemp[i] = m * aux;
        }
        long long int hora = 0;
        j = n;
        for (i = 1; i <= n; ++i, --j){
            hora += mintemp[j] * i;
        }
        printf("%lld\n", hora);
    }
    return 0;
}
