#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n;

	cin >> n;
	ll soma = 0, maximum = 0;
	for(ll i = 0; i < n; i++){
		ll temp;
		cin >> temp;
		soma += temp;
		maximum = max(maximum, temp);
	}
	
	if(soma % 2 != 0 || maximum * 2 > soma) cout << "NO" << endl;
	else cout << "YES" << endl; 
	return 0;
}