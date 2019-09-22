#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll factorial[22];

int main()
{
	factorial[0] = 1;
	for(int i = 1; i <= 20; i++){
		factorial[i] = factorial[i-1] * i;
	}

	int t;
	cin >> t;
	for(int j = 1; j <= t; j++){
		stack<int> facts;
		ll n;
		cin >> n;
		cout << "Case " << j << ": ";
		/*if(n == 1){
			cout << "0!\n";
			continue;
		}*/
		int i;
		for(i = 0; factorial[i] < n; i++){
		}
		while(i >= 0){
			if(factorial[i] <= n){
				facts.push(i);
				n -= factorial[i];
			}
			i--;
		}
		if(n == 0){
			while(facts.size() != 1){
				cout << facts.top() << "!+";
				facts.pop();
			}
			cout << facts.top() << "!\n";
			facts.pop();
		}else cout << "impossible\n";

	}
	
	
    return 0;
}