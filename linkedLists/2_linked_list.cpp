#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
	int data;
	node* link;
};

void show(node* ptr)
{
	node* current = ptr;

	while(current!=NULL)
	{
		cout<<current->data<<endl;
		current = current->link;
	}
	cout<<'\n';
}

node* build_linked_list_fwd()
{
	int num;
	node* newNode = new node;
	node* first;
	node* last;

	first = NULL;

	cin>>num;

	while(num!=-1)
	{   
		newNode = new node;
		newNode->data = num;

		if(first == NULL)
		{
			first = newNode;
			last  = newNode;
		}
		else
		{
			last->link = newNode;
			last = newNode;
		}
		
		cin>>num;
	}
    
    last = NULL;
    return first;
}

node* build_linked_list_bwd()
{
	node* first;
	node* newNode;
	first = NULL;

	int num;
	cin>>num;

	while(num!=-1)
	{
		newNode = new node;
		newNode->data = num;
		newNode->link = first;
		first = newNode;
		cin>>num;
	}
	return first;
}


int main()
{
	// node* first = build_linked_list_fwd();
 //    cout<<"\n";
	// show(first);

    node* second = build_linked_list_bwd();
    cout<<"\n";
	show(second);


}