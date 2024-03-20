#include "LinkedList.h"
#include <assert.h>

template<class t>
Node<t>::Node()
{
	next = 0;
}
template<class t>
Node<t>::Node(t val)
{
	next = 0;
	value = val;
}

template <class T>
LinkedList<T>::LinkedList()
{
	head = tail = 0;
	count = 0;
}

template< class t>
int LinkedList<t>::Length()
{
	return count;
}
template <class t>
t LinkedList<t>::At(int pos)
{
	assert(pos >= 0 && pos < count);

	Node<t>* temp = head;
	for (int i = 0; i <pos; i++)
	{
		temp = temp->next;
	}
	return temp->value;
}
template <class t>
void LinkedList <t>::InsertAt(int pos, t val)
{
	assert(pos >= 0 && pos < count);
	Node <t>* newItemInList = new Node<t>(val);
	newItemInList->value = val;
	Node <t>* temp = head;
	if (pos == 0)
	{
		newItemInList->next = head;
		head = newItemInList;
	}
	else
	{
		
		for (int i = 0; i < pos-1; i++)
		{
			temp = temp->next;
		}
		newItemInList->next = temp->next;
		temp->next = newItemInList;
	}
	count++;
}
template <class t>
void LinkedList<t>::Append(t val)
{
	if (count == 0)
	{
		Node <t>* temp = new Node<t>(val);
		tail = temp;
		head = temp;
	}
	else
	{
		Node <t>* temp = new Node<t>(val);
		tail->next = temp;
		tail = temp;
	}
	
	count++;
}
template <class t>
void LinkedList <t>::DeleteAt(int pos)
{
	assert(pos >= 0 && pos < count);
	Node <t>* temp = head;
	if (pos == 0)
	{
		if (count == 1)
		{
			delete temp;
			temp = NULL;
			head = NULL;
			count--;
			return;
		}
		head = head->next;
		delete temp;
		temp = NULL;
	}
	else
	{
		
		for (int  i = 0; i < pos-1; i++)
		{
			temp = temp->next;
		}
		Node <t>* DeletedOne = temp->next;
		temp->next = DeletedOne->next;
		delete DeletedOne;
		DeletedOne = NULL;
		if (pos == count - 1)
			tail = temp;

	}
	count--;

}


template <class t> 
void LinkedList <t> ::Insert(t val)
{
	
	if (count == 0)
	{
		Node <t>* newItem = new Node<t>(val);
		head = tail = newItem;
		count++;
	}
	else
	{
		if (head->value >= val)
		{
			
			InsertAt(0, val);
			return;
		}
		else if (tail->value < val)
		{
			
			Append(val);
			return;
		}
		else
		{
			Node <t>* temp = head;
			int  i = 0;
			for (; i < count; i++)
			{
				if (val <= temp->value)
				{
					break;
				}
				else
				{
					temp = temp->next;
				}
			}

			InsertAt(i , val);
		}
		
		
	}
}

template<class t>
t LinkedList<t>::getMin()
{
	return head->value;
}

template<class t>
void LinkedList<t>::Merge( LinkedList<t> & newlist)
{
	for (int i = 0; i < newlist.Length(); i++)
	{
		Insert(newlist.At(i));
	}
}


template<class t>
void  LinkedList<t>::Intersection(LinkedList<t> newlist,LinkedList<t> & resultlist)
{
	
	
	for (int i = 0; i < Length(); i++)
	{
		for (int j = 0; j < newlist.Length(); j++)
		{
			if (At(i) < newlist.At(j))
				break;
			if (At(i) == newlist.At(j))
			{
				resultlist.Insert(newlist.At(j));
				newlist.DeleteAt(j);
				break;
			}
		}
	}

	
}

template <class t>
LinkedList<t>::~LinkedList()
{
	/*while (count != 0)
		DeleteAt(0);*/
}
