#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n, divi;
int ans;
int s[N][N];
int linha[N][N], coluna[N][N];
int box[N][N];
// linha[x][y] = checa ocorrencia do numero Y na linha X
// box[x][y] = ocorrencia de 'y' na x-esima caixinha

int boxId(int x, int y) {
  int colunaMaior = y / divi;
  int linhaMaior = x / divi;
  return linhaMaior * divi + colunaMaior;  
}

void bt(int x, int y) {
  if (x == n - 1 && y == n) {
    ans = 1;
    return;
  }
  if (y == n) bt(x + 1, 0);
  else if (s[x][y] != 0) bt(x, y + 1);
  else {
    for (int i = 1; i <= 9; ++i) {
      if (linha[x][i]) continue;
      if (coluna[y][i]) continue;
      if (box[boxId(x, y)][i]) continue;
      s[x][y] = i;
      linha[x][i] = 1; coluna[y][i] = 1; box[boxId(x, y)][i] = 1;
      bt(x, y + 1);
      if (ans) return;
      s[x][y] = 0;
      linha[x][i] = 0; coluna[y][i] = 0; box[boxId(x, y)][i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int ja = 0;
  while (cin >> n) {
    ans = 0;
    divi = n;
    n *= n;
    memset(box, 0, sizeof box);
    memset(linha, 0, sizeof linha);
    memset(coluna, 0, sizeof coluna);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> s[i][j];
         if (s[i][j] != 0) {
          linha[i][s[i][j]] = coluna[j][s[i][j]] = box[boxId(i, j)][s[i][j]] = 1;
         }
      } 
    }
    bt(0, 0);
    if (!ja) ja = 1;
    else cout << endl;
    if (!ans) cout << "NO SOLUTION" << endl;
    else {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          cout << s[i][j] << " \n"[j == n - 1];
        }
      }
    }
  }
  return 0;
}