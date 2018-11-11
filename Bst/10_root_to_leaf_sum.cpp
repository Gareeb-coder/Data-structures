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

bool rootToLeafSum(node* root,int sum)
{
	if(root == NULL)
		return false;

	// Check if node is a leaf
	if(root->left==NULL && root->right==NULL)
	{
		if(root->data == sum)
		{
			// result.push_back(root->data);
			cout<<root->data<<endl;
			return true;
		}
		else
			return false;
	}

	// if left side returns true
	if(rootToLeafSum(root->left,sum-root->data))
	{
		// result.push_back(root->data);
		cout<<root->data<<endl;
		return true;
	}

	// if right side returns true
	if(rootToLeafSum(root->right,sum-root->data))
	{
		// result.push_back(root->data);
		cout<<root->data<<endl;
		return true;
	}

	return false;
}

// Compact version
bool pathHasSum(node* root, int sum)
{
	if(!root) 
		return false;
	sum = sum-root->data;
	if(!root->left && !root->right && sum == 0)
		return true;
	return pathHasSum(root->left,sum)||pathHasSum(root->right,sum);
}

int main()
{
	node* root = inorderRoot();
	
	inorder(root);
	cout<<"########"<<'\n';

    list<int> result;
    cout<<rootToLeafSum(root,90)<<endl;

    cout<<pathHasSum(root,60)<<endl;

	return 0;
}