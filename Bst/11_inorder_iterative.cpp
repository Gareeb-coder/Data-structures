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

void inorderIter(node* root)
{
	stack<node*> s;
	s.push(root);
	node* current = root;
	while(true)
	{
		if(current!=NULL)
		{
			s.push(current);
			current = current->left;
		}
		else
		{	if(s.empty()){break;}
			current = s.top();
			cout<<current->data<<endl;
			s.pop();
			current = current->right;
		}
	}
}


int main()
{
	inorder(inorderRoot());
	cout<<"########"<<'\n';

	inorderIter(inorderRoot());

   

	return 0;
}