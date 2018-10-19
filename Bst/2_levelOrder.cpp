#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;

};

node* newNode(int data)
{
	node* newnode  = new node;

	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return(newnode);
}

//     sample levelOrder tree
//			25        //root
//		  /    \
//		 15      35
//		/ \     /
//	   10  20  30
// level order - 25, 15,35, 10,20,30

node* levelOrderTree()
{
	node* root = newNode(25);
	root->left = newNode(15);
	root->right = newNode(35);
	root->left->left = newNode(10);
	root->left->right = newNode(20);
	root->right->left = newNode(30);
	// root->right->left->left = newNode(3);
	return root;
}

void levelOrder(node* root)
{
	if(root == NULL)return;

	queue<node*> Q;
	node* current  = root;

	Q.push(current);
	while(!Q.empty())
	{
		current = Q.front();
		cout<<current->data<<endl;
		Q.pop();

		if(current->left)
		{
			Q.push(current->left);
		}
		if(current->right)
		{
			Q.push(current->right);
		}

	}
}


int main()
{
	levelOrder(levelOrderTree());
	cout<<"########"<<'\n';

	return 0;
}
