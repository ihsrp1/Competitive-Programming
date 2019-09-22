#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	stack<char> letras;

	cin >> s;

	int jogadas = 0;
	int i = 0, tam = s.length();

	for(i = 0; i < tam; i++){
		if(letras.size() == 0){
			letras.push(s[i]);
		}else{
			if(s[i] == letras.top()){
				jogadas++;
				letras.pop();
			}else{
				letras.push(s[i]);
			}
		}
	}
	
	
	if(jogadas % 2 == 0) printf("No\n");
	else printf("Yes\n");
    return 0;
}