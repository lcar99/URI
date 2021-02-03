#include <bits/stdc++.h>

using namespace std;

int v[123456], m[123456], lembro[123456][22][2];

int s(int pos, int marc){
    if (marc < 0){
        return -1e9;
    }
    if (pos < 0){
        if (marc == 0){
            return 0;
        }
        return -1e9;
    }
    if (lembro[pos][marc][0]){
        return lembro[pos][marc][1];
    }
    lembro[pos][marc][0] = 1;
    if (m[pos]){
        if (marc == 1){
            return lembro[pos][marc][1] = max(0, s(pos - 1, marc - 1)) + v[pos];
        }else{
            return lembro[pos][marc][1] = s(pos - 1, marc - 1) + v[pos];
        }
    }else{
        if (marc == 0){
            return lembro[pos][marc][1] = max(0,s(pos - 1, marc)) + v[pos];
        }else{
            return lembro[pos][marc][1] = s(pos - 1, marc) + v[pos];
        }
    }
}

int main(){

    int i, j, lo, hi, n, ans = -1e9;
    scanf("%d %d %d", &n, &lo, &hi);
    for (i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; ++i){
        scanf("%d", &m[i]);
    }
    for (i = 0; i < n; ++i){
        for (j = lo; j <= hi; ++j){
            ans = max(ans, s(i, j));
        }
    }
    printf("%d\n", ans);

    return 0;
}
