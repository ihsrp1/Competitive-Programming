#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool sml(ll a, ll b){
	return a < b;
}

int main(){
	stack<ll> stk;
	stack<ll> minimum;
	
	ll n;
	cin >> n;
	
	string s;
	while(n--){
		cin >> s;
		if(s == "PUSH"){
			ll temp;
			cin >> temp;
			stk.push(temp);
			if(minimum.empty() || temp < minimum.top()){
				minimum.push(temp);
			}else{
				minimum.push(minimum.top());
			}
		}else if(s == "POP"){
			if(stk.empty()) cout << "EMPTY" << endl;
			else {
				stk.pop();
				minimum.pop();
			}
		}else{
			if(stk.empty()) cout << "EMPTY" << endl;
			else cout << minimum.top() << endl;
		}
		
	}
	return 0;
}