#include <iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

void show(node* first)
{	
	node* ptr = first;
	if(first!= NULL)
	{
		do{
			cout<<ptr->data<<" ";
			ptr = ptr->link;
		  }while(ptr!=first);
	}
	
	cout<<endl;
}

void insert(int val, node* ptr)
{
	node* n = new node;
	n->data = val;

	n->link = ptr->link;
	ptr->link = n;
}


void split(node* first,node** h1, node** h2)
{

	node* slow = first;
	node* fast = first;

	if (first == NULL)
		return;

	while(fast->link != first && 
		fast->link->link != first)
	{
		fast = fast->link->link;
		slow = slow->link;
	}

	if (fast->link->link == first)
		fast = fast->link;

	*h1 = first;

	if(first->link!= first)
		*h2 = slow->link;

	slow->link = first;
	fast = NULL;
}


int main()
{
	node* first = new node;
	node* second = new node;
	node* third = new node;

	first->link = second;
	second->link = third;
	third->link = NULL;

	first->data = 10;
	second->data = 20;
	third->data = 30;

	third->link = first;

	// show(first);
	// show(second);
	// show(third);

	insert(100,second);
	// show(third);

	insert(200,first);
	// show(first);

	
	show(first);

	// node* h1 = NULL;
	// node* h2 = NULL;
	// split(first,&h1,&h2);

	// show(h1);
	// show(h2);
	// cout<<h2->data<<endl;
	// cout<<h2->link->data<<endl;
	// cout<<h2->link->link->data<<endl;
	// cout<<h2->link->link->link->data<<endl;
	// cout<<h2->link->link->link->link->data<<endl;
	// cout<<h2->link->link->link->link->link->data<<endl;
	// show(first);

	show(third);



    
	
	return 0;
}