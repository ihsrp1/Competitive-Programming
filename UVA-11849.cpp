#include <bits/stdc++.h>

using namespace std;



int main() {
	
	long long n, m;

	while(cin >> n >> m && n != 0 && m != 0){
		long long temp;
		long long count = 0;
		if(n < m){
			stack<long long> jack;
			set<long long> jill;
			for(long long i = 0; i < n; i++){
				cin >> temp;
				jack.push(temp);
			}
			for(long long i = 0; i < m; i++){
				cin >> temp;
				jill.insert(temp);
			}
			while(!jack.empty()){
				if(jill.find(jack.top()) != jill.end()){
					count++;
				}
				jack.pop();
			}
		}else{
			set<long long> jack;
			stack<long long> jill;
			for(long long i = 0; i < n; i++){
				cin >> temp;
				jack.insert(temp);
			}
			for(long long i = 0; i < m; i++){
				cin >> temp;
				jill.push(temp);
			}
			while(!jill.empty()){
				if(jack.find(jill.top()) != jack.end()){
					count++;
				}
				jill.pop();
			}
		}
		cout << count << endl;
		
	}
	
	return 0;
}