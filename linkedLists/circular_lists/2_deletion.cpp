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
	if(first!= NULL)
	{
		do{
			cout<<ptr->data<<" ";
			ptr = ptr->link;
		  }while(ptr!=first);
	}
	
	cout<<endl;
}

void printList(node *head) 
{ 
    node *temp = head->link; 
    if (head != NULL) 
    { 
        while (temp != head); 
        { 
            printf("%d ", temp->data); 
            temp = temp->link; 
        }   
    } 
  
    printf("\n"); 
} 

void insert(int val, node* ptr)
{
	node* n = new node;
	n->data = val;

	n->link = ptr->link;
	ptr->link = n;
}


node* search(node* first, int key)
{
	node* ptr = first->link;
	while(ptr->data != key && ptr!=first)
	{
		ptr = ptr->link;
		// cout<<"searched :: "<<ptr->data<<endl;
	}

	if(ptr->data==key)
		return ptr;
	else
		return NULL;
}

void find(node* first,int key,node** pre,node** pos)
{
	node* ptr = first->link;
	node* save = first;
	while(ptr->data!=key && ptr!=first)
	{
		save = ptr;
		ptr = ptr->link;
	}
	if(ptr->data==key)
	{
		*pre = save;
		*pos = ptr;
	}
	else
	{
		*pre = save;
		*pos = NULL;
	}

}

void delete_key(node* first,int key)
{
	node* pre = NULL;
	node* pos = NULL;

	find(first,key,&pre,&pos);

	if(pos == NULL)
	{
		cout<<"item not found"<<endl;
		return;
	}
	node*temp = pos;
	pre->link = pos->link;
	delete pos;
	pos = NULL;

}

int main()
{
	node* first = new node;
	node* second = new node;
	node* third = new node;

	first->link = second;
	second->link = third;
	third->link = NULL;

	first->data = 10;
	second->data = 20;
	third->data = 30;

	third->link = first;

	// show(first);
	// show(second);
	// show(third);

	insert(100,second);
	// show(third);

	insert(200,first);
	// show(first);

	
	show(first);

	// show(second);

	
	// show(first);
	// printList(first);

	int key = 10;
	node* found = search(first,key);
	if (found==NULL)
		cout<<"not found"<<endl;
	else
		cout<<found->data<<endl;

	node* pre = NULL;
	node* pos = NULL;

	find(first,key,&pre,&pos);
	cout<<pos->data<<endl;
	cout<<pre->data<<endl;

	key = 30;
	cout<<"before del: ";
	show(first);
	delete_key(first,key);
	cout<<"after del : ";
	show(first);
	
	return 0;
}