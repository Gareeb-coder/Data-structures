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

node* find(node* root, int item)
{	
	node* current = root;
	while(current->data!=item && current!=NULL)
	{
		if(item < current->data)
			current = current->left;
		else
			current = current->right;
	}
	if(current->data == item)
		return current;
	else
		return NULL;
}

node* search(node* root, int item)
{
	if(root == NULL || root->data == item)
		return root;
	if(item < root->data)
		return search(root->left,item);
	else
		return search(root->right,item);
}
//     sample inorder tree
//			25        //root
//		  /    \
//		 15      35
//		/ \     / 
//	   10  20  30

node* getSuccessor(node* root, int item)
{
	node* current = find(root,item);
	if(current == NULL) return NULL;
	// node has right sub tree
	if(current->right != NULL)
		return findMin(current->right);
	else //node has no right sub tree
	{
		node* successor = NULL;
		node* ancestor = root;
		while(ancestor != current)
		{
			if(current->data < ancestor->data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
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
	root->left->right->left = newNode(18);
	root->left->right->right = newNode(22);
	root->right->left = newNode(30);
		
	inorder(root);
	cout<<"########"<<'\n';
	node* f = find(root,30);
	cout<<f->data<<endl;

	node* s = getSuccessor(root,20);
	cout<<s->data<<endl;


    
    

	return 0;
}

//     sample inorder tree
//			25        //root
//		  /    \
//		 15     35
//		/ \     / 
//	   10  20  30
//        /  \ 
//       18  22