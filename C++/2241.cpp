#include <bits/stdc++.h>

using namespace std;

#define MAX (501)
 
int main(){
	
	int i, j, n, p, l, c, k, contp = 0, contb = 0;
	int tabp[MAX][MAX], tabb[MAX][MAX];
	memset(tabp, 0, sizeof(tabp));
	memset(tabb, 0, sizeof(tabb));
	scanf ("%d %d", &n, &p);
	for (i = 1; i <= p; ++i){
		scanf ("%d %d", &l, &c);
		tabp[l][c] = 1;
	}
	for (i = 1; i <= p; ++i){
		scanf ("%d %d", &l, &c);
		tabb[l][c] = 1;
	}
	/*
	for (i = 1; i <= n; ++i){
		for (j = 1; j <= n; ++j){
			printf("%d ", tabp[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
	*/
	int sump[MAX][MAX];
	//memset(sump, 0, sizeof(sump)); 
    sump[0][0] = tabp[0][0]; 
    for (int i = 1; i <= n; ++i){
        sump[0][i] = sump[0][i - 1] + tabp[0][i]; 
    }
    for (int i = 0; i <= n; ++i){//0
        sump[i][0] = sump[i - 1][0] + tabp[i][0]; 
    }
    for (int i = 1; i <= n; ++i) { 
        for (int j = 1; j <= n; ++j){ 
            sump[i][j] = sump[i - 1][j] + sump[i][j - 1] - sump[i - 1][j - 1] + tabp[i][j];
        } 
    }
    int sumb[MAX][MAX];
    //memset(sumb, 0, sizeof(sumb));  
    sumb[0][0] = tabb[0][0]; 
    for (int i = 1; i <= n; ++i){
        sumb[0][i] = sumb[0][i - 1] + tabb[0][i]; 
    }
    for (int i = 0; i <= n; ++i){//0
        sumb[i][0] = sumb[i - 1][0] + tabb[i][0]; 
    }
    for (int i = 1; i <= n; ++i) { 
        for (int j = 1; j <= n; ++j){ 
            sumb[i][j] = sumb[i - 1][j] + sumb[i][j - 1] - sumb[i - 1][j - 1] + tabb[i][j];
        } 
    }
    /*
    for (i = 1; i <= n; ++i){
		for (j = 1; j <= n; ++j){
			printf("%d ", sump[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
	for (i = 1; i <= n; ++i){
		for (j = 1; j <= n; ++j){
			printf("%d ", sumb[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
	*/
    int zapp = 0, zapb = 0;
    for (i = 1; i <= n; ++i){
		for (j = 1; j <= n; ++j){
			for (k = 0; k < n; ++k){
				if (i + k > n or j + k > n){
					break;
				}
				zapp = sump[i + k][j + k] - sump[i + k][j - 1] - 
				sump[i - 1][j + k] + sump[i - 1][j - 1];
				zapb = sumb[i + k][j + k] - sumb[i + k][j - 1] - 
				sumb[i - 1][j + k] + sumb[i - 1][j - 1];
				if (zapp > 0 and zapb == 0){
					//printf("PRETO i:%d j:%d k:%d\n",i, j, k);
					//printf("zapp:%d zapb:%d\n",zapp, zapb);
					++contp;
				}
				else if (zapb > 0 and zapp == 0){
					//printf("BRANCO i:%d j:%d k:%d\n",i, j, k);
					//printf("zapp:%d zapb:%d\n",zapp, zapb);
					++contb;
				}
			}		
		}
	}

    /*
    for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			printf("%d ", sump[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			printf("%d ", sumb[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
	*/  
	/*
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			printf("%d ", tabp[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			printf("%d ", tabb[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
	*/
	printf("%d %d\n",contp, contb);

	return 0;
}
