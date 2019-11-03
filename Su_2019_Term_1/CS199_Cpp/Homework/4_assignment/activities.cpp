#include <iostream>
#include <cctype>
#include <cstring>
#include "activities.h"

using namespace std;

schedule::schedule()
{
	head = NULL;
	headcopy = NULL;
}

schedule::~schedule()
{
	node *temp = head;
	while(temp)
	{
		temp = temp->next;
		remove_one(head);
		head = temp;
	}
}
		
//Entries are added in the order that the user inputs them
void schedule::add()
{
	char buffer[100];

	//make a new node, *temp
	node *temp = NULL;

	//if the linked list is empty:
	if(head == NULL)
	{
		head = new node;
		cout << "Enter activity name: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		head->name = new char[strlen(buffer) + 1];
		strcpy(head->name, buffer);

		cout << "Enter activity type: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		head->type = new char[strlen(buffer) + 1];
		strcpy(head->type, buffer);		
		
		cout << "Enter activity location: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		head->location = new char[strlen(buffer) + 1];
		strcpy(head->location, buffer);

		cout << "Enter activity date: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		head->date = new char[strlen(buffer) + 1];
		strcpy(head->date, buffer);
		
		cout << "Enter activity time: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		head->time = new char[strlen(buffer) + 1];
		strcpy(head->time, buffer);

		cout << "Enter expected duration (hours): ";
		cin >> head->duration;
		while(cin.fail())
		{
			cin.clear();
			cout << "Invalid input. Enter expected duration (hours): ";
			cin >> head->duration;
		}
		cin.ignore(100, '\n');
		cout << '\n';	
	
		head->next = NULL;
	}
	else
	{
		temp = new node;

		cout << "Enter activity name: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		temp->name = new char[strlen(buffer) + 1];
		strcpy(temp->name, buffer);

		cout << "Enter activity type: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		temp->type = new char[strlen(buffer) + 1];
		strcpy(temp->type, buffer);		
		
		cout << "Enter activity location: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		temp->location = new char[strlen(buffer) + 1];
		strcpy(temp->location, buffer);
		
		cout << "Enter activity date: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		temp->date = new char[strlen(buffer) + 1];
		strcpy(temp->date, buffer);
		
		cout << "Enter activity time: ";
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		temp->time = new char[strlen(buffer) + 1];
		strcpy(temp->time, buffer);

		cout << "Enter expected duration (hours): ";
		cin >> temp->duration;
		while(cin.fail())
		{
			cin.clear();
			cout << "Invalid input. Enter expected duration (hours): ";
			cin >> temp->duration;
		}
		cin.ignore(100, '\n');
		cout << '\n';	

		temp->next = head;
		head = temp;
	}
}

void schedule::display_all()
{
	node *temp = head;
	if(!head)
	{
		cout << "No activities\n";
	}
	else
	{
		while(temp)
		{
			display_one(temp);
			temp = temp->next;
		}
	}
}

void schedule::display_one(node *a)
{
	cout << "Activity name: " << a->name << '\n';
	cout << "Activity type: " << a->type << '\n';
	cout << "Activity location: " << a->location << '\n';
	cout << "Activity date: " << a->date << '\n';
	cout << "Activity time: " << a->time << '\n';
	cout << "Activity duration (hours): " << a->duration << "\n\n";	
}

void schedule::remove_one(node *a)
{
	delete [] a->name;
	delete [] a->type;
	delete [] a->location;
	delete [] a->date;
	delete [] a->time;
	delete a;
}

void schedule::check()
{
	node *temp = head;
	while(temp)
	{
		cout << temp->name << '\n';
	//	cout << temp->next << "\n\n";
		temp = temp->next;
	}
}

void schedule::remove()
{
	char getridof[100];
//	char *act;
	node *current, *temp, *previous;

	cout << "Enter name of activity to remove: ";
	cin.get(getridof, 100, '\n');
	cin.ignore(100, '\n');	
//	act = new char[strlen(buffer) + 1];
//	strcpy(act, buffer);

	if(!head)
	{
		cout << "No activities\n";
	}
	else if(strcmp(head->name, getridof) == 0)
	{
		temp = head;
		head = temp->next;
		remove_one(temp);
		//delete temp->next;
	}
	else
	{
		current = head->next;
		previous = head;
		//go through the linked list until we find a name that matches the input
		while(current->next != NULL && strcmp(current->name, getridof) != 0)
		{
			previous = current;
			current = current->next;
		}
		if(strcmp(current->name, getridof) == 0)//if the while loop ends-- it's either because current->next is null or we've found a match to 'getridof'
		{
			previous->next = current->next;
			remove_one(current);
		//	delete current->next;
			cout << "Activity removed\n";
		}
		//current->next is NULL
		else
		{
			cout << "Activity not found\n";
		}
	}
}

void schedule::search()
{
	node *temp, *copy, *current;
	char search[100];

	cout << "Enter activity type to search for: ";
	cin.get(search, 100, '\n');
	cin.ignore(100, '\n');
	
	if(!head)
	{
		cout << "No activities\n";
	}
	
	else //if there are nodes in the linked list
	{
		temp = head;
		while(temp) //continue if temp node has info
		{
			if(strcmp(temp->type, search) != 0)//keep on going if the type isnt what we're looking for 
			{
				temp = temp->next;
		//		if(temp == NULL)
		//		{
		//			cout << "'" << search << "'" << " not found\n";
		//		}
			}
				
			//if we hit the end of the list and no hits were found, it doesn't really matter
			else if(strcmp(temp->type, search) == 0 && temp != NULL)
			{
				//make a copy of the node.. copy everything
				copy = new node;
			
				copy->name = new char[strlen(temp->name) + 1];
				strcpy(copy->name, temp->name);
				copy->type = new char[strlen(temp->type) + 1];
				strcpy(copy->type, temp->type);
				copy->location = new char[strlen(temp->location) + 1];
				strcpy(copy->location, temp->location); 		
				copy->date = new char[strlen(temp->date) + 1];
				strcpy(copy->date, temp->date);
				copy->time = new char[strlen(temp->time) + 1];
				strcpy(copy->time, temp->time);
				copy->duration = temp->duration;
				
				//if headcopy is currently empty	
				if(!headcopy)
				{
					copy->next = NULL;
					headcopy = copy;
/*					headcopy = new node;
					headcopy->name = copy->name;
					headcopy->type = copy->type;
					headcopy->location = copy->location;
					headcopy->date = copy->date;
					headcopy->time = copy->time;
					headcopy->duration = copy->duration;
					headcopy->next = NULL;
*/
				}
				//if the copyname is lower, it needs to go in front
				else if(strcmp(headcopy->name, copy->name) < 0) 
				{
					copy->next = headcopy;
					headcopy = copy;
				}
				//if copyname is bigger, it has to go somewhere in the back
				else
				{	
					current = headcopy;
					//keep going through the linked list until we get to a spot where the next name is bigger than copyname
					while(current->next && strcmp(current->next->name, copy->name) > 0) 
					{	
						current = current->next;
					}
					//at this point, we connect the wires
					copy->next = current->next;
					current->next = copy;
				}
				temp = temp->next;
			}
		}
	}
//print out all the things that made it into headcopy list
	if(headcopy)
	{
		temp = headcopy;
		while(temp)
		{
			display_one(temp);
			temp = temp->next;
		}
	}
		
//delete everything we used

	if(headcopy)
	{
		temp = headcopy;
		current = headcopy;
		while(temp)
		{
			current = temp;
			temp = temp->next;
			remove_one(current);
		}
		headcopy = NULL;
	}
}

void menu()
{
	cout << "Activity Scheduler:\n\t1. Add activity\n\t2. Print all activities\n\t3. Search for activity type\n\t4. Remove an activity\n\t5. Exit\n\n";
}

int menu_option()
{
	int select;
	cout << "Enter menu selection: ";
	cin >> select;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid selection. Enter menu selection: ";
		cin >> select;
	}
	cin.ignore(100, '\n');
return select;
}
/*
int main(void)
{
	schedule stuff;
	int selection = 0;

	while(selection != 5)
	{
		menu();
		switch(selection = menu_option())
		{
			case 1: cout << '\n';
				stuff.add();
				break;	
			case 2: cout << '\n';
				stuff.display_all();
				break;
			case 3: cout << '\n';
				stuff.search();
				break;	
			case 4: cout << '\n';
				stuff.remove();
				break;
		}
	}
return 0;
}*/
