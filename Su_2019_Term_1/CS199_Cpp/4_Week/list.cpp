#include <iostream>
#include <cctype>
#include <string>
#include "list.h"

using namespace std;

linked_list::linked_list()
{
	head = NULL;
}

void linked_list::addfront(int x)
{
	node *temp;
	if(head == NULL)
	{
		head = new node;
		head->value = x;
		head->address = NULL;
	}
	else //if the head is not null
	{	
		temp = new node; //create memory for temp
		temp->value = x; //the value is x
		temp->address = head; //address is now the the address for head
		head = temp;//->address; //head is redefined as the address for temp
	}
}

void linked_list::display(void)
{
	node *current;
	current = head; //current is now pointing to the same place as head
	//while current has something in it
	if(head == NULL)
	{
		cout << "Linked list is empty.";
	}
	else
	{
		while(current != NULL)
		{
			cout << current->value; //print out the value of current
			current = current->address; //current changed to *head.address
		}
	}
	cout << '\n';
}

void linked_list::displaylast(void)
{
	node *current;
	current = head;
	if(!head)
	{
		cout << "Linked list is empty.";
	}
	else
	{
		while(current->address != NULL)
		{
			current = current->address;
		}	
		cout << current->value;
	}
}

void linked_list::everyother()
{
	node *current;
	current = head;

	if(!head)
	{
		cout << "Linked list is empty";
	}
	else
	{
		cout << current->value << ' ';
		while(current->address != NULL)
		{
			current = current->address;
			if(current->address != NULL)
			{
				current = current->address;
				cout << current->value << ' ';
			}			
		}
	}
}

void linked_list::secondadd(int x)
{
	node *temp;
	if(!head)
	{
		head = new node;
		head->value = x;
		next->address = NULL;	
	}
	else
	{
		temp = new node;
		temp->value = x;
		
	}
}

