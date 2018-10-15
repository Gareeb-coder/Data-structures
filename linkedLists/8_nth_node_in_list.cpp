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

node* LastNode(node* first) //iterative 
{
	node* ptr = first;
	node* pre_ptr = first;
	int count = 0;
	while(ptr != NULL)
	{
		count++;
		pre_ptr = ptr;
		ptr = ptr->link;
	}
	return pre_ptr;
}

node* nthFromEnd(node* first, int nth)
{
	int len = lengthOfList(first);
	int pos = len - nth;
	return findNode(first,pos);

}

bool detectLoop(node* first)
{
	node* s_ptr = first;
	node* l_ptr = first;
	while(s_ptr && l_ptr && l_ptr->link)
	{
		s_ptr = s_ptr->link;
		l_ptr = l_ptr->link->link;
		if (s_ptr==l_ptr)
		{
			return true;
		}
	}
	return false;
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
	
	// node* nth = findNode(first,3);
	// cout<<nth->data<<endl;	

	// nth = findNode2(first,2);
	// cout<<nth->data<<endl;

	// nth = LastNode(first);
	// cout<<nth->data<<endl;

	// nth = nthFromEnd(first,3);
	// cout<<nth->data<<endl;

	// creating loop
	first->link->link->link->link = first;
	bool isLoop = detectLoop(first);
	cout<<isLoop;


	
}