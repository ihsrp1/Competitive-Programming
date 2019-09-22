#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, cmd, fila = 0, pilha = 0, filap = 0;
	ll resp = 4;
	// 1 stack
	// 2 queue
	// 3 priority_queue
	// 4 impossible
	// 5 not sure
	

	while(cin >> n){
		priority_queue<ll> pq;
		queue<ll> q;
		stack<ll> s;
		int total = 0;
		resp = 4;
		fila = 0, pilha = 0, filap = 0;
		for(ll i = 0; i < n; i++){
			ll temp;
			cin >> cmd >> temp;
			if(cmd == 1){
				pq.push(temp);
				q.push(temp);
				s.push(temp);
			}else{
				total++;
				
				if(!pq.empty()) if(temp == pq.top()) filap++;
				if(!q.empty()) if(temp == q.front()) fila++;
				if(!s.empty()) if(temp == s.top()) pilha++;
				if(!pq.empty()) pq.pop();
				if(!q.empty()) q.pop();
				if(!s.empty()) s.pop();
			}
		}
		//cout << filap << " " << fila << " " << pilha << endl;
		if(filap == total) resp = 3;
		if(fila == total){
			if(resp == 4) resp = 2;
			else resp = 5;
		}
		if(pilha == total){
			if(resp == 4) resp = 1;
			else resp = 5;
		}
		if(resp == 1) cout << "stack\n";
		else if(resp == 2) cout << "queue\n";
		else if(resp == 3) cout << "priority queue\n";
		else if(resp == 4) cout << "impossible\n";
		else cout << "not sure\n";
	}
	return 0;
}