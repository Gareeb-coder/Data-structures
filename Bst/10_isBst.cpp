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

//     sample inorder tree
//			25        //root
//		  /    \
//		 15      35
//		/ \     / 
//	   10  20  30

void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\n",root->data );
		inorder(root->right);
	}
}

node* inorderRoot()
{
	node* root = newNode(25);
	root->left = newNode(15);
	root->right = newNode(35);
	root->left->left = newNode(10);
	root->left->right = newNode(20);
	root->right->left = newNode(30);
	return root;
}


node* insert(node* root, int data)
{
	if(root == NULL)
		return newNode(data);
	else
	{
		if(data<=root->data)
			root->left = insert(root->left,data);
		else
			root->right = insert(root->right,data);
		return root;
	}
}

bool isBstUtil(node* root, int min, int max)
{
	if(root == NULL) 
		return true;
	if(root->data > min 
	   && root->data < max
	   && isBstUtil(root->left,min,root->data)
	   && isBstUtil(root->right,root->data,max))
		return true;
	else
		return false;
}

bool isBst(node* root)
{
	return isBstUtil(root,INT_MIN,INT_MAX);
}

bool isPresent(node* root,int item)
{
	node* current = root;
	while(current!=NULL)
	{
		if(item == current->data)
			return true;
		else if(item < current->data)
			current = current->left;
		else
			current = current->right;
	}
}

int main()
{
	inorder(inorderRoot());
	cout<<"########"<<'\n';

	node* root = newNode(25);
	root->left = newNode(15);
	root->right = newNode(35);
	root->left->left = newNode(10);
	root->left->right = newNode(20);
	root->right->left = newNode(30);
	// root->right->left->left = newNode(3);

	cout<<isBst(root)<<endl;
	cout<<"########"<<'\n';
	cout<<isPresent(root,30)<<endl;


	return 0;
}

//     sample inorder tree
//			25        //root
//		  /    \
//		 15      35
//		/ \     / 
//	   10  20  30