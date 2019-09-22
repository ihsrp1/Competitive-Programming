#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int n, a[N], cs[N];

int procura(string s, char c){
	int i;
	int tam = s.length();
	for(i = 0; i < tam; i++){
		if(s[i] == c) return i;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		stack<char> pilha;
		queue<char> fila; 
		string s;
		cin >> s;
		int tam = s.length();
		string ops ("+-*/^");
		for(int j = 0; j < tam; j++){
			if(isalpha(s[j])){
				fila.push(s[j]);
			}else if(s[j] == '('){
				pilha.push(s[j]);
			}else if(s[j] == ')'){
				while(pilha.top() != '('){
					fila.push(pilha.top());
					pilha.pop();
				}
				pilha.pop();
			}else{
				//cout << s[j] << " " << pilha.top() << endl;
				//cout << procura(ops, s[j]) << " " << procura(ops, pilha.top()) << endl;
				if(procura(ops, s[j]) < procura(ops, pilha.top())){
					fila.push(pilha.top());
					pilha.pop();
					pilha.push(s[j]);
				}else{
					//cout << "to entrando nesse carai " << s[j] << endl;
					pilha.push(s[j]);
				}
			}
			//cout << "Para " << s[j] << ":\n";
			//if(!fila.empty()) cout << "Fila: " << fila.back() << endl;
			//if(!pilha.empty()) cout << "Pilha: " <<pilha.top() << endl << endl;
		}
		while(!fila.empty()){
			cout << fila.front();
			fila.pop();
		}
		cout << endl;
	}
	
	return 0;
}