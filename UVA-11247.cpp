#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    long long m, x;
    while(cin >> m >> x) {
		if(m == 0 && x == 0) break;

		double tax = x/100.0;
        if (m == 1 || x == 0 || x == 100) {
            cout << "Not found" << endl;
            continue;
        }
        long long maximum = (m - 1) * 100 / (100 - x);
        if ((m-1)*100 % (100-x) == 0) maximum--;
        if(maximum < m) cout << "Not found\n";
        else cout << maximum << endl;

    }
    return 0;
}