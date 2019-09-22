#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int N = 52;

int h, w;
int dp[N][N];
char grid[N][N];

int dx[] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int dy[] = { 1, -1, 0, 1, -1, 0, 1, -1 };

int solve(int x, int y) {
    int &ret = dp[x][y];
    if (~ret) return ret;
    ret = 0;
    for (int i = 0; i < 8; ++i) {
        int px = x + dx[i];
        int py = y + dy[i];
        if (px >= 0 && py >= 0 && px < h && py < w && grid[px][py] == grid[x][y] + 1) {
            ret = max(ret, solve(px, py) + 1);
        }
    }
    return ret;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr);
    
    int caso = 1;

    while (cin >> h >> w && (h || w)) {
        memset(dp, -1, sizeof dp);
        cout << "Case " << caso++ << ": ";
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == 'A') {
                    ans = max(ans, solve(i, j) + 1);
                }
            }
        }
        cout << ans << endl;
    }
	
	return 0;
}