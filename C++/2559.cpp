#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_NIVEIS (4)
      
long long arvore[1<<MAX_NIVEIS][4];//total, propagação, check7, check13

void atualiza(int lo, int hi, int valor, int noh, int inicio, int fim) {
    if (hi < inicio or lo > fim)//out of range
        return;
 
    if (lo <= inicio and hi >= fim){
        arvore[noh][1] += valor;
        if (inicio == fim){
            arvore[noh][0] = arvore[noh][1];
            arvore[noh][1] = 0;
            if (lo == hi){
                if (valor == 7){
                    arvore[noh][2] = 1;
                }
                else if (valor == 13){
                    arvore[noh][3] = 1;
                }
            }
        }
        return;
    }
 
    int meio = (inicio + fim) / 2;
    int esq = 2*noh + 1;
    int dir = 2*noh + 2;
 
    arvore[esq][1] += arvore[noh][1];
    arvore[dir][1] += arvore[noh][1];
    arvore[noh][1] = 0;
 
    atualiza(lo, hi, valor, esq, inicio, meio);//prenche primeira metade
    atualiza(lo, hi, valor, dir, meio + 1, fim);//preenche segunda metade
    
}
 
void consulta(int lo, int hi, int noh, int inicio, int fim) {
    if (hi < inicio or lo > fim)//out of range
        return;
 
    if (lo <= inicio and hi >= fim){//?
        /*
        if ((arvore[noh][0] + arvore[noh][2]) > valor){
            valor = arvore[noh][0] + arvore[noh][2];
            pos = arvore[noh][1];
        }
        */
        return;
    }
     
    int meio = (inicio + fim)/2;
    int esq = 2*noh + 1;
    int dir = 2*noh + 2;
 
    arvore[noh][0] += arvore[noh][1];
    arvore[esq][1] += arvore[noh][1];
    arvore[dir][1] += arvore[noh][1];
    arvore[noh][1] = 0;
 
    consulta(lo, hi, esq, inicio, meio);
    consulta(lo, hi, dir, meio+1, fim);
    


    return;
}
 
int main() {
    int i, n, q, lo, hi, val, comando, pos, sub;
    while (scanf ("%d", &n) != EOF){
        memset(arvore, 0, sizeof arvore);
        for (i = 0; i < n; ++i){
            scanf ("%d", &val);
            atualiza(i, i, val, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
        }
        ///*
        for(int i = 0; i < (1<<(MAX_NIVEIS)) - 1; ++i) {
            printf("%d %lld %lld %lld %lld\n", i, arvore[i][0], arvore[i][1], arvore[i][2], arvore[i][3]);
        }
        //*/
        scanf ("%d", &q);
        for (i = 0; i < q; ++i){
            scanf ("%d", &comando);
            if (comando == 3){
                scanf("%d%d", &lo, &hi);
                consulta(lo-1, hi-1, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
                //printf("%d\n", );
            }
            else if (comando == 1){
               scanf("%d%d", &pos, &val);
               atualiza(pos - 1, pos - 1, val, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
            }else{
               scanf("%d%d%d%d", &lo, &hi, &sub, &val); 
               //atualiza
            }
        }
        for(int i = 0; i < (1<<(MAX_NIVEIS)) - 1; ++i) {
            printf("%d %lld %lld %lld %lld\n", i, arvore[i][0], arvore[i][1], arvore[i][2], arvore[i][3]);
        }
    }
    return 0;
}