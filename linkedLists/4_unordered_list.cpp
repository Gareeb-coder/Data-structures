#include "3_listADT.cpp"
#include <iostream>

class unorderedList : public List
{
public:
	// unorderedList();
	bool search(const int &searchItem) const;
	void insertFirst(const int &insertItem);
	void insertLast(const int  &insertItem);
	void deleteNode(const int &deleteItem);
	// ~unorderedList();
	
};



bool unorderedList::search(const int &searchItem)const
{
	nodeType* current;
	current = first;
	bool found = false;

	while(current!=NULL || !found)
	{
		if(current->info==searchItem)
			found = true;
		current = current->link;
	}
	return found;
}

void unorderedList::insertFirst(const int &insertItem)
{
	nodeType* newNode = new nodeType;
	newNode->info = insertItem;
	newNode->link = first;
	first = newNode;
	count++;

	if(last = NULL)
		last = newNode;
}

void unorderedList::insertLast(const int &insertItem)
{
	nodeType* newNode;
	newNode = new nodeType;
	newNode->info = insertItem;
	newNode->link = NULL;
	if(first=NULL)
	{
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		last->link = newNode;
		last = newNode;
		count++;
    }
	
}

void unorderedList::deleteNode(const int &deleteItem)
{	
	nodeType* current;
	nodeType* trailCurrent;
	bool found;

	if(first = NULL)       //CASE 1-- list empty
	{
		cout<<"Empty Cannot delete Node."<<endl;
	}
	else
	{                      //CASE 2-- item at first node
		if(first->info == deleteItem) 
		{
			current = first;
			first = first->link;
			count--;

			if(first = NULL) // case 2a-- only one node
				last = NULL;
			                 //else 2b -- more than one nodes
			delete current;
		}

		else				//CASE 3-- item not at first
		{
			found  = false;
			trailCurrent = first;
			current = trailCurrent->link;
			while(last!=NULL || !found)
			{
				if(current->info != deleteItem)   
				{
					trailCurrent = current;
					current = current->link;
				}
				else
				{
					found = true;
				}
				
			}

			if(found)                          //case 3a - item found
			{
				trailCurrent->link = current->link;  
				count--;
				if(last==current)             //3a-i ---- item at last
					last = trailCurrent;
				 							  // 3a-ii ---- item not at last ie. in middle
				delete current;
			}
			else                              // 3b - item not found.
			{
				cout<<"Item not in list."<<endl;
			}
		}

	}
}

int main(int argc, char const *argv[])
{

	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    freopen("output.txt", "w", stdout);
 //    #endif
    
	unorderedList list1;
	int num;

	cin >> num;
	while (num != -1)
	{
	list1.insertFirst(num);
	cin >> num;
	}

	// cin >> num;
	// while (num != -1)
	// {
	// list1.insertLast(num);
	// cin >> num;
	// }
    
	list1.print();
	cout<<endl;
	cout<<"enter item to be deleted: ";
	cin>>num;
	list1.deleteNode(num);
	list1.print();

	return 0;
}