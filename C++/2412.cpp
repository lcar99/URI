#include <bits/stdc++.h>

using namespace std;

int vizinho[1234][1234], marcado[1234];

int main(){

    int i, j, n, d, arvorex[1234], arvorey[1234];
    scanf("%d %d", &n, &d);
    for(i = 0; i < n; ++i){
        scanf("%d %d", &arvorex[i], &arvorey[i]);
    }
    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j){
            int dx = arvorex[i] - arvorex[j];
            int dy = arvorey[i] - arvorey[j];
            double dist = pow(dx*dx + dy*dy, 0.5);
            if (dist <= d) {
                vizinho[i][j] = vizinho[j][i] = 1;
            }
        }
    }
    deque <int> fila; 
    fila.push_back(0);
    marcado[0] = 1;
    while(!fila.empty()){
        int prox = fila.front();
        fila.pop_front();
        for (i = 0; i < n; ++i){
            if (vizinho[prox][i] and !marcado[i]){
                fila.push_back(i);
                marcado[i] = 1;
            }
        }
    }
    for (i = 0; i < n; ++i){
        if (!marcado[i]){
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0;
}
