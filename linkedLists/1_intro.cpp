#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
	int data;
	node *link;	
};

void show(node* ptr)
{
	node* current = ptr;

	while(current!=NULL)
	{
		cout<<current->data<<endl;
		current = current->link;
	}
	cout<<'\n';
}

void insert(int value,node* ptr1)
{
	node *n = new node;
	n->data = value;

	n->link = ptr1->link;
	ptr1->link = n;
}

void del_next_ptr_of(node *ptr)
{   
	node* trash = ptr->link;
	delete trash; //deletes the MEMORY pointed by trash ptr
	trash = NULL; //deletes the TRASH PTR
	ptr->link = ptr->link->link;
}

int main()
{  
	// **Creation**
    // Allocating memory
    node* head = new node;
    node* second = new node;
    node* third = new node;

    head->data = 1;
    head->link = second;

    second->data = 2;
    second->link = third;
    
    third->data = 3;
    third->link = NULL;

    show(head);

	// // **Insertion bw head and second**

 //    node* p = new node;
 //    p->data =100;
    
 //    p->link = head->link;
 //    head->link = p;
    
    insert(100,head);
    show(head); 

    // **Deletion of node having data 100
    // head->link = second;
    del_next_ptr_of(head);
    show(head);

    del_next_ptr_of(head);
    show(head);

    insert(200,head);
    show(head);

    

	return 0;
}