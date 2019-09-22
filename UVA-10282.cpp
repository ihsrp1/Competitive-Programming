#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	map<string, string> dictnry;
	string s;

	getline(cin, s);
	stringstream ss(s);

	while(s != ""){
		string a, b;
		ss >> a >> b;
		//cout << a << " " << b << endl;
		dictnry[b] = a;
		getline(cin, s);
		ss = stringstream(s);
	}

	while(cin >> s){
		if(dictnry[s] == "") cout << "eh" << endl;
		else cout << dictnry[s] << endl;
	}

}