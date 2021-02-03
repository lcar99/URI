#include <bits/stdc++.h>

using namespace std;

int n, v[60];

int quad_perfe(int a){
    int b = sqrt(a);
    if (b * b == a){
        return 1;
    }else{
        return 0;
    }
}

int zap(int bola){//colocar bola onde der quadrado perfeito ou não tiver nada
    int i;
    int flag = 1;
    for (i = 0; i < n; ++i){
        if ((quad_perfe(bola + v[i])) == 1 or v[i] == 0){
            v[i] = bola;
            flag = 0;
            break;
        }
    }
    if (flag == 1){
        return bola;
    }
    return zap(bola + 1);
}
int main(){

    int i, t;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        memset(v, 0, sizeof(v));
        printf("%d\n", zap(1)-1);
    }
    return 0;
}
