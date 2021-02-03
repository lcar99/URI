#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_NIVEIS (18)
      
long long arvore[1<<MAX_NIVEIS][3];
 
int pos, valor;

void atualiza(int lo, int hi, int valor, int noh, int inicio, int fim) {
    if (hi < inicio or lo > fim)//out of range
        return;
 
    if (lo <= inicio and hi >= fim){//out of range
        arvore[noh][2] += valor;//valor nao existe ainda, criar???
        if (inicio == fim){
            arvore[noh][0] += arvore[noh][2];
            arvore[noh][2] = 0;
            if (lo == hi){
                arvore[noh][1] = lo;
            }
        }
        return;
    }
 
    int meio = (inicio + fim) / 2;
    int esq = 2*noh + 1;
    int dir = 2*noh + 2;
 
    arvore[esq][2] += arvore[noh][2];
    arvore[dir][2] += arvore[noh][2];
    arvore[noh][2] = 0;
 
    atualiza(lo, hi, valor, esq, inicio, meio);//prenche primeira metade
    atualiza(lo, hi, valor, dir, meio + 1, fim);//preenche segunda metade
    //parte das somas, desnecessaria?
    //arvore[noh][0] = arvore[esq][0] + arvore[dir][0];//propagação
    long long x, y;
    x = arvore[esq][0] + arvore[esq][2];
    y = arvore[dir][0] + arvore[dir][2];
    if (x > y){
        arvore[noh][0] = x;
        arvore[noh][1] = arvore[esq][1];
    }
    else if (x < y){
        arvore[noh][0] = y;
        arvore[noh][1] = arvore[dir][1];   
    }else{
        if (arvore[esq][1] > arvore[dir][1]){
            arvore[noh][0] = x;
            arvore[noh][1] = arvore[esq][1];       
        }else{
            arvore[noh][0] = x;
            arvore[noh][1] = arvore[esq][1];
        }
    }
    //arvore[noh][0] += arvore[esq][1] * (meio - inicio + 1);
    //arvore[noh][0] += arvore[dir][1] * (fim - (meio + 1) + 1);
}
 
void consulta(int lo, int hi, int noh, int inicio, int fim) {
    if (hi < inicio or lo > fim)//out of range
        return;
 
    if (lo <= inicio and hi >= fim){//?
        if ((arvore[noh][0] + arvore[noh][2]) > valor){
            valor = arvore[noh][0] + arvore[noh][2];
            pos = arvore[noh][1];
        }
        return;
    }
     
    int meio = (inicio + fim)/2;
    int esq = 2*noh + 1;
    int dir = 2*noh + 2;
 
    arvore[noh][0] += arvore[noh][2];
    arvore[esq][2] += arvore[noh][2];
    arvore[dir][2] += arvore[noh][2];
    arvore[noh][2] = 0;
 
    consulta(lo, hi, esq, inicio, meio);
    consulta(lo, hi, dir, meio+1, fim);
    


    return;
}
 
int main() {
    int i, n, q, lo, hi, val;
    char comando;
    while (scanf ("%d%d", &n, &q) != EOF){
        memset(arvore, 0, sizeof arvore);
        for (i = 0; i < n; ++i){
            scanf ("%d", &val);
            atualiza(i, i, val, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
        }
        /*
        for(int i = 0; i < (1<<(MAX_NIVEIS)) - 1; ++i) {
            printf("%d %lld\n", i, arvore[i][1]);
        }
        */
        for (i = 0; i < q; ++i){
            scanf (" %c", &comando);
            if (comando == 'C'){
                pos = valor = 0;
                scanf("%d%d", &lo, &hi);
                consulta(lo-1, hi-1, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
                printf("%d\n", pos + 1);
            }else{
               scanf("%d%d%d", &lo, &hi, &val);
               atualiza(lo-1, hi-1, val, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
            }
        }
    }
    return 0;
}