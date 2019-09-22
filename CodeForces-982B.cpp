#include<bits/stdc++.h>

using namespace std;
 


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> rows;
    stack<int> st;
    for(int i = 0; i < n; i++){
    	int temp;
    	cin >> temp;
    	rows.push_back({temp, i+1});
    }
    sort(rows.begin(), rows.end());
    int k = 0;
    for(int i = 0; i < 2*n; i++){
    	char c;
    	cin >> c;
    	if(c == '0'){
    		cout << rows[k].second << " ";
    		st.push(rows[k].second);
    		k++;
    	}else{
    		cout << st.top() << " ";
    		st.pop();
    	
    	}
    }
    cout << endl;
}