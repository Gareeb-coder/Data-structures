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

void delete_next_ptr_of(node* ptr)
{	
	if(ptr->link == NULL)
	{
		cout<<"Last element"<<endl;
	}
	else{
		node* temp = ptr->link;
		delete temp;
		temp = NULL;
		ptr->link = ptr->link->link;
	}
}

void delete_by_key(node* first, int key)
{	
	bool found = false;
	node* ptr = first;
	node* pre_ptr = first;
	while(ptr!= NULL || !found)
	{
		if(ptr->data == key)
		{
			found = true;
			// cout<<"key is:: "<< key<<endl;
			// cout<<"pre_ptr data:: "<<pre_ptr->data<<endl;
			node* temp = pre_ptr->link;
			delete temp;
			temp = NULL;
			pre_ptr->link = pre_ptr->link->link;
			return;
		}
			
			
		else{
			pre_ptr = ptr;
			ptr = ptr->link;
		}
	}
	if (!found)
	{
		printf("%s\n","key not found" );
	}
}

node* delete_by_pos(node* first, int pos)
{	
	node* ptr = first;
	node* pre_ptr = first;

	if(pos==0)
	{
		node* temp = first;
		delete temp;
		temp = NULL;
		first = first->link;
		return first;
	} 

	int i = 0;
	while(ptr!= NULL)
	{
		if(pos==i)
		{
			node* temp = ptr;
			// cout<<"temp:: "<<temp->data<<endl;
			// cout<<"pos :: "<<pos<<endl;
			// cout<<"pre_ptr ::"<<pre_ptr->data<<endl;
			delete ptr;
			ptr = NULL;
			pre_ptr->link = pre_ptr->link->link;
			return first;
		} 
		i++;
		pre_ptr = ptr;
		ptr = ptr->link;
    }
}

void delete_list(node* first)
{
	node* temp;
	while(first!=NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	temp = NULL;
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

	// show(first);

	insert(10,third);

	show(first);

	delete_next_ptr_of(third);
	

	show(first);

	delete_by_key(first,33);
	show(first);

	insert(10,first);
	insert(20,first);
	insert(30,first);
	show(first);

	first = delete_by_pos(first,0);
	show(first);

	first  = delete_by_pos(first,2);
	show(first);

	first  = delete_by_pos(first,2);
	show(first);

	delete_list(first);
	show(first);


	return 0;
}