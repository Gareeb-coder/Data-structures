#include <iostream>
#include <stack>
#include <deque>
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


//     sample postorder tree
//			10        //root
//		  /    \
//		 30    20
//		/ \    / 
//	   40  50 60


node* spiralRoot()
{
	node* root = newNode(10);
	root->left = newNode(30);
	root->right = newNode(20);
	root->left->left = newNode(40);
	root->left->right = newNode(50);
	root->right->left = newNode(60);
	return root;
}

// This techqnique uses two stacks.
void spiral1(node* root)
{
	if(!root) return;
	stack<node*> s1;
	stack<node*> s2;
	node* current = root;
	s1.push(current);

	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			current = s1.top();
			cout<<current->data<<endl;
			s1.pop();

			if(current->left) 
				s2.push(current->left);

			if(current->right)
				s2.push(current->right);
		}

		while(!s2.empty())
		{
			current = s2.top();
			cout<<current->data<<endl;
			s2.pop();

			if(current->right) 
				s1.push(current->right);

			if(current->left) 
				s1.push(current->left);
		}
	}
}

// This techqnique uses one deque
// and null in center as sentinel.
void spiral2(node* root)
{
	if(!root) return;
	deque<node*> dq;
	dq.push_front(NULL);
	node* current = root;
	dq.push_front(current);

	while(dq.front() || dq.back())
	{
		while(dq.front())
		{
			current = dq.front();
			dq.pop_front();
			cout<<current->data<<endl;

			if(current->left)
				dq.push_back(current->left);
			if(current->right)
				dq.push_back(current->right);
		}

		while(dq.back())
		{
			current = dq.back();
			dq.pop_back();
			cout<<current->data<<endl;

			if(current->right)
				dq.push_front(current->right);
			if(current->left)
				dq.push_front(current->left);
		}
	}
}


int main()
{

	spiral1(spiralRoot());
	cout<<"########"<<'\n';

	spiral2(spiralRoot());
	cout<<"########"<<'\n';
 	



	return 0;
}