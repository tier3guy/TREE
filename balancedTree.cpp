#include<iostream>
#include<cmath>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

int height(node* root){
	if(root == NULL){
		return 0;
	}

	int lh = height(root->left);
	int rh = height(root->right);


	return (max(lh,rh)+1);
}

bool balancedTree(node* root){
	if(root == NULL){
		return true;
	}

	bool ans = false;
	int lh = height(root->left);
	int rh = height(root->right);

	if(abs(lh-rh) <= 1){
		ans = true;
	}

	return (ans && balancedTree(root->left) && balancedTree(root->right));

}
int main(){

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->right->right->right = new node(8);
	root->right->right->right->right = new node(9);

	cout << balancedTree(root) << endl;

	return 0;
}