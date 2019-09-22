#include <bits/stdc++.h>
#define INV 999
using namespace std;

int nsols = 0;
int x, y;
int rainhas[8];

void printSol(){
	if(nsols >= 10) printf("%d      ", nsols);
	else printf(" %d      ", nsols);

	for(int i = 0; i < 8; i++){
		printf("%d", rainhas[i]+1);
		if(i < 7) printf(" ");
	}
	printf("\n");
}

void ver(int coluna){
	if(coluna == 8){
		nsols++;
		printSol();
		return;
	}

	if(coluna == y) ver(coluna+1);
	else{
		for(int linha = 0; linha < 8; linha++){
			int no = 0;
			if((abs(coluna - y) == abs(linha - x)) || (coluna == y) || (linha == x)){
				no = 1;
			}else{
				for(int i = 0; i < coluna; i++){
					if((abs(coluna - i) == abs(linha - rainhas[i])) || (coluna == i) || (linha == rainhas[i])){
						//printf("Choque com a rainha %d %d\n", rainhas[i], i);
						no = 1;
						break;
					}else no = 0;
				}
			}
			
			if(no == 0){
				//printf("Conseguiu colocar em %d %d\n", linha, coluna);
				rainhas[coluna] = linha;
				ver(coluna+1);
				rainhas[coluna] = -INV;
			}
		}
	}

	return;
}


int main() 
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		x -= 1;
		y -= 1;
		nsols = 0;
		memset(rainhas, -INV, sizeof rainhas);

		rainhas[y] = x;

		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		ver(0);
		if(i < n-1)
			printf("\n");
	}
    return 0; 
} 