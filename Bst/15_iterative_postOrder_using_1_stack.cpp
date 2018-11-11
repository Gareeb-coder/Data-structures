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

void postorderIterative1Stack(node* root)
{
	stack<node*> s;
	node* current = root;

	while(current || !s.empty())
	{
		if(current)
		{
			s.push(current);
			current = current->left;
		}
		else
		{
			if(s.top()->right)
				current = s.top()->right;
			else
			{   
				node* temp = s.top();
				cout<<s.top()->data<<endl;
				s.pop();
				while(!s.empty() && temp==s.top()->right)
				{   
					
					temp = s.top();
					cout<<temp->data<<endl;
					s.pop();
				 
				}
			}
		}
	}
}


int main()
{

	postorder(postorderRoot());
	cout<<"########"<<'\n';

	postorderIterative1Stack(postorderRoot());

	return 0;
}