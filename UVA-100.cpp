#include <bits/stdc++.h>

using namespace std;


long long cycle(long long n){
	long long c = 0;
	while(n != 1){
		if(n%2 == 0){
			n /= 2;
		}else{
			n = n*3 + 1;
		}
		c++;
	}
	return c+1;
}

int main()
{
	long long i, j;
	while(cin >> i >> j){
		long long max = 0;
		if(i < j){
			for(long long x = i; x <= j; x++){
				long long value = cycle(x);
				if(value > max) max = value;
			}
		}else{
			for(long long x = j; x <= i; x++){
				long long value = cycle(x);
				if(value > max) max = value;
			}
		}
		
		cout << i << " " << j << " " << max << endl;
	}

    return 0;
}