#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int c, l, m, side, viagens, soma;
    queue<int> left, right;
    scanf("%d", &c);
    while(c--) {
        scanf("%d %d", &l, &m);
        l = l*100;
        
        int temp;
        char s[50];
        while(m--) {
            scanf("%d %s", &temp, s);
            if(s[0] == 'l')
                left.push(temp);
            else
                right.push(temp);
        }
        side = 0, viagens = 0;
        while(!left.empty() || !right.empty()) {
            viagens++;
            soma = 0;
            if(side == 1) {
                while(!right.empty() && soma + right.front() <= l)
                    soma += right.front(), right.pop();
            } else {
                while(!left.empty() && soma + left.front() <= l)
                    soma += left.front(), left.pop();
            }
            side = !side;
        }
        printf("%d\n", viagens);
    }
    return 0;
}