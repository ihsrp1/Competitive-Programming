#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double pi = 3.14159265358979323846;



int main() {
	int p, q, r, s, t, u;
	int solved = 0;
	double mini, maxi, med, f;
	
	while(cin >> p >> q >> r >> s >> t >> u){
		mini = 0;
		maxi = 1;
		if(p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u > 1e-9 || p+r+u<0){
            cout << "No solution" << endl;
            continue;
        }
		for(int i = 0; i < 1000; i++){
			//cout << mini << " " << maxi << endl;
			med = (mini+maxi)/2;
			f=p*exp(-med)+q*sin(med)+r*cos(med)+s*tan(med)+t*med*med+u;
			
			//cout << f << endl;
			if(f > 0) mini = med;
			else if(f < 0) maxi = med;
			else{
				break;
			}
		}
		printf("%.4f\n", mini);

	}
	
	
	
	return 0;
}