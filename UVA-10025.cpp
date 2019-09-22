#include <bits/stdc++.h>

using namespace std;


int main()
{
	int tests;
	cin >> tests;
	while(tests--){
		int n;
		cin >> n;
		int soma = 0, i;
		n = abs(n);
		if(n == 0) {
			cout << "3" << endl;
			if(tests - 1 >= 0) cout << endl;
			continue;
		}
		for (i = 0; soma < n; i++){
			soma += i;
		}
		i--;
		while ((soma - n) % 2){
			i++;
			soma += i;
		}

		cout << i << endl;
		if(tests - 1 >= 0) cout << endl;
	}
	
    return 0;
}