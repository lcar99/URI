#include <bits/stdc++.h> 

using namespace std; 

bool isBipartite(vector<int> adj[], int v, vector<int>& visited){ 
	for (int i = 0; i < adj[v].size(); ++i){ 
		int u = adj[v][i]; 
		if (visited[u] == 0){ 
			if (visited[v] == 1){
				visited[u] = 2;
			}
			else if (visited[v] == 2){
				visited[u] = 1;
			}  
			if (!isBipartite(adj, u, visited)){ 
				return false; 
			}
		}  
		else if (visited[u] == visited[v]){ 
			return false; 
		}
	} 
	return true; 
} 
 
int main(){ 
 
	int i, n, pos1, pos2;
	char sinal;
	while(scanf("%d", &n), n != 0){ 
		vector<int> adj[n + 1]; 
		vector<int> visited(n + 1); 
		for (i = 0; i < n; ++i){
			scanf ("%d", &pos1);
			sinal = 'a';
			while(sinal != '\n'){
				scanf("%d%c", &pos2, &sinal);
				adj[pos1].push_back(pos2); 
				adj[pos2].push_back(pos1);		
			}
		}
		visited[1] = 1; 
		if (isBipartite(adj, 1, visited)){ 
			printf("SIM\n"); 
		}else{ 
			printf("NAO\n"); 
		} 
	}
	return 0; 
} 
