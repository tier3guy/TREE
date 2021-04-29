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

node* buildTree(int post[],int in[],int st,int end,int &key){
	int element = post[key];
	key--;
	node* root = new node(element);
	if(st == end){
		return root;
	}
	for(int i =st ;i<=end;i++){
		if(in[i] == element){
			root->right = buildTree(post,in,i+1,end,key);
			root->left = buildTree(post,in,st,i-1,key);
		}
	}
	return root;
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

	int post[] = {4, 5, 2, 6, 7, 3, 1 };
	int in[] = {4 ,2, 5, 1, 6, 3, 7};

	int key = 6;
	node* root = buildTree(post,in,0,6,key);
	preOrder(root);

	return 0;
}