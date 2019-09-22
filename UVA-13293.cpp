#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string, int> jogador;


string diminui(string a) {
	for (int i = 0; i < a.length(); i++)
		a[i] = tolower(a[i]);
	return a;
}

bool compStr(string a, string b){
	return diminui(a) < diminui(b);
}

bool comp(jogador a, jogador b){
	if(a.second != b.second){
		return a.second > b.second;
	}
	return compStr(a.first, b.first);
}

int main()
{
	char nome[21];
	char c;
	int temp, p, pontos = 0;
	int caso = 1;
	vector<jogador> jogadores;

	while(cin >> p){
		cout << "Case "  << caso << ":" << endl;
		caso++;
		
		for(int i = 0; i < p; i++){
			jogador novo;
			pontos = 0;
			scanf(" %[^;]", nome);
			cin >> c;
			for(int j = 0; j < 5; j++){
				for(int k = 0; k < 5; k++){
					cin >> temp;
					if(temp == 1){
						if(k == 4) pontos += 2;
						else pontos += 1;
					}
				}
				if(j < 4) cin >> c;
			}
			novo.first = nome;
			novo.second = pontos;
			jogadores.push_back(novo);
		}
		
		sort(jogadores.begin(), jogadores.end(), comp);

		for(int i = 0; i < p; i++){
			cout << jogadores[i].first << " " << jogadores[i].second << endl;
		}

		jogadores.clear();
	}

	
	
    return 0;
}