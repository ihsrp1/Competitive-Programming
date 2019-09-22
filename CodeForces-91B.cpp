#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    while(cin >> n){
        vector<pair<ll, ll>> v;
        vector<ll> displeasure(n, 0);
        for(int i = 0; i < n; i++){
            ll temp;
            cin >> temp;
            v.push_back({temp, i});
        }
        sort(v.begin(), v.end());
        ll temp = 0;
        for(int i = 0; i < n; i++){
            temp = max(v[i].second,temp);
            displeasure[v[i].second] = temp - v[i].second - 1;
        }

        for(int i = 0; i < n; i++){
            cout << displeasure[i] << " ";
        }
        cout << endl;

    }
    return 0;
}