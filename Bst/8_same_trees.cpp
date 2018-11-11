#include "node.h"

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

bool isSame(node* root1, node* root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;

	return root1->data = root2->data &&
		   isSame(root1->left,root2->left) &&
		   isSame(root1->right,root2->right);
}


int main()
{
	

	node* root1 = newNode(25);
	root1->left = newNode(15);
	root1->right = newNode(35);
	root1->left->left = newNode(10);
	root1->left->right = newNode(20);
	root1->right->left = newNode(30);
	
	inorder(root1);
	cout<<"########"<<'\n';

	node* root2 = newNode(25);
	root2->left = newNode(15);
	root2->right = newNode(35);
	root2->left->left = newNode(10);
	root2->left->right = newNode(20);
	root2->right->left = newNode(30);
	
	inorder(root2);
	cout<<"########"<<'\n';

	cout<<isSame(root1,root2);

	return 0;
}