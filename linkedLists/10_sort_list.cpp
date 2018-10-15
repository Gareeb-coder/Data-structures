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

void removeDuplicates(node* first)
{
	node* ptr = first->link;
	node* pre_ptr = first;
	
	node* temp;
	while(ptr!=NULL)
	{
		if(ptr->data == pre_ptr->data)
		{	
			temp = ptr;
			delete ptr;
			temp = NULL;
			pre_ptr->link = pre_ptr->link->link;
			ptr = pre_ptr->link;
		}
		else
		{
			pre_ptr = ptr;
			ptr = ptr->link;
		}
	}
}

void removeDuplicates2(node* first)
{
	unordered_set<int> intset;
	node* ptr = first;
	node* prev = NULL;
	node* temp;
	while(ptr)
	{
		if(intset.find(ptr->data) == intset.end())
		{		//if we reachend ie data not in set
			intset.insert(ptr->data);
			prev = ptr;			
		}
		else
		{	
			prev->link = ptr->link;
			temp = ptr;
			delete temp;
			temp = NULL;
		}
		ptr = ptr->link;
	}
}

int main()
{   
	node* start = new node;
	node* first = new node;
	node* second = new node;
	node* third = new node;
 	
	first->data = 11;
	second->data = 11;
	third->data = 22;
	
	start->link = first;
	first->link = second;
	second->link = third;
	third->link = NULL;


	insert(33,third);
	insert(33,third);
	insert(30,third);
	insert(22,third);
    insert(22,third);

	show(start);

	// removeDuplicates(first);
	// show(start);

	removeDuplicates2(first);
	show(start);

	
	
}