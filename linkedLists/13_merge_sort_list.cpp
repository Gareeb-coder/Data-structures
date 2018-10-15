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


node* merge(node* l1, node* l2)
{
	node* n_l = new node;
	node* first = n_l;
	node* temp;

	if (l1==NULL)
		return l2;
	if (l2==NULL)
		return l1;

	while(l1!= NULL && l2!= NULL)
	{	
		node* temp = new node;
		if(l1->data < l2->data)
		{			
			temp->data = l1->data;
			l1 = l1->link;
		}

		else
		{
			temp->data = l2->data;
			l2 = l2->link;
		}

		n_l->link = temp; 
		n_l = temp;
	}

	if (l1==NULL)
	{
		while(l2)
		{
			node* temp = new node;
			temp->data = l2->data;
			n_l->link = temp;
			n_l = temp;
			l2 = l2->link;
		}
	}

	if (l2==NULL)
	{
		while(l1)
		{
			node* temp = new node;
			temp->data = l1->data;
			n_l->link = temp;
			n_l = temp;
			l1 = l1->link;
		}
	}

	return first->link;
}
  
void split(node* first, node* front , node* back)
{
	node* fast;
	node* slow ;
	slow = front;
	fast = front->link;

	while(fast!=NULL)
	{
		fast = fast->link;
		if (fast!= NULL)
		{	
			fast = fast->link;
			slow = slow->link;
		}
	}
	front = first;
	back = slow->link;
	slow->link = NULL;
	
}

void mergeSort(node* first)
{	
	node* ptr = first;
	node* a;
	node* b;
	if(ptr==NULL)
		return;
	if(ptr->link==NULL)
		return;

	split(ptr,a,b);

	mergeSort(a);
	mergeSort(b);

	first = merge(a,b);
}

int main()
{   
	node* l1 = new node;
	l1->data = 1;
	l1->link = NULL;

	insert(65,l1);
	insert(40,l1);
	insert(9,l1);
	insert(77,l1);
	insert(5,l1);
    insert(20,l1);
    show(l1);

    node* l2 = new node;
	l2->data = 3;
	l2->link = NULL;

	insert(8,l2);
	insert(6,l2);
	insert(4,l2);
    // show(l2);


	
	// node* n = merge(l1,l2);
	// show(n);
	// mergeSort(l1);
	// show(l1);
	node* front = new node;
	node* back= new node;
	split(l1,front,back);
	// show(front);
	// show(back);

	
}