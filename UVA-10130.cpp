#include <bits/stdc++.h>


using namespace std;



int price[1005];
int weight[1005];
int table[1005][35];
int T, N, G, result, maxWeight;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);

	cin >> T;

    for (int k = 0; k < T; k++) {
		result = 0;


        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> price[i] >> weight[i];
        }
        cin >> G;

        for (int x = 0; x < G; x++) {
			cin >> maxWeight;
            for(int i = 0; i < 1005; i++){
				for(int j = 0; j < 35; j++){
					table[i][j] = 0;
				}
			}
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= maxWeight; j++) {
                    if (j >= weight[i]) {
                        table[i][j] = max(table[i - 1][j], table[i - 1][j - weight[i]] + price[i]);
                    } else {
                        table[i][j] = table[i - 1][j];
                    }
                }
            }
            result += table[N][maxWeight];
        }
        cout << result << endl;
    }
	
	return 0;
}