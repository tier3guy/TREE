#include<iostream>
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

int sumReplacement(node* root){
	if(root == NULL){
		return 0;
	}

	root->data += (sumReplacement(root->left) + sumReplacement(root->right));

	return root->data;
}

void preOrder(node* root){
	if(root == NULL){
		return;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(){

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

	preOrder(root);
	cout << "\n";
	sumReplacement(root);
	preOrder(root);

	return 0;
}