#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    int t;

    cin >> t;
    for(int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";

		int n, k = 0;
        cin >> n;
        vector<ll> rungs;

		rungs.push_back(0);
        for(int j = 1; j <= n; j++){
			ll temp;
			cin >> temp;
			rungs.push_back(temp);
		}
        for(int j = 1; j <= n; j++) {
            if(rungs[j]-rungs[j-1] > k) k = rungs[j]-rungs[j-1];
        }
        int resp = k;
        for(int j = 1; j <= n; j++) {
            if(rungs[j]-rungs[j-1] == k) k--;
            else if(rungs[j]-rungs[j-1] > k) {
                resp++;
                break;
            }
        }
        cout << resp << endl;
    }
    return 0;
}