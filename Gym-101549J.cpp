#include <bits/stdc++.h>

using namespace std;


int main()
{
    string line = "";
	string text = "";
	string longest = "";

	while(getline(cin, line)){
		text += line + " ";
	}

	int tam = text.length();

	int max_tam = 0;
	string temp = "";
	for(int i = 0; i < tam; i++){
		if(isalpha(text[i]) || text[i] == '-') {
			//cout << text[i] << " ";
			temp += text[i];
		}else{
			//cout << text[i] << " ";
			if(temp.length() > max_tam){
				max_tam = temp.length();
				longest = temp;
			}
			temp = "";
		}
	}

	for(int i = 0; i < longest.length(); i++){
		longest[i] = tolower(longest[i]);
	}

	cout << longest << endl;


	//cout << text << endl;
    

    return 0;
}