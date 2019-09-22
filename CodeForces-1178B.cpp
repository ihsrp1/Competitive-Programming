#include <bits/stdc++.h>

using namespace std;



long long first[1000001], last[1000001];

int main(){
	//vvvovvv
	//0122234
	//0322210
	//vvovooovovvovoovoovvvvovovvvov
	//011111111122222222234555556777
	//066666666655555555543222221000

	string s;
	cin >> s;
	int tam = s.length();

	long long qtd = 0;
	for(int i = 1; i < tam; i++){
		if(s[i] == 'v' && s[i - 1] == 'v') qtd++;
		first[i] = qtd;
	}
	
	qtd = 0;
	for(int i = tam - 1; i > 0; i--){
		if(s[i] == 'v' && s[i + 1] == 'v') qtd++;
		last[i] = qtd;
	}


	long long ans = 0;
	for(int i = 0; i < tam; i++){
		if(s[i] == 'o'){
			ans += first[i - 1] * last[i + 1];
		}

	}

	cout << ans << endl;
}