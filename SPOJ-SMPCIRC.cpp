#include <bits/stdc++.h>

using namespace std;


int main()
{
	int x1, x2, y1, y2, r1, r2;
	int t;

	cin >> t;

	while(t--){
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
		if(d < abs(r1-r2)*abs(r1-r2)){
			cout << "I" << endl;
		}else if(d == abs(r1-r2)*abs(r1-r2)){
			cout << "E" << endl;
		}else{
			cout << "O" << endl;
		}
	}

    return 0;
}