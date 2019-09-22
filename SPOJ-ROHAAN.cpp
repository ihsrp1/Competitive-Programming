#include <bits/stdc++.h>
#define INF 1e8
#define MAX 300


using namespace std;

int matriz[MAX][MAX];
int D[MAX][MAX];

void fw(int n){
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (matriz[i][j] > matriz[i][k] + matriz[k][j])
					matriz[i][j] = matriz[i][k] + matriz[k][j];
			}
		}
	}
}


int main (){
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int t, n, r, soma;

	cin >> t;

	for(int i = 0; i < t; i++){
		soma = 0;
		cin >> n;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				int temp;
				cin >> matriz[j][k];
			}
		}
		fw(n);
		cin >> r;

		for(int j = 0; j < r; j++){
			int t1, t2;
			cin >> t1 >> t2;
			soma += matriz[t1-1][t2-1];
		}

		cout << "Case #" << i+1 << ": " << soma << endl;
	}
	return 0;
}