#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList()
{
	head = NULL;
}
LinkedList::insert(int v)
{
	node * tptr;
	node * n = new node();
	n->data = v;
	if(this->head == Null)
	{
		this->head = n;
	}
}
LinkedList::print()
{
	node *ptr = head;
	while(ptr->next != Null)
	{
		cout<< ptr->data<< endl;
		ptr = ptr->next;
	}
}
