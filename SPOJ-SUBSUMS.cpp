#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main(){
	ll n, a, b;
	vector<ll> set, soma1, soma2;

	cin >> n >> a >> b;


	for(ll i = 0; i < n; i++){
		ll temp;
		cin >> temp;
		set.push_back(temp);
	}

	ll tamCombs = 1 << (n/2);
	ll tamSub = (n/2);

	for(ll i = 0;i < tamCombs; i++){
		ll soma = 0;
		for(ll j = 0; j < tamSub; j++){
			if(i & (1 << j)){
				soma += set[j];
			}
		}
		soma1.push_back(soma);
	}

    if((n & 1) == 1){
		tamSub = (n/2) + 1;
		tamCombs = 1 << tamSub;
	}else{
		
		tamSub = (n/2);
		tamCombs = 1 << tamSub;
	}
	for(ll i = 0; i < tamCombs; i++){
		ll soma = 0;
		for(ll j = 0; j < tamSub; j++){
			if(i & (1 << j)){
				soma += set[(n/2) + j];
			}
		}
		soma2.push_back(soma);
	}
	sort(soma1.begin(), soma1.end());

	vector<ll>::iterator up, down;
	ll resp = 0;

	for(ll i = 0; i < tamCombs; i++){
		up = lower_bound(soma1.begin(),soma1.end(),a-soma2[i]);
		down = upper_bound(soma1.begin(),soma1.end(),b-soma2[i]);
		resp += (down - up);
	}
	cout << resp << endl;
	
}