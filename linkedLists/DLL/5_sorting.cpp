#include <iostream>
using namespace std;

struct node
{
	int data;
	node* prev;
	node* next;
};

void show_fw(node* first)
{
	node* ptr = first;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

void show_bw(node* third)
{
	node* ptr = third;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->prev;
	}
	cout<<endl;
}

void delete_node(node* a)
{	
	if(a->prev!=NULL)
		a->prev->next = a->next;

	if(a->next!=NULL)
		a->next->prev = a->prev;
	
	delete a;
	a = NULL;
}

void insert_bw(node* a ,node* c, int key)
{
	node* n = new node;
	n->data = key;

	a->next = n;
	n->next = c;
	c->prev = n;
	n->prev = a;
}

void insert(node* a , int key)
{
	node* n = new node;
	n->data = key;
	node* c = a->next;

	a->next = n;
	n->next = c;
	c->prev = n;
	n->prev = a;
}


node* last_node(node* first)
{	
	node* ptr = first;
	node* prev = NULL;
	while(ptr!=NULL)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	return prev;
}

node* insert_sorted(node* first, int key)
{
	node* ptr = first;
	node* n = new node;
	n->data = key;

	while(ptr->next!=NULL && ptr->data <key)
	{
		ptr = ptr->next;
	}

	if(ptr->next==NULL)
	{
		ptr->next = n;
		n->prev = ptr;
		n->next = NULL;
	}
	else if(ptr->prev == NULL)
	{
		n->prev = NULL;
		n->next = first;	
		first = n;
		
		
	}
	else
	{
		ptr->prev->next = n;
		n->next = ptr;
		ptr->prev = n;
	}
 	
	return first;
}

int main()
{

	node* first = new node;
	node* second = new node;
	node* third = new node;

	first->prev = NULL;
	second->prev = first;
	third->prev = second;

	first->next = second;
	second->next = third;
	third->next = NULL;

	first->data = 2;
	second->data = 20;
	third->data = 15;

	// show_fw(first);
	// insert_bw(first,second,2);
	
	insert(first,12);
	insert(first,8);
	insert(first,4);
	insert(first,3);
	show_fw(first);

	node* a = second->prev;
	// cout<<a->data;

	first = insert_sorted(first,1);
	show_fw(first);

	
	

	return 0;
}