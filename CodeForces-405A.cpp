#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n;
	vector<ll> v;
	cin >> n;
	for(ll i = 0; i < n; i++){
		ll temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		if(i < n-1) cout << v[i] << " ";
		else cout << v[i] << endl;
	}
	return 0;
}