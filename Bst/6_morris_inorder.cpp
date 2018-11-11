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


void MorrisTraversal(node* root)
{
	node* current = root;
	while(current!=NULL)
	{
		//left is null then print and go right
		if(current->left == NULL)
		{
			cout<<current->data<<endl;
			current = current->right;
		}
		//current left is not null
		else
		{
			// find predecessor of current
			//and point its right to current
			node* predecessor = current->left;
			while(predecessor->right!=NULL && predecessor->right!=current)
			{
				predecessor = predecessor->right;
			}
			// if right of pred is null then it has not been visited
			// so visit it an set its rigth to current
			if(predecessor->right == NULL)
			{
				predecessor->right = current;
				current = current->left;
			}
			else
				// pred has already been visited
			{
				predecessor->right = NULL;
				cout<<current->data<<"##"<<endl;
				current = current->right;
			}			
		}
	}
}

//     sample inorder tree
//			25        //root
//		  /    \
//		 15     35
//		/ \     / 
//	   10  20  30
//        /  \ 
//       18  22

int main()
{


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
	MorrisTraversal(root);


    
    

	return 0;
}

