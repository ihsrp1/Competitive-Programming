#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool smlts(pair<string, ll> a, pair<string, ll> b){
	return a.second > b.second;
}

int main(){
	vector<pair<string, ll>> stocks;
	
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int cmd;
		string s;
		ll price;
		cin >> cmd;
		if(cmd == 1){
			cin >> s;
			cin >> price;
			stocks.push_back({s, price});
		}else if(cmd == 2){
			cin >> s;
			cin >> price;
			for(int j = 0; j < stocks.size(); j++){
				if(stocks[j].first == s) stocks[j].second = price;
			}
		}else{
			cin >> s;
			sort(stocks.begin(), stocks.end(), smlts);
			cout << stocks[stocks.size()-1].first << " " << i << endl;
			stocks.pop_back();
		}
	
	}
	return 0;
}