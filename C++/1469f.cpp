#include <bits/stdc++.h>

using namespace std;

vector<int> lista[515];
int menIdade;

void add(int v1, int v2){

	lista[v2].push_back(v1); 

}

void dfs(int visitado[], int idade[], int v){

    visitado[v] = 1;
    int n = lista[v].size();
    for (int i = 0; i < n; ++i){
		if (idade[lista[v][i]] < menIdade){
			menIdade = idade[lista[v][i]];
		}    	
    }
    for (int i = 0; i < n; ++i){
        int prox = lista[v][i];
        if (visitado[prox] != 1){
        	dfs (visitado, idade, prox);
        }
    }

}

void troca(int v, int v1, int v2){
	int n = lista[v].size();
	for (int i = 0; i < n; ++i){
        if (lista[v][i] == v1){
        	lista[v][i] = v2;
        }
        else if (lista[v][i] == v2){
        	lista[v][i] = v1;
        }

    }
}

int main(){
	
	int nVertices, nArestas, nInst, v1, v2;
	char inst;
	while (scanf ("%d %d %d", &nVertices, &nArestas, &nInst) != EOF){
		int visitado[nVertices], idade[nVertices];
		memset (visitado, 0, sizeof(visitado));
		memset (idade, 0, sizeof(idade));
		for (int i = 0; i < 516; ++i){
   			lista[i].clear();
		}
		for (int i = 0; i < nVertices; ++i){
			scanf ("%d", &idade[i]);
		}
		for (int i = 0; i < nArestas; ++i){
			scanf ("%d %d", &v1, &v2);
			add (v1 - 1, v2 - 1);
		}
		for (int i = 0; i < nInst; ++i){
			menIdade = 1e9;
			memset (visitado, 0, sizeof(visitado));
			scanf (" %c", &inst);
			if (inst == 'T'){
				scanf ("%d %d", &v1, &v2);
				swap (lista[v1 - 1], lista[v2 - 1]);
				for (int j = 0; j < nVertices; ++j){
					troca (j, v1 - 1, v2 - 1);
				}
			}else{
				scanf ("%d", &v1);
				dfs (visitado, idade, v1 - 1);
				if(menIdade == 1e9){
					printf ("*\n");
				}else{
					printf ("%d\n", menIdade);
				}
			}
		}
	}
	return 0;
}