#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	deque<int> jobs;
	
	int n;
	int reverse = 1;
	
	scanf("%d", &n);
	char s[50];
	for(int i = 0; i < n; i++){
		scanf(" %s", s);
		if(reverse == 1){
			if(s[0] == 'f'){
				if(jobs.empty()) printf("No job for Ada?\n");
				else{
					printf("%d\n", jobs.front());
					//cout << jobs.front() << endl;
					jobs.pop_front();
				}
			}else if(s[0] == 'b'){
				if(jobs.empty()) printf("No job for Ada?\n");
				else{
					printf("%d\n", jobs.back());
					//cout << jobs.back() << endl;
					jobs.pop_back();
				}
			}else if(s[0] == 't'){
				int temp;
				scanf("%d", &temp);
				jobs.push_front(temp);
			}else if(s[0] == 'p'){
				int temp;
				scanf("%d", &temp);
				jobs.push_back(temp);
			}else{
				reverse = 0;
			}
		}else{
			if(s[0] == 'f'){
				if(jobs.empty()) printf("No job for Ada?\n");
				else{
					printf("%d\n", jobs.back());
					//cout << jobs.front() << endl;
					jobs.pop_back();
				}
			}else if(s[0] == 'b'){
				if(jobs.empty()) printf("No job for Ada?\n");
				else{
					printf("%d\n", jobs.front());
					//cout << jobs.back() << endl;
					jobs.pop_front();
				}
			}else if(s[0] == 't'){
				int temp;
				scanf("%d", &temp);
				jobs.push_back(temp);
			}else if(s[0] == 'p'){
				int temp;
				scanf("%d", &temp);
				jobs.push_front(temp);
			}else{
				reverse = 1;
			}
		}
	}
	
	return 0;
}