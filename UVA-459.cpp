#include<bits/stdc++.h>
#define MAXN 300
#define L 1000
using namespace std;



typedef struct{
    int matrix[MAXN][MAXN];
    int numEdge;
    int mark[MAXN];
}G;

int n;
queue<int> q;

G create_graph(){
	G graph;
	memset(graph.matrix, 0, sizeof(graph.matrix));
	graph.numEdge = 0;
	memset(graph.mark, 0, sizeof(graph.mark));
	return graph;
}


int first(G g, int v){
	for(int i = 0; i < n; i++){
		if(g.matrix[v][i] != 0) return i;
	}
	return n;
}

int next(G g, int v, int w){
	for(int i = w+1; i < n; i++){
		if(g.matrix[v][i] != 0) return i;
	}
	return n;
}

int deq(){
	int i = q.front();
	q.pop();
	return i;
}


void BFS(G *g, int start){
	q = queue<int>();
	q.push(start);
	g->mark[start] = 1;
	while(q.size() > 0){
		int v = deq();
		int w = first(*g, v);
		while(w < n){
			if(g->mark[w] == 0){
				g->mark[w] = 1;
				q.push(w);
			}
			w = next(*g, v, w);
		}
	}
}

int graphTraverse(G g){
	int resp = 0;
	for (int v = 0; v < n; v++){
		g.mark[v] = 0;
	}
	
	for(int v = 0; v < n; v++){
		if(g.mark[v] == 0){
			resp++;
			BFS(&g, v);
		}
	}
	return resp;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr);

	int t;
	char c;
	string arestas;

	cin >> t; cin.ignore();

	getline(cin, arestas);

	for(int i = 0; i < t; i++){
		G graph = create_graph();
		cin >> c; cin.ignore();
		n = c - 'A' + 1;
		while(getline(cin, arestas) && arestas != ""){
			int u = arestas[0] - 'A';
			int v = arestas[1] - 'A';
			graph.matrix[u][v] = 1;
			graph.matrix[v][u] = 1;
		}
		
		cout << graphTraverse(graph) << endl;
		if(i != t - 1) cout << endl;
	}

	

    return 0 ;
}