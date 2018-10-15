#include <iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};


void show(node* first)
{
	node* ptr = first->link;
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

node* findNode(node* first, int pos)
{	
	int i=0;
	node* ptr = first;
	while(ptr!=NULL)
	{
		if(i==pos)
			return ptr;
		ptr = ptr->link;
		i++;
	}
}

node* findNode2(node* first, int pos)
{	
	int i = 1;
	if(i == pos)
		return first;

	return findNode(first->link,pos-1);
}

int lengthOfList(node* first) //iterative 
{
	node* ptr = first;
	int count = 0;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	return count;
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


void swap_kth_node(node* first,int k)
{
	if(first==NULL)
		return;
	int l = lengthOfList(first);

	if(k>l)
		return;

	if(2*k - 1 == l)
		return;

	node* ptr1 = first;
	node* prev1 = NULL;

	int i = 0;
	while(i!=k-1)
	{
		prev1 = ptr1;
		ptr1 = ptr1->link;
		i++;
	}

	node* ptr2 = ptr1;
	node* prev2 = prev1;

	while(i!=l-k)
	{
		prev2 = ptr2;
		ptr2 = ptr2->link;
		i++;
	}
    cout<<"k :: "<<ptr1->data<<" "<<ptr2->data<<endl;

    prev1->link = ptr2;
    node* temp = ptr2->link;
    ptr2->link = ptr1->link;
    ptr1->link = temp;
    prev2->link = ptr1;
}

int main()
{   
	node* start = new node;
	node* first = new node;
	node* second = new node;
	node* third = new node;
 	
	first->data = 11;
	second->data = 22;
	third->data = 33;
	
	start->link = first;
	first->link = second;
	second->link = third;
	third->link = NULL;

	// show(first);

	insert(66,third);
	insert(55,third);
	insert(44,third);

	show(start);

	swap_kth_node(first,2);
	show(start);
	o
	swap(start, 11,22);
	show(start);
	


	
}