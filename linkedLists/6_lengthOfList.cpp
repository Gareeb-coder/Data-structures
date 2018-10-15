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

int lengthOfList2(node* first)  //recursive
{
	if (first == NULL)
	{
		return 0;
	}
	
	return 1 + lengthOfList2(first->link);
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

	int l = lengthOfList(first);
	cout<<"len:: "<<l<<endl;

	l = lengthOfList2(first);
	cout<<"len:: "<<l<<endl;
	
}