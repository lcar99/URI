#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g[100][100];

typedef struct lista_prioridade{
    int vertice;
    int prioridade;
    struct lista_prioridade * prox;
}lista_prioridade;

lista_prioridade * raiz;

lista_prioridade * aloca(int vertice, int prioridade){
    lista_prioridade * nova = (lista_prioridade *)malloc(sizeof(lista_prioridade));
    nova->vertice = vertice;
    nova->prioridade = prioridade;
    nova->prox = NULL;
    return nova;
}

void lista_p_pop(){
    lista_prioridade * temp = raiz;
    raiz = raiz->prox;
    free(temp);
}


void lista_p_push(int vertice, int prioridade){ 
    if (raiz == NULL){
        raiz = aloca(vertice, prioridade);
        return;
    }
    lista_prioridade * raiz_temp = raiz; 
    lista_prioridade * temp = aloca(vertice, prioridade); 
    if (raiz->prioridade > prioridade){ 
        temp->prox = raiz; 
        raiz = temp; 
    }else{
        while (raiz_temp->prox != NULL && raiz_temp->prox->prioridade < prioridade){ 
           raiz_temp = raiz_temp->prox; 
        } 
        temp->prox = raiz_temp->prox; 
        raiz_temp->prox = temp; 
    } 
}

void add(int i, int j, int n, int a, int b, int c, int d){
    if (a == 1){
        g[(i * n) + j][(i * n) + j + n] = 1;
    }
    if (b == 1){
        g[(i * n) + j][(i * n) + j - n] = 1;
    }
    if (c == 1){
        g[(i * n) + j][(i * n) + j - 1] = 1;
    }
    if (d == 1){
        g[(i * n) + j][(i * n) + j + 1] = 1;
    }
}

void dijkstra(int dist[], int spt[], int nVertices, int vIni){
    lista_p_push(vIni, 0);
    dist[vIni] = 0;
    while (raiz != NULL){
        int menor = raiz->vertice;
        lista_p_pop();
        spt[menor] = 1;
        for (int j = 0; j < nVertices; ++j){
            if(spt[j] == 0 and g[menor][j] == 1 and dist[menor] != 1e9 and dist[menor] + g[menor][j] < dist[j]){
                dist[j] = dist[menor] + g[menor][j];
                lista_p_push(j, dist[j]);
            }
        }
    }  
}


int main(){
    
    int nVertices, n2, p, a, b, c, d, x0, y0, x1, y1;
    int spt[100], dist[100];
    while(scanf ("%d", &nVertices), nVertices != 0){ 
        n2 = nVertices * nVertices; 
        for (int i = 0; i < 100; ++i){
            for (int j = 0; j < 100; ++j){
                g[i][j] = 0;
            }
        }
        for (int i = nVertices - 1; i >= 0; --i){
            for (int j = 0; j < nVertices; ++j){
                scanf("%d %d %d %d", &a, &b, &c, &d);
                add(i, j, nVertices, a, b, c, d);
            }
        }
        scanf("%d", &p);
        for (int i = 0; i < p; ++i){
            for (int j = 0; j < 100; ++j){
                dist[j] = 1e9;
                spt[j] = 0;
            }
            scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
            dijkstra(dist, spt, n2, y0 * nVertices + x0);
            if (dist[y1 * nVertices + x1] == 1e9){
                printf("Impossible\n");
            }else{
                printf("%d\n", dist[y1 * nVertices + x1]);
            }
        }
        printf("\n");
    }
    return 0;
}
