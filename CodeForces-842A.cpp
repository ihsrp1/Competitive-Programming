#include <bits/stdc++.h>


using namespace std;
int main(){
	int x, y, l, r;
	double k;
	
	cin >> l >> r >> x >> y >> k;
	
	if (k*x > r || k*y < l) {
		cout << "NO" << endl;
		return 0;
	}
	
	for (int i = l; i <= r; i++){
		for(int j = x; j <= y; j++){
			if (j*k == i){
				 cout << "YES" << endl;
				 return 0;
			}
			else if(j*k > i) break;
		}
	}
	cout << "NO" << endl;
	return 0;
}