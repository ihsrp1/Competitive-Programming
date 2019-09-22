#include <bits/stdc++.h>

using namespace std;


int main()
{
	int w, h, x = 1;
	cin >> w >> h;

	for(int i = 0; i < w; i++){
		x = (x*2) % 998244353;
	}
	for(int i = 0; i < h; i++){
		x = (x*2) % 998244353;
	}
	
	cout << x << endl;

    return 0;
}