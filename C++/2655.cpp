#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_NIVEIS (5)
 
int arvore[1<<MAX_NIVEIS];
 
void atualiza(int pos, int valor, int noh, int inicio, int fim) {
    if (inicio == fim) { // FOLHA!
        arvore[noh] = valor;
        //printf("%d %d\n", noh, arvore[pos]);
        return;
    }
 
    int meio = (inicio + fim) / 2;
    int esq = 2*noh + 1;
    int dir = 2*noh + 2;
 
    if (pos <= meio) { //ESQUERDA!
        atualiza(pos, valor, esq, inicio, meio);
    } else { // DIREITA!
        atualiza(pos, valor, dir, meio + 1, fim);
    }
 
    arvore[noh] = arvore[esq] * arvore[dir];
    //printf("%d %d %d %d\n", noh, arvore[esq], arvore[dir], arvore[pos]);
}
 
int consulta(int a, int b, int noh, int inicio, int fim) {
    if (a <= inicio and b >= fim)
        return arvore[noh];
 
    int meio = (inicio + fim)/2;
 
    int x = 1, y = 1;
 
    if (not(b < inicio or a > meio)) { //[a, b] inter [inicio, meio]
        x = consulta(a, b, 2*noh + 1, inicio, meio);
    }
 
    if (not(b < meio+1 or a > fim)) { //[a, b] inter [meio+1, fim]
        y = consulta(a, b, 2*noh + 2, meio+1, fim);
    }
 
    return x * y;
}
//1 consulta 2 mudança 

int main() {
    int n, m, k, v, a;
    int comando;
    while(scanf("%d %d %d", &n, &k, &m) != EOF) {
        memset(arvore, 0, sizeof arvore);
        for(int i = 0; i < n; ++i){
            scanf("%d", &v);
            atualiza(i, v, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
            //puts("---------------");
        }
 
        ///*
        for(int i = 0; i < (1<<(MAX_NIVEIS)) - 1; ++i) {
            printf("%d %d\n", i, arvore[i]);
        }
 
        puts("---------------");
        //*/
 
        for(int i = 0; i < k; ++i) {
            scanf("%d %d %d", &comando, &a, &v);
            if (comando == 2) {
                atualiza(a-1, v, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
            } else {
                v = consulta(a - 1, v - 1, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
                printf("%d\n", v);
            }
        }
    }
    return 0;
}
 