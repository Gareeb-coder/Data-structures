#include <iostream>
#include <assert.h>
using namespace std;


struct nodeType
{	
	int info;
	nodeType *link;
};

class Iterator
{
private:
	nodeType* current;
public:
	Iterator();
	Iterator(nodeType* ptr);
	int operator*();
	Iterator operator++();
	bool operator==(const Iterator &I) const;
	bool operator!=(const Iterator &I) const;
	// ~Iterator();
};
// Definations of Iterator

Iterator::Iterator()
{
	current = NULL;
}

Iterator::Iterator(nodeType* ptr)
{
	current = ptr;
}

int Iterator::operator*()
{
	return current->info;
}

Iterator Iterator::operator++()
{
	current = current->link;
	return *this;
}

bool Iterator::operator==(const Iterator &I) const
{
	return (current==I.current);
}

bool Iterator::operator!=(const Iterator &I) const
{
	return (current!=I.current);
}


class List
{	
protected:
	int count;
	nodeType* first;   //here
	nodeType* last;     //here
	void copyList(const List &otherList);
public:
	const List& operator=(const List &otherList);
	void initializeList();
	bool isEmpty() const;
	void print() const;
	int length() const;
	void destroyList();
	int front() const; //here
	int back() const;  //here
	Iterator begin();
	Iterator end();
	List();                      // default constructor
	List(const List &otherList); //copy constructor
	// friend ostream& operator<<(ostream & out,List &l)
	// {
	// 	for (int i = 0; i < l.length(); ++i)
	// 	{
	// 		out<<
	// 	}
	// }
	~List();
};

List::List()
{
	count  = 0;
	first = NULL;
	last = NULL;
}

void List::destroyList()
{
	nodeType* temp;
	while(first!=NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}

void List::initializeList()
{
	destroyList();
}

void List::print() const
{
	nodeType* current;
	current = first;
	while(current!=NULL)
	{
		cout<<current->info<<" ,";
		current = current->link;
	}
}

int List::length() const
{
	return count;
}


int List::front() const
{
	assert(first!=NULL);
	return first->info;
}

int List::back() const
{
	assert(last!=NULL);
	return last->info;
}

Iterator List::begin()
{
	Iterator temp(first);
	return temp;
}

Iterator List::end()
{
	Iterator temp(NULL);
	return temp;
}

void List::copyList(const List &otherList)
{
	nodeType* newNode;
	nodeType* current;

	if(first!=NULL)
		destroyList();

	if(otherList.first == NULL)
	{
		first = NULL;
		last = NULL;
		count = 0;
	}

	else
	{
		current = otherList.first;
		count = otherList.count;
		first = new nodeType;
		first->info = current->info;
		first->link = NULL;
		last = first;
		current = current->link;

		while(current!=NULL)
		{
			newNode = new nodeType;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}

List::~List()
{
	destroyList();
}

List::List(const List &otherList)
{
	first = NULL;
	copyList(otherList);
}

const List& List::operator=(const List &otherList)
{
	if(this != &otherList)
	{
		copyList(otherList);
	}
	return *this;
}


// int main(int argc, char const *argv[])
// {
// 	List l1;

// 	return 0;
// }