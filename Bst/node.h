#include <iostream>
#include <queue>
#include <bits/stdc++.h>
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
