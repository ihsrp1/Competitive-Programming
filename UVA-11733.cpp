#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

//const int max = 1e8;

vector<pair<int,pii>> edges;
vi ancestral;
vi indexes;
int ans = 0;
int airports = 0;
int t, n, m, a;
int x, y, c;
int first;

int find(int x){
	if(x == ancestral[x]) return x;
	return ancestral[x] = find(ancestral[ancestral[x]]);
}

void unite(int x, int y){
	int px = find(x);
	int py = find(y);
	ancestral[px] = py;
}

void kruskal(int k){
	long long aeroportos = n;
	long long custo = 0;
	sort(edges.begin(), edges.end());
	for(int i = 0; i < edges.size(); i++){
		if (edges[i].first >= a) continue;
		int from = edges[i].second.first;
		int to = edges[i].second.second;
		if(find(from) != find(to)){
			unite(from, to);
			aeroportos--;
			custo += edges[i].first;
		}
	}
	cout << "Case #" << k+1 << ": " << custo + aeroportos * a << " " << aeroportos << endl;
}



int main (){
	ios::sync_with_stdio(0); cin.tie(nullptr);
	

	cin >> t;

	for(int k = 0; k < t; k++){
		first = 1;
		ans = 0;
		airports = 0;
		edges.clear();
		ancestral.clear();
		indexes.clear();

		cin >> n >> m >> a;

		ancestral.resize(n+1);


		for(int i = 0; i < n; i++){
			ancestral[i] = i;
		}

		for(int i = 0; i < m; i++){
			cin >> x >> y >> c;
			edges.push_back({c, {x-1, y-1}});
		}

		kruskal(k);
	}

	return 0;
}