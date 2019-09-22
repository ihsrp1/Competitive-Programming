#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

typedef struct node {
	struct node* left, *right;
    unsigned long long int value;
	int height, leftSons, rightSons;
}node;

node * create_node(unsigned long long int e){
	node *r = (node *) malloc(sizeof(node));
	r->left = NULL;
	r->right = NULL;
	r->value = e;
    r->height = 1;
    r->leftSons = 0;
    r->rightSons = 0;
	return r;
}

int height(node *root){
	if(root == NULL) return 0;
    return root->height;
}

int getBalance(node *rt){
	if(rt == NULL) return 0;
	return height(rt->left) - height(rt->right);
}

node * rightRotate(node *rt){
	node* l = rt->left;
	node* lr = l->right;
    rt->leftSons = l->rightSons;
	l->right = rt;
	rt->left = lr;
	rt->height = max(height(rt->left), height(rt->right)) + 1;
	l->height = max(height(l->left), height(l->right)) + 1;
	l->rightSons = 1 + ((l->right)->rightSons) + ((l->right)->leftSons);
    return l;
}

node * leftRotate(node *rt){
	node *r = rt->right;
	node *rl = r->left;
    rt->rightSons = r->leftSons;
	r->left = rt;
	rt->right = rl;
	rt->height = max(height(rt->left), height(rt->right)) + 1;
	r->height = max(height(r->left), height(r->right)) + 1;
	r->leftSons = 1 + ((r->left)->rightSons) + ((r->left)->leftSons);
    return r;
}

node * insert_help(node *rt, unsigned long long int e){
	if (rt == NULL) return create_node(e);
	if (rt->value > e) {
        rt->leftSons = rt->leftSons + 1;
		rt->left = insert_help(rt->left, e);
	} else if (rt->value < e) {
        rt->rightSons += 1;
		rt->right = insert_help(rt->right, e);
    } else return rt;

    rt->height = 1 + max(height(rt->left), height(rt->right));

	int balance = getBalance(rt);
	if (balance > 1 && e < rt->left->value) return rightRotate(rt);
	if (balance < -1 && e >= rt->right->value) return leftRotate(rt);
	if (balance > 1 && e >= rt->left->value){
		rt->left = leftRotate(rt->left);
		return rightRotate(rt);
	}
	if (balance < -1 && e < rt->right->value){
		rt->right = rightRotate(rt->right);
		return leftRotate(rt);
	}
	return rt;
}

void busca(node* root, unsigned long long int val, int idx) {
    if (root == NULL) {
        printf("Data tidak ada\n");
        return;
    }

    if (val < root->value) {
        busca(root->left, val, idx);
    } else if (val > root->value) {
        busca(root->right, val, idx + 1 + root->leftSons);
    } else {
        printf("%d\n", idx + 1 + root->leftSons);
    }
}

int main (){
    node *avl = NULL;

	int n;
	scanf("%d", &n);

	int cmd, i;
    unsigned long long int e;
	for(i = 0; i < n; i++){
		scanf("%d %llu", &cmd, &e);
		if(cmd == 1){
			avl = insert_help(avl, e);
		}else{
			busca(avl, e, 0);
		}
	}

	return 0;
}