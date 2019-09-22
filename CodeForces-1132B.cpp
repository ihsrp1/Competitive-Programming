#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void f(priority_queue<ll> price, ll temp, ll sum){
	
}


int main(){
	ll n, sum = 0;
	cin >> n;
	
	vector<ll> price;
	
	for(int i = 0; i < n; i++){
		ll temp;
		cin >> temp;
		sum += temp;
		price.push_back(temp);
	}
	sort(price.begin(), price.end());
	reverse(price.begin(), price.end());

	ll m;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		ll temp;
		cin >> temp;
		cout << sum - price[temp-1] << endl;
	}
	
	
	return 0;
}