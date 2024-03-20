#pragma once


template <class t>
class Node {
public:
	Node <t>* next;
	t value;
	Node();
	Node(t);
};


template <class t>
class LinkedList
{
	int count;
	Node <t>* head;
	Node <t>* tail;
public:
	LinkedList();
	int Length();
	t At(int);
	void InsertAt(int, t);
	void Append(t);
	void DeleteAt(int);
	void Insert(t);
	t getMin();
	void Merge( LinkedList<t>& newlist);
	void Intersection(LinkedList<t> newlist, LinkedList<t>& resultlist);
	~LinkedList();
};

