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

int size(node* root)
{
	if(root == NULL)
		return 0;
	int left = size(root->left);
	int right = size(root->right);
	return left + right + 1;
}

int height(node* root)
{
	if(root == NULL)
		return 0;
	int left = height(root->left);
	int right = height(root->right);
	return max(left ,right) + 1;
}

int main()
{
	node* root = inorderRoot();
	
	inorder(root);
	cout<<"########"<<'\n';

	cout<<size(root)<<endl;
	cout<<height(root)<<endl;

	return 0;
}