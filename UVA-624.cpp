#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll total, n;
vector<ll> setl;
ll maskresp, nearestTotal;

void verif(int atual, int mask, int p) {
	if (atual > total)
		return;
	if (atual > nearestTotal) {
		nearestTotal = atual;
		maskresp = mask;
	}
	if (p >= n)
		return;

	verif(atual + setl[p], mask | (1 << p), p + 1);
	verif(atual, mask, p + 1);
}

int main() {
	while (cin >> total >> n) {
		setl.clear();
		for (int i = 0; i < n; i++) {
			ll temp;
			cin >> temp;
			setl.push_back(temp);
			
		}

		maskresp = -1;
		nearestTotal = -1;
		verif(0, 0, 0);

		for (int i = 0; i < n; i++) {
			if ((maskresp >> i) % 2)
				printf("%lld ", setl[i]);
		}
		printf("sum:%lld\n", nearestTotal);
	}

	return 0;
}