#include <iostream>
#include <stdio.h>
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

int height(node* root)
{
	if(root == NULL)
		{return -1;}
	int leftHeight = height(root->left) +1;
	int rightHeight = height(root->right) +1;
	return max(leftHeight,rightHeight);
}

int findMin(node* root)
{
	node* current = root;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current->data;
}

int findMax(node* root)
{
	node* current = root;
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current->data;
}

void print(node* root)
{
	cout<<root->data<<endl;
    node* current = root;
    while(root!=NULL)
    {
    	print(current->left);
    	print(current->right);
    }
}

int main()
{
	inorder(inorderRoot());
	cout<<"########"<<'\n';
	preorder(preorderRoot());
	cout<<"########"<<'\n';
	postorder(postorderRoot());
	cout<<"########"<<'\n';

	node* root = newNode(25);
	root->left = newNode(15);
	root->right = newNode(35);
	root->left->left = newNode(10);
	root->left->right = newNode(20);
	root->right->left = newNode(30);


	insert(root,100);
	insert(root,4);
	insert(root,35);

	inorder(root);
	cout<<"########"<<'\n';

	cout<<height(root)<<endl;

	cout<<findMin(root)<<endl;
	cout<<findMax(root)<<endl;
	cout<<max(2,2);
	print(root);

	return 0;
}
