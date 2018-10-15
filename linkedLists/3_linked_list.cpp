
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
	while(ptr!= NULL)
	{
		cout<<ptr->data<<endl;
		ptr = ptr->link;
	}
	cout<<endl;
}

void insert(int value, node* ptr)
{
	node* n = new node;
    n->data = value;

    n->link = ptr->link;
    ptr->link = n;
}

void del_next_ptr_of(node* prePtr)
{
	node* temp = prePtr->link;
    delete temp;
    temp = NULL;
	prePtr->link = prePtr->link->link;

    
}

node* linked_fw()
{
	node* first = NULL;
	node* last = NULL;
	

	int x;
	cin>>x;

	while(x!=-1)
	{	
		node* n = new node;
		n->data = x;

		if(first==NULL){
			first =  n;
			last = n;
		}
		else{
			last->link = n;
			last = n;
			
		}
	    cin>>x;
	}
	last = NULL;
	return first;
}

node* linked_bw()
{
	node* first = NULL;
	node* n;
	int x;
	cin>>x;

	while(x!=-1)
	{
		n = new node;
		n->data = x;
		n->link = first;
		first = n;
		cin>>x;
	}

	return n;
}

int main(int argc, char const *argv[])
{
	node* first = new node;
	node* second = new node;
	node* third = new node;

	first->data = 1;
	second->data =2;
	third->data = 3;

	first->link = second;
	second->link = third;
	third->link = 	NULL;
    
    show(first);


    insert(100,first);
    insert(200,second);

    show(first);
    del_next_ptr_of(first);
    
    show(first);

    // node* A = linked_fw();
    // show(A);

    node* B = linked_bw();
    show(B);
	return 0;
}

