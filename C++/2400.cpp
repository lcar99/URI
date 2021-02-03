#include <bits/stdc++.h>

using namespace std;

#define MAX_NIVEIS (18)

int arvore[1<<MAX_NIVEIS];

void atualiza(int pos, int valor, int noh, int inicio, int fim) {
    if (inicio == fim and inicio == valor){
        arvore[noh] = 1;
        return;
    }
    if (valor > fim or valor < inicio){
        return;
    }
    int meio = (inicio + fim) / 2;
    int esq = 2*noh + 1;
    int dir = 2*noh + 2;

    atualiza(pos, valor, esq, inicio, meio);
    atualiza(pos, valor, dir, meio + 1, fim);
    arvore[noh] = arvore[esq] + arvore[dir];
}

int consulta(int a, int b, int noh, int inicio, int fim) {
    if (a <= inicio and b >= fim)
        return arvore[noh];

    int meio = (inicio + fim)/2;

    int x = 0, y = 0;

    if (not(b < inicio or a > meio)) { //[a, b] inter [inicio, meio]
        x = consulta(a, b, 2*noh + 1, inicio, meio);
    }

    if (not(b < meio+1 or a > fim)) { //[a, b] inter [meio+1, fim]
        y = consulta(a, b, 2*noh + 2, meio+1, fim);
    }
    return x + y;
}

int main() {
    int i, n, v;
    long long cont = 0;
    scanf("%d", &n);
    memset(arvore, 0, sizeof arvore);
    for (i = 0; i < n; ++i) {
        scanf ("%d", &v);
        cont += consulta (v, n, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
        atualiza (i, v, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
    }
    printf("%lld\n", cont);
    return 0;
}
