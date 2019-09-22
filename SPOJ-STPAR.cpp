#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	while(n != 0){
		stack<int> side_s;
		int k = 1, main_s[1111];
		bool conseguiu = true;

		for(int i = 0; i < n; i++){
			cin >> main_s[i];
		}
		for(int i = 0; i < n; i++){
			while(!side_s.empty() && side_s.top() == k){
				k++;
				side_s.pop();
			}
			if(main_s[i] == k){
				k++;
			}else if(!side_s.empty() && side_s.top() < main_s[i]){
				conseguiu = false;
				break;
			}else{
				side_s.push(main_s[i]);
			}
		}
		if(conseguiu) cout << "yes" << endl;
		else cout << "no" << endl;
		cin >> n;
	}
}