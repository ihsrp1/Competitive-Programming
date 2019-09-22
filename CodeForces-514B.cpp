#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	map<long double, float> sts;
	ll n;
	
	cin >> n;
	
	float x0, y0, x, y;
	cin >> x0 >> y0;
	int k = 0;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		if(x == x0) {
			k = 1;
			continue;
		}
		long double m = (y-y0)/(x-x0);
		sts[m]++;
	}
	
	cout << sts.size()+k << endl;
	
	return 0;
}