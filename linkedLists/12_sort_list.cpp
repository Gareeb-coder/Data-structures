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


void swap(node* first,int x,int y)
{
	int i=0;
	node* ptr1 = first;
	node* ptr2 = first;
	node* pre_ptr1 = NULL;
	node* pre_ptr2 = NULL;


	while(ptr1 && ptr1->data!=x)
	{
		pre_ptr1 = ptr1;
		ptr1 = ptr1->link;
	}

	while(ptr2 && ptr2->data!=y)
	{
		pre_ptr2 = ptr2;
		ptr2 = ptr2->link;
	}
	
	if(ptr1==NULL || ptr2==NULL)
		return;
	
	if (pre_ptr1!=NULL)
		pre_ptr1->link = ptr2;
	else
		first = ptr2;

	if (pre_ptr2!=NULL)
		pre_ptr2->link = ptr1;
	else
		first = ptr2;


	node* temp = ptr2->link;
	ptr2->link = ptr1->link;
	ptr1->link = temp;
}

void swap2(node* a, node* b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

node* sort_list(node* first)
{
	node* ptr = first;
	node* ptr1;
	node* min;

	while(ptr)
	{	
		min = ptr;
		ptr1 = ptr->link;
		while(ptr1)
		{
			if (ptr1->data < min->data)
			{
				min = ptr1;
			}
			ptr1 = ptr1->link;
		}
		swap2(ptr,min);
		ptr = ptr->link;
	}
	return first;
}

node* merge(node* first)
{
	
}

int main()
{   
	node* start = new node;
	node* first = new node;
	node* second = new node;
	node* third = new node;
 	
	first->data = 11;
	second->data = 99;
	third->data = 50;
	
	start->link = first;
	first->link = second;
	second->link = third;
	third->link = NULL;


	insert(6,third);
	insert(3,third);
	insert(77,third);
	insert(58,third);
    insert(2,third);


	show(first);

	// first =  sort_list(first);
	// show(first);

	
	first = merge_sort(first);
	show(first);
	
}