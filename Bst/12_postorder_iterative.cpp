#include "node.h"

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

void postorderIterative(node* root)
{
	if(root == NULL)
		return;
	stack<node*> s1;
	stack<node*> s2;
	node* current = root;
	s1.push(current);

	// Forming stack s2
	while(!s1.empty())
	{
		current = s1.top();
		s1.pop();
		s2.push(current);
		if(current->left)
			s1.push(current->left);
		if(current->right)
			s1.push(current->right);
	}

	// Printing stack s2
	while(!s2.empty())
	{
		current = s2.top();
		cout<<current->data<<endl;
		s2.pop();
	}
}


int main()
{

	postorder(postorderRoot());
	cout<<"########"<<'\n';

	postorderIterative(postorderRoot());

	return 0;
}