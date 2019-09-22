#include <bits/stdc++.h>

using namespace std;


int main() {
	map<string, int> dic;
	
	int m, n;
	
	cin >> m >> n;
	
	string s;
	int temp;
	for(int i = 0; i < m; i++){
		cin >> s >> temp;
		dic[s] = temp;
	}
	
	for(int j = 0; j < n; j++){
		long long soma = 0;
		while(cin >> s && s != "."){
			soma += dic[s];
		}
		cout << soma << endl;
	}
	
    return 0;
}