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

//     sample preorder tree
//			10        //root
//		  /    \
//		 20    50
//		/ \     / 
//	   30  40  60

void preorder(node* root)
{
	if(root)
	{
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

node* preorderRoot()
{
	node* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(50);
	root->left->left = newNode(30);
	root->left->right = newNode(40);
	root->right->left = newNode(60);
	return root;
}


//     sample postorder tree
//			60        //root
//		  /    \
//		 30    50
//		/ \     / 
//	   10  20  40

void postorder(node* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->data);
	}
}

node* postorderRoot()
{
	node* root = newNode(60);
	root->left = newNode(30);
	root->right = newNode(50);
	root->left->left = newNode(10);
	root->left->right = newNode(20);
	root->right->left = newNode(40);
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

node* insertIterative(node* root, int item)
{ 
	node* newnode = newNode(item);
	if(root == NULL)
		return NULL;
	node* parent = NULL;
	node* current = root;
	while(current!=NULL)
	{	
		parent = current;

		if(item<= current->data)
			current = current->left;
		else
			current = current->right;
	}
	

	if(item<= parent->data)
		parent->left = newnode;

	else
		parent->right = newnode;
}

int main()
{
	

	node* root = newNode(25);
	root->left = newNode(15);
	root->right = newNode(35);
	root->left->left = newNode(10);
	root->left->right = newNode(20);
	root->right->left = newNode(30);
	

	insert(root,100);
	insert(root,4);
	insertIterative(root,39);
	
	inorder(root);
	cout<<"########"<<'\n';



	return 0;
}