#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool smlts(string a, string b){
	return (a+b < b+a); 
}

int main(){
	ll n;
	vector<string> sts;
	
	
	cin >> n;
	string s;
	cin.ignore();
	for(int i = 0; i < n; i++){
		getline(cin, s);
		sts.push_back(s);
	}
	
	sort(sts.begin(), sts.end(), smlts);
	
	string a = "";
	for(int i = 0; i < n; i++){
		a += sts[i];
	}
	cout << a << endl;
	return 0;
}