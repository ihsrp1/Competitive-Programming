#include <bits/stdc++.h>

#define MAX 10005

using namespace std;

typedef pair<int, int> pii;

const int inf = 1e9 + 5;

int V, E;
int x, y;


vector<pii> adj[MAX];
int dist[MAX];

void dijkstra() {
	for (int i = 0; i <= V; ++i) {
		dist[i] = inf;
	}
	dist[x] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> h;
	h.push({0, x});
	while (!h.empty()) {
		pii topo = h.top(); h.pop();
		int vertice = topo.second;
		int distancia = topo.first;
		if (distancia > dist[vertice]) continue;
		for (int i = 0; i < adj[vertice].size(); ++i) {
			int proximo = adj[vertice][i].first;
			int peso = adj[vertice][i].second;
			if (dist[proximo] > dist[vertice] + peso) {
				dist[proximo] = dist[vertice] + peso;
				h.push({dist[proximo], proximo});
			}
		}
	}
} 
   
 
int main() {
	ios::sync_with_stdio(0); cin.tie(nullptr); 
	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> V >> E;

		for(int j = 0; j <= V; j++){
			adj[j].clear();
		}
		
		for(int j = 0; j < E; j++){
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({b, c});
		}

		cin >> x >> y;

		dijkstra();

		if (dist[y] == inf) cout << "NO" << endl;
		else cout << dist[y] << endl;
	}
   
	return 0; 
} 