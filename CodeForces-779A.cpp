#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    map<int, int> A, B;

    int n;
    cin >> n;
    for(int i = 1; i <= 5; i++){
        A[i] = 0;
        B[i] = 0;
    }

    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        A[temp]++;
    }
    for(int i = 0; i < n; i++){
        cin >> temp;
        B[temp]++;
    }

    int mudancas = 0;
    for(int i = 1; i <= 5; i++){
        if((A[i] + B[i])%2 == 0){
            if(A[i] == B[i]) {
                continue;
            }
            else{
                mudancas += abs(A[i] - B[i])/2;
            }
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    cout << mudancas/2 << endl;

    return 0;
}