#include <bits/stdc++.h>

using namespace std; 

typedef struct node{ 
	int value; 
	struct node *left;
	struct node *right; 
}node; 
  

node* createNode(int value){ 
	node *temp = new node; 
	temp->value = value; 
	temp->left = NULL;
	temp->right = NULL; 
	return temp; 
} 

int search(int vet[], int start, int end, int value){ 
	for (int i = start; i <= end; i++){ 
		if(vet[i] == value)
			return i; 
	} 
} 

int j = 0;

node* construct(int in[], int pre[], int start, int end){
	if(start > end) 
		return NULL; 

	node *temp = createNode(pre[j++]); 

	if (start == end) 
		return temp; 

	int k = search(in, start, end, temp->value); 


	temp->left = construct(in, pre, start, k-1); 
	temp->right = construct(in, pre, k+1, end); 

	return temp; 
} 
  

int checkPost(node* node, int post[], int k){ 
	if (node == NULL) 
		return k; 

	k = checkPost(node->left, post, k); 
	k = checkPost(node->right, post, k);
	
	if (node->value == post[k]) 
		k++; 
	else
		return -1; 

	return k; 
}
  

int main(){ 
	int in[8000]; 
	int pre[8000]; 
	int post[8000]; 
  
	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> pre[i];
	}
	for(int i = 0; i < n; i++){
		cin >> post[i];
	}
	for(int i = 0; i < n; i++){
		cin >> in[i];
	}

	node *root = construct(in, pre, 0, n - 1); 
  

	int k = checkPost(root, post, 0); 
	(k == n) ? cout << "yes" : cout << "no";
  
	return 0; 
} 