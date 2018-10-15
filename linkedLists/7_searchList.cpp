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
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"  ";
		ptr = ptr->link;
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

bool search(node* first, int key) //iterative
{
	node* ptr = first;
	while(ptr!= NULL)
	{
		if(ptr->data == key)
			return true;
		ptr = ptr->link;
	}
}

bool search2(node* first, int key)
{   
	if(first == NULL)
		return false;

	if(first->data == key)
		return true;

	return search2(first->link,key);
}


int main()
{   
	// node* start;
	node* first = new node;
	node* second = new node;
	node* third = new node;
 	
 	// start->link = first;
	first->data = 11;
	second->data = 22;
	third->data = 33;
	
	
	first->link = second;
	second->link = third;
	third->link = NULL;

	show(first);

	insert(10,third);

	show(first);
	
	bool found = search2(first,10);
	cout<<found;	
	
}