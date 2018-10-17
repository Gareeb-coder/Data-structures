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

void insert(node* a ,node* c, int key)
{
	node* n = new node;
	n->data = key;

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

void find_pair(node* first, int key)
{
	node* last = last_node(first);
	node* beg = first;
	node* end = last;

	while(beg!=end)
	{	
		int sum = beg->data + end->data;
		if (sum == key)
		{
			cout<<beg->data<<", "<<end->data<<endl;
			beg = beg->next;
		}

		else if(sum > key)
		{
			end = end->prev;
		}
		else
		{
			beg = beg->next;
		}
	}
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

	first->data = 1;
	second->data = 8;
	third->data = 9;

	// show_fw(first);
	insert(first,second,2);
	insert(first->next,second,4);
	insert(first->next->next,second,5);
	insert(first->next->next->next,second,6);
	show_fw(first);


	find_pair(first,10);
	

	return 0;
}