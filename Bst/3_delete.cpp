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

node* findMin(node* root)
{
	node* current = root;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

node* Delete(node* root,int item)
{
	if(root == NULL) return root;
	else if(item < root->data)
		root->left = Delete(root->left,item);
	else if(item > root->data)
		root->right = Delete(root->right,item);
	else
	{
		// case 1: no child
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			return root;
		}

		// case 2: one child
		else if(root->left == NULL)
		{
			node* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if(root->right == NULL)
		{
			node* temp = root;
			root = root->left;
			delete temp;
			return root;
		}

		// case 3: two child
  		else
  		{
  			node* temp = findMin(root->right);
  			root->data = temp->data;
  			root->right = Delete(root->right,temp->data);
  		}

	}
	return root;
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
	root->left->right->left = newNode(18);
	root->left->right->right = newNode(22);
	root->right->left = newNode(30);

	inorder(root);
	cout<<"########"<<'\n';

    root =  Delete(root,15);

	inorder(root);
	cout<<"########"<<'\n';

	return 0;
}

//     sample inorder tree
//			25        //root
//		  /    \
//		 15      35
//		/ \     /
//	   10  20  30
