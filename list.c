include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long size(Node * head) {
	Node * itr = &head;
	long length = 0;
	while(itr->next != NULL)
	{
		length++;
	}
	return length;
}

void printList(Node * head)
{
	Node * itr = &head;
	while(itr->next != NULL)
	{
		printf("[%d] ",itr->data);
		itr = itr->next;
	}
}

void printRec(Node * head)
{
	
}

void printReverse(Node * head)
{
	Node * itr = &head;
	while(itr->next != NULL)
	{
		itr =
	}
}

void addFront(Node **lptr, int val)
{
	Node * insert = malloc(sizeof(Node));
	insert->data = val;
	if(lptr != NULL)
	{
		insert->next = lptr;
	} else {
		lptr = insert;
		insert->next = NULL;
	}
}

void addTailR(Node **lptr, int val)
{

}

void addTail(Node **lptr, int val)
{
	Node * insert;

	while(lptr->next != NULL)
	{
		lptr = lptr->next;
	}

	insert = malloc(sizeof(Node));
	insert->data = val;
	insert->next = NULL;

	lptr->next = insert;
}

int delete(Node **lptr, int val) 
{
	return 0;
}

int deleteR(Node **lptr, int val)
{
	return 0;
}

void clearList(Node **lptr)
{
	while(lptr != NULL)
	{
		Node * temp = lptr->next;
		free(lptr);
		lptr = temp;
	}
}

Node* find(Node * head, int val) 
{
	Node * itr = &head;
	while(itr->next != NULL)
	{
		if(itr->data == val)
			return itr;
	}
	return NULL;
}

int replace(Node * head, int old, int new) 
{
	return 0;
}

Node* insert(Node **lptr, int val)
{
	
	return NULL;
}
