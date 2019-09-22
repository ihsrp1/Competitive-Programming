#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const ll MOD = 1001;
const ll B = 23;

ll pot[34];
string nome[1000];
ll pontos[1000];
pair<string, ll> table[1001];
bool venc[1001];

void pre() {
	pot[0] = 1;

	for (int i = 1; i < 34; ++i) {
		pot[i] = (pot[i - 1] * B) % MOD;
	}
}

ll mh(string z) {
	ll id = 0;

	for (int i = 0; z[i] != '\0'; ++i) {
		ll x = (pot[i] * (z[i] - 'a')) % MOD;
		id = (id + x) % MOD;
	}

	return id;
}

int main (){
	ios::sync_with_stdio(0); cin.tie(nullptr);
	pre();

	int n; cin >> n;

	for (int i = 0; i < MOD; ++i) {
		table[i] = make_pair("", -1);
	}

	for (int i = 0; i < n; ++i) {
		cin >> nome[i] >> pontos[i];

		ll hID = mh(nome[i]);

		while (table[hID].first != "" && table[hID].first != nome[i]) {
			hID++;
			hID %= MOD;
		}

		if (table[hID].first == "") {
			table[hID] = make_pair(nome[i], pontos[i]);
		} else {
			table[hID].second += pontos[i];
		}
	}

	ll ans = INT_MIN;

	for (int i = 0; i < MOD; ++i) {
		if (table[i].first != "") {
			ans = max(ans, table[i].second);
		}
	}

	int cnt = 0;

	for (int i = 0; i < MOD; ++i) {
		if (table[i].first != "") {
			if (table[i].second == ans) {
				venc[i] = 1;
				++cnt;
			}
		}
	}

	if (cnt == 1) {
		for (int i = 0; i < MOD; ++i) {
			if (table[i].second == ans) {
				cout << table[i].first << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < MOD; ++i) {
		table[i] = make_pair("", -1);
	}

	for (int i = 0; i < n; ++i) {
		ll hID = mh(nome[i]);

		while (table[hID].first != "" && table[hID].first != nome[i]) {
			hID++;
			hID %= MOD;
		}

		if (table[hID].first == "") {
			table[hID] = make_pair(nome[i], pontos[i]);
		} else {
			table[hID].second += pontos[i];
		}

		if (table[hID].second >= ans && venc[hID]) {
			cout << table[hID].first << endl;
			return 0;
		}
	}

	return 0;
}