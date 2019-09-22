#include <stdio.h>
#include <stdlib.h>


typedef struct bst{
    int val;
    struct bst *left;
    struct bst *right;
}bst;

bst * bst_insert(bst *root, int v){
	if(root == NULL){
		bst *n = (bst *) malloc(sizeof(bst));
		n->val = v;
		n->left = NULL;
		n->right = NULL;
		return n;
	}else if(v < root-> val){
		root->left = bst_insert(root->left, v);
		return root;
	}else{
		root->right = bst_insert(root->right, v);
		return root;
	}
}

void post_order(bst *root){
    if(root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d\n", root->val);
}


int main(){
    bst *root = NULL;
    int temp;

    while(scanf("%d", &temp) != EOF){
        root = bst_insert(root, temp);
    }

    post_order(root);
    return 0;
}