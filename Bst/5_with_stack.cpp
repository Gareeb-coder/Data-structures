#include <iostream>
#include <stack>
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

void inorderStack(node* root)
{
	stack<node*> s;
	node* current = root;
	while(current!=NULL || !s.empty())
	{
		while(current != NULL) 
		{
			s.push(current);
			current = current->left;
		}
		current = s.top();
		s.pop();
		cout<<current->data<<endl;
		current = current->right;
	}
}

int main(int argc, char const *argv[])
{
	
	node* root = inorderRoot();
	inorder(root);
	cout<<"########"<<endl;
	inorderStack(root);

	return 0;
}