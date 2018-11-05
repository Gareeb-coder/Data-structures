#include <iostream>
#include <stdio.h>
using namespace std;

#define SIZE 10

class Queue
{
	int *arr;
	int capacity,F,R,count;
public:
	Queue(int size = SIZE);

	void dequeue();
	void enqueue(int x);
	int front();
	int size();
	bool isEmpty();
	bool isFull();
};

Queue::Queue(int size)
{
	arr = new int[size];
	capacity = size;
	F = 0;
	R = -1;
    count = 0;
}

void Queue::dequeue()
{
	if(isEmpty())
	{
		cout<<"UnderFlow"<<endl;
		return;
	}
	cout<<"Removing "<<arr[F]<<endl;
	F = (F+1)%capacity;
	count--;
}

void Queue::enqueue(int item)
{
	if(isFull())
	{
		cout<<"OverFlow"<<endl;
		return ;
	}
	R = (R+1)%capacity;
	arr[R] = item;
	cout<<"Added item:"<<item<<" at pos:"<<R<<endl;
	count++;
}


int Queue::front()
{
	if(isEmpty())
	{
		cout<<"UnderFlow ";
		return -1;
	}
	return arr[F];
}

int Queue::size()
{
	return count;
}

bool Queue::isEmpty()
{
	return(size()==0);
}

bool Queue::isFull()
{
	return(size()==capacity);
}

int main(int argc, char const *argv[])
{
	Queue q(3);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	q.enqueue(3);
	q.enqueue(3);

	cout<<q.front()<<endl;
	q.dequeue();
	cout<<q.front()<<endl;
	q.dequeue();
	cout<<q.front()<<endl;
	q.dequeue();
	cout<<q.front()<<endl;
	return 0;
}