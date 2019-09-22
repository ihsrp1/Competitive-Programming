#include <bits/stdc++.h>

using namespace std;



int main(){
	string s;
	string t;
	
	cin >> s >> t;
	int resp = 0;
	for(int i = 0; i < t.length(); i++){
		if(t[i] == s[resp]) resp++;
	}
	
	cout << resp << endl;
	return 0;
}