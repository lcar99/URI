#include <bits/stdc++.h>

using namespace std;

int main(){

    int i, n, b, v8[10], v4[10], v2[10], f, gol1, gol2, aux = 0;
    for (i = 0; i < 8; ++i){
        scanf("%d %d", &gol1, &gol2);
        if (gol1 > gol2){
            v8[i] =  2 * i;
        }else{
            v8[i] = (2 * i) + 1;
        }
    }
    for (i = 0; i < 4; ++i){
        scanf("%d %d", &gol1, &gol2);
        if (gol1 > gol2){
            v4[i] = v8[2 * i];
        }else{
            v4[i] = v8[(2 * i) + 1];
        }
    }
    for (i = 0; i < 2; ++i){
        scanf("%d %d", &gol1, &gol2);
        if (gol1 > gol2){
            v2[i] = v4[2 * i];
        }else{
            v2[i] = v4[(2 * i) + 1];
        }
    }

    scanf("%d %d", &gol1, &gol2);
    if (gol1 > gol2){
        printf("%c\n", v2[0] + 65);
    }else{
        printf("%c\n", v2[1] + 65);
    }
    return 0;
}
