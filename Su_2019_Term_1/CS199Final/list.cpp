#include <iostream>
#include <cstring>
#include "list.h"
using namespace std;

waiting_room::waiting_room()
{
	head = NULL;	
return;
}

waiting_room::~waiting_room()
{
return;
}

// Add a patient node to the list
void waiting_room::admit_patient(void)
{
	char buffer[100];
	node *temp = new node;
	node *current;
	patient_info(temp);
	
	cout << "Enter patient name: ";
	cin.get(buffer, 100, '\n');
	cin.ignore(100, '\n');
	temp->name = new char[strlen(buffer) + 1];
	strcpy(temp->name, buffer);
	
	cout << "Enter patient priority: ";
	cin >> temp->priority;
	while(cin.fail() || temp->priority < 0 || temp->priority > 5)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input. Enter patient priority: ";
		cin >> temp->priority;
	}
	cin.ignore(100, '\n');
	
	//linked list is current empty
	if(!head)
	{
		head = temp;
		temp->next = NULL;
	}
	//If the linked list is not empty
	else
	{	//look at the priority. If it's smaller than the head, add it to the front
		if(temp->priority < head->priority)
		{
			temp->next = head;
			head = temp;
		}
		//if priority equals the priority in the head
		else if(temp->priority == head->priority)
		{
			current = head;
			while(current->next && current->next->priority == head->priority)
			{
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
		}	
		//if priority for the entere patient is greater than the head.		
		else if(temp->priority > head->priority)
		{
			current = head;
			while(current->next && current->next->priority <= temp->priority)
			{
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
		}
	}
return;
}

// Removes the highest priority patient from the list
void waiting_room::see_patient(void)
{
	node *temp;

	if(!head)
	{
		cout << "No patients\n";
	}
	else
	{
		temp = head;
		cout << temp->name << " the doctor will see you now\n";
		head = temp->next;
	}
return;
}

// displays the current linked list
void waiting_room::display(void)
{
	node *temp;
	if(!head)
	{
		cout << "No patients\n";
	}
	else
	{
		temp = head;
		while(temp)
		{	
			cout << '\n';
			cout << "Name: " << temp->name << '\n';
			cout << "Priority: " << temp->priority << '\n';
			temp = temp->next;
		}
	}
}

// Fill outs a patient struct
void waiting_room::patient_info(node *p)
{
  // placeholder values
  p->name = NULL;
  p->priority = 0;
}
