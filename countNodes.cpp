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

int countNodes(node* root){
	if(root == NULL){
		return 0;
	}
	int ans = 0;

	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node* temp = q.front();
		q.pop();
		ans++;
		if(temp->left != NULL){
			q.push(temp->left);
		}
		if(temp->right != NULL){
			q.push(temp->right);
		}
	}

	return ans;
}

int sumNodes(node* root){
	if(root == NULL){
		return 0;
	}
	int ans = 0;

	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node* temp = q.front();
		q.pop();
		ans += temp->data;
		if(temp->left != NULL){
			q.push(temp->left);
		}
		if(temp->right != NULL){
			q.push(temp->right);
		}
	}

	return ans;
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

	cout << countNodes(root) << endl;
	cout << sumNodes(root) << endl;
	
	return 0;
}