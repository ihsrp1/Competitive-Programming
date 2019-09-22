#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n;
	while(cin >> n && n != 0){
		priority_queue<int, vector<ll>, greater<ll>> heap;
		for(ll i = 0; i < n; i++){
			ll temp;
			cin >> temp;
			heap.push(temp);
		}
		ll soma = 0, total = 0;
		while(heap.size() > 1){
			soma = heap.top();
			heap.pop();
			soma += heap.top();
			heap.pop();
			total += soma;
			heap.push(soma);
		}
		cout << total << endl;
	}
	return 0;
}