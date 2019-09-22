#include <bits/stdc++.h>

double maximus(double a, double b){
	if (a > b) return a;
	else return b;
}


using namespace std;
int main(){
	vector<int> lanterns;
	int n, l;
	
	cin >> n >> l;
	
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		lanterns.push_back(temp);
	}
	
	sort(lanterns.begin(), lanterns.end());
	
	double maxi = 0;
	for(int i = 0; i < n-1; i++){
		if(lanterns[i+1] - lanterns[i] > maxi) maxi = lanterns[i+1] - lanterns[i];
	}
	double antigo = maxi;
	maxi = maximus(maximus(antigo/2, lanterns[0]), l - lanterns[n-1]);
	int a = floor(maxi);
	if(a == maxi) {
		cout << a << endl;
	}else{
		cout << a << "." << (maxi-a)*10 << endl;
	}
	
	return 0;
}