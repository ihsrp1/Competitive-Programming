#include <bits/stdc++.h>


using namespace std;


int main(){
	string s;
	
	cin >> s;
	int tam = s.length();
	int num = (s[tam-2]-48)*10 + (s[tam-1]-48);
	
	if(num % 4 == 0) cout << 4 << endl;
	else cout << 0 << endl;
	
	return 0;
}