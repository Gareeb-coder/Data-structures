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
	do
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}while(ptr!=first);
	cout<<endl;
}

void show_bw(node* third)
{
	node* ptr = third;
	do
	{
		cout<<ptr->data<<" ";
		ptr = ptr->prev;
	}while(ptr!=third);
	cout<<endl;
}

void delete_node(node* a)
{
	a->prev->next = a->next;
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

int main()
{

	node* first = new node;
	node* second = new node;
	node* third = new node;

	first->prev = third;
	second->prev = first;
	third->prev = second;

	first->next = second;
	second->next = third;
	third->next = first;

	first->data = 100;
	second->data = 200;
	third->data = 300;

	show_fw(first);
	show_fw(third);
	show_bw(third);
	show_bw(first);

	delete_node(second);

	show_fw(first);

	int key = 55;
	insert(first,third,key);
	show_fw(first);

	insert(first->next,third,999);
	show_fw(first);

	delete_node(first->next->next);
	show_fw(first);

	return 0;
}