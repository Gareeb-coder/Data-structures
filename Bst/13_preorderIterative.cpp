#include "node.h"

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

void preorderIterative(node* root)
{
	if(!root) return;
	node* current = root;
	stack<node*> s;
	s.push(current);

	while(!s.empty())
	{
		current = s.top();
		s.pop();
		cout<<current->data<<endl;

		// Push right first, then left
		if(current->right)
			s.push(current->right);
		if(current->left)
			s.push(current->left);

	}
}

int main()
{

	preorder(preorderRoot());
	cout<<"########"<<'\n';

	preorderIterative(preorderRoot());
	cout<<"########"<<'\n';


	return 0;
}