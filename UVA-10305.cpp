#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const int N = 1234;

vector<int> adj[N];
int deg[N];
queue<int> q;
vector<int> ans;

void init() {
	for (int i = 0; i < N; ++i) {
		adj[i].clear();
		deg[i] = 0;
	}
	q = queue<int>();
}

void solve() {
	ans.clear();
	while (!q.empty()) {
		int p = q.front(); q.pop();
		ans.pb(p);
		for (int u : adj[p]) {
			deg[u]--;
			if (deg[u] == 0) {
				q.push(u);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	
	int n, m;
	
	while (cin >> n >> m && (n || m)) {
		init();
		for (int i = 0; i < m; ++i) {
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			deg[y]++;
		}
		for (int i = 1; i <= n; ++i) {
			if (!deg[i]) {
				q.push(i);
			}
		}
		solve();
		for (int i = 0; i < n; ++i) {
			cout << ans[i] << " \n"[n - i == 1];
		}
	}

	return 0;
}