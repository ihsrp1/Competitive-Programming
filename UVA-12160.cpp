#include <bits/stdc++.h>

using namespace std;

int dist[10000];
int b[15];

int main() {
    ios::sync_with_stdio(0);

    int l, u, r;
    int caso = 1;

    while (cin >> l >> u >> r && (l || u || r)) {
        for (int i = 0; i < r; ++i) {
            cin >> b[i];
        }
        queue<int> q;
        q.push(l);
        int ans = 0;
        memset(dist, -1, sizeof dist);
        dist[l] = 0;
        while (!q.empty()) {
            int at = q.front();
            q.pop();
            for (int i = 0; i < r; ++i) {
                int to = (at + b[i]) % 10000;
                if (dist[to] == -1) {
                    dist[to] = dist[at] + 1;
                    q.push(to);
                }
            }
        }
        cout << "Case " << caso++ << ": ";
        if (dist[u] == -1) cout << "Permanently Locked" << endl;
        else cout << dist[u] << endl;
    }

    return 0;
}