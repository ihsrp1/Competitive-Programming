#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n;

	cin >> n;
	vector<ll> claws(n);
	vector<ll> vivos(n, 1);

	ll pendentes = 0;
	for(ll &k : claws){
		cin >> k;
	}
	for(ll i = n-1; i >= 0; i--){
		if(pendentes != 0){
			vivos[i] = 0;
			pendentes--;
		}
		pendentes = max(pendentes, claws[i]);
	}
	ll count = 0;
	for(ll i = 0; i < n; i++){
		if(vivos[i] == 1) count++;
	}
	cout << count << endl;
	return 0;
}