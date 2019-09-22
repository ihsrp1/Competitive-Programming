#include <bits/stdc++.h>


using namespace std;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
int n, c = 0;
vector<int> resp(20, 1);

bool isPrime(int x){
    for (int p : primes)
        if (p == x) return true;
    return false;
}
void backtracking(int l, vector<bool> visitados)
{
    if (l == n) {
        if (!isPrime(resp[n-1] + 1))
            return;
        cout << "1";
        for (int i = 1; i < n; i++)
            cout << " " << resp[i];
        cout << endl;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (visitados[i]) continue;
        if (isPrime(i + resp[l - 1])) {
            visitados[i] = 1;
            resp[l] = i;

            backtracking(l + 1, visitados);

            visitados[i] = 0;
        }
    }
}
int main()
{
    while (cin >> n) {
        if (c++) cout << endl;
        cout << "Case " << c << ":\n";
        vector<bool> visitados(20, 0);
        backtracking(1, visitados);
    }
}