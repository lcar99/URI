#include <stdio.h>
#include <stdlib.h>

int compara_nada(const void *a, const void *b){
    long long int x, y;
    x = *(long long int*)a;
    y = *(long long int*)b;
    return x - y;
}

int main(){

    long long int i, n, c, s, m, x, aux, r;
    long long int v[123456];
    scanf ("%lld %lld", &n, &c);
    for (i = 0; i < n; ++i){
        scanf ("%lld", &v[i]);
    }
    qsort (v, n, sizeof(long long int), compara_nada);
    long long int e = c * v[n - 1];
    //printf ("%lld\n", e);
    s = 0, x = 0; 
    while (s != e - 1){
        x = 0;
        m = (s + e)/2;
        //printf ("...%lld %lld %lld ", s, m, e);
        for (i = 0; i < n; ++i){
            x += m/v[i];
        }
        //printf ("%lld\n", x);
        if(x > c){
            e = m;
        }
        else if(x < c){
            s = m;
        }else{
            r = 0;
            for (i = 0; i < n; ++i){
                r += (m - 1)/v[i];
            }
            if (x == r){
                e = m;
            }else{
                printf ("%lld\n", m);
                break;
            }
        }
        aux = m;
    }
    x = 0;
    if (s == e - 1){
        for (i = 0; i < n; ++i){
            x += s/v[i];
        }
        if (x > c){
            printf("%lld\n", s);
        }else{
            printf("%lld\n", e);
        }
    }
    return 0;
}