#include<iostream>
#include<queue>
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

int heightofTree(node* root){
	if(root == NULL){
		return 0;
	}
	
	int leftHeight = heightofTree(root->left);
	int rightHeight = heightofTree(root->right);

	return (max(leftHeight,rightHeight) + 1);
}

int diameterofTree(node* root){
	if(root == NULL){
		return 0;
	}
	
	int lh = heightofTree(root->left);
	int rh = heightofTree(root->right);

	int currH = lh + rh + 1;

	int ld = diameterofTree(root->left);
	int rd = diameterofTree(root->right);

	return max(currH , max(ld,rd));
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->left->right->left = new node(9);
	root->left->right->left->right = new node(11);
	root->right->left = new node(6);
	root->right->left->right = new node(10);
	root->right->right = new node(7);
	root->right->right->right = new node(8);

	cout << diameterofTree(root) << endl;

	return 0;
}