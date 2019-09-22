#include <bits/stdc++.h>

using namespace std;


int table[1005][1005];

int dp(int i, int j, string a, string b) {
	if (!a[i]) return 0;
	if (!b[j]) return 0;
	int &result = table[i][j];
	if (~result) return result;
	result = 0;
	result = dp(i + 1, j, a, b);
	result = max(result, dp(i, j + 1, a, b));
	if (a[i] == b[j]) {
		result = max(result, dp(i + 1, j + 1, a, b) + 1);
	}
	return result;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr);

	string string1, string2;
	while (getline(cin, string1) && getline(cin, string2)) {
		for(int i = 0; i < 1005; i++){
			for(int j = 0; j < 1005; j++){
				table[i][j] = -1;
			}
		}
		int result = dp(0, 0, string1, string2);
		cout << result << endl;
	}
	
	return 0;
}