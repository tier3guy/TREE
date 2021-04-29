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

node* buildTree(int pre[] , int in[] , int st , int end ,int &key){
	int element = pre[key];
	key++;
	node* root = new node(element);
	if(st == end ){
		return root;
	}
	int pos =0;
	for(int i =st;i<=end;i++){
		if(in[i] == element){
			pos = i;	
			root->left = buildTree(pre,in,st,pos-1,key);
			root->right = buildTree(pre,in,pos+1,end,key);
			break;
		}
	}


	return root;
}

void postOrder(node* root){
	if(root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

int main(){

	/*node* root = new node(1);
	root->left = new node(2);
	root->right = new node(2);
	root->left->left = new node(2);
	root->left->right = new node(2);
	root->right->left = new node(2);
	root->left = new node(2);
	root->left = new node(2);*/

	int pre[] = {1,2,4,5,3,6,7};
	int in[] = {4,2,5,1,6,3,7};

	int key = 0;
	node* root = buildTree(pre,in,0,6,key);
	postOrder(root);

	return 0;
}