#include <iostream>
#include <unordered_set>
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


node* intersection_list(node* l1, node* l2)
{
	node* ptr1 = l1;
	node* ptr2 = l2;
	node* ptr = new node;
	node* first = ptr;
	node* prev_ptr = NULL;

	while(ptr1  && ptr2 )
	{ 
		if(ptr1->data == ptr2->data)
		{
			node* n = new node;
			n->data = ptr1->data;

			ptr->link = n;
			prev_ptr = ptr;
			ptr = ptr->link;
			// insert(ptr1->data, ptr);

			ptr1 = ptr1->link;
			ptr2 = ptr2->link;

		}
		else if (ptr1->data < ptr2->data)
		{
			ptr1 = ptr1->link;
		}
		else
			ptr2 = ptr2->link;
	}
	return first;
}

int main()
{   	
	node* l1 = new node;
	l1->data = 1;
	l1->link = NULL;

	insert(6,l1);
	insert(4,l1);
	insert(3,l1);
    insert(2,l1);
    show(l1);

    node* l2 = new node;
	l2->data = 2;
	l2->link = NULL;

	insert(8,l2);
	insert(6,l2);
	insert(4,l2);
    show(l2);

    node* n = intersection_list(l1,l2);
    show(n);

	
}