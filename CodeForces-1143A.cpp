#include <bits/stdc++.h>


using namespace std;
int main(){
	vector<int> entradas;
	int left = 0, right = 0;
	int n, temp;
	int portas = 0;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> temp;
		entradas.push_back(temp);
		if(temp == 1) right++;
		else left++;
	}
	
	
	for(int i = 0; i < n; i++){
		if(entradas[i] == 1) {
			right--;
		}
		else {
			left--;
		}
		
		portas++;
		if(right == 0) break;
		if(left == 0) break;
	}
	
	cout << portas << endl;
	return 0;
}