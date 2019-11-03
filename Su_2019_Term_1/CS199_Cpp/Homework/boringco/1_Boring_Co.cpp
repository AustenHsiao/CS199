#include <iostream>
#include <cctype>
#include <cstring>
#include "1_Boring_Co.h"

using namespace std;

//Display all attributes for employee a
void display(Employee &a)
{
	cout << "\n" << a.name << '\t' << a.title << '\t' << a.description << "\t\t" << a.paytype << '\t' << a.pay << "\t\n";
	cout << a.name << " manages: ";

	for(int i = 0; i < a.managerof; ++i)
	{
		cout << a.report[i] << ' ';
	}
	if(a.managerof == 0)
	{
		cout << "Does not manage any employees";
	}
	cout << "\n";
}

//Company constructor
Company::Company()
{
	//When a new company is made, the default number of employees is 0
	number_of_employees = 0;
}
		
//Company destructor
Company::~Company()
{
	for(int i = 0; i < number_of_employees; ++i)
	{
		delete []company_list[i].name;
		delete []company_list[i].title;
		delete []company_list[i].description;
		delete []company_list[i].paytype;
		for(int j = 0; j < company_list[i].managerof; ++j)
		{
			delete []company_list[i].report[j];
		}
		delete []company_list[i].report;
	}	
}

//for a new employee, this function goes through each attributes and asks the user to input them
//strings are allocated dynamically		
void Company::add_employee()
{
	//buffer is a holder for any strings
	char buffer[100];
	//create an employee variable pointer to the company_list so I can access the variables within the employeestruct
	Employee *employee_list = &company_list[number_of_employees];
	
	//Get name			
	cout << "\nEnter employee name: ";
	cin.get(buffer, 100, '\n');	
	cin.ignore(100, '\n');	
	//allocate just enough space in memory for their name; (*employee_list).name
	employee_list->name = new char[strlen(buffer) + 1];
	//copy the name from the static holder to address in heap
	strcpy(employee_list->name, buffer);
	//Get title
	cout << "Enter employee title: ";
	cin.get(buffer, 100, '\n');
	cin.ignore(100, '\n');
	employee_list->title = new char[strlen(buffer) + 1];
	strcpy(employee_list->title, buffer);
	//Get description
	cout << "Enter employee job description: ";
	cin.get(buffer, 100, '\n');
	cin.ignore(100, '\n');
	employee_list->description = new char[strlen(buffer) + 1];
	strcpy(employee_list->description, buffer);
	//Get pay type
	cout << "Enter employee pay type (hourly or salary): ";
	cin.get(buffer, 100, '\n');		
	employee_list->paytype = new char[strlen(buffer) + 1];
	strcpy(employee_list->paytype, buffer);
	//Get pay
	cout << "Enter employee's pay rate: ";
	cin >> employee_list->pay;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input. Enter employee's pay rate: ";
		cin >> employee_list->pay;
	}		
	cin.ignore(100, '\n');
	//Get managed employees
	cout << "Enter the number of people this employee will manage: ";
	cin >> employee_list->managerof; 
	while(employee_list->managerof > 4 || employee_list->managerof < 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input. Enter the number of people this employee will manage: ";
		cin >> employee_list->managerof;
	}		
	employee_list->report = new char*[employee_list->managerof];
	cin.ignore(100,'\n');
	for(int i = 0; i < employee_list->managerof; ++i)
	{
		cout << "Enter name of managed employee " << i+1 << ": "; 
		cin.get(buffer, 100, '\n');
		cin.ignore(100, '\n');
		employee_list->report[i] = new char[strlen(buffer) + 1];
		strcpy(employee_list->report[i], buffer);
	}
	number_of_employees++;
	cout << '\n';
} 

//search function. Unfortunately case sensitive
void Company::search()
{
	char search[100];

	cout << "\nEnter employee name to find: ";
	cin.get(search, 100, '\n');
	cin.ignore(100, '\n');
	
	cout << "\nName\tTitle\tDescrip\t\tPayType\tPayRate\n"; 
	for(int i = 0; i < number_of_employees; ++i)
	{
		if(strcmp(search, company_list[i].name) == 0)
		{
			display(company_list[i]);
		}
	}
	cout << '\n';
}

//Display everything. Since we're keeping track of the number of employees in the company, display is called from 0-(number of employees)
void Company::display_company()
{
	cout << "\nName\tTitle\tDescrip\t\tPayType\tPayRate\n"; 
	for(int i = 0; i < number_of_employees; ++i)
	{
		display(company_list[i]);
	}
	cout << '\n';
}	

//Displays the menu itself
void print_menu(void)
{
	cout << "Boring Co. Directory\n";
	cout << "Menu options:\n" << "\t1.Enter new employee\n" << "\t2.Search for employee\n" << "\t3.Print company directory\n" << "\t4.Exit program\n";
}

//returns the user's menu selection
int menu_option(void)
{
	int menu_select;

	cout << "Select a menu option: ";
	cin >> menu_select;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "Invalid input. Select a menu option: ";
		cin >> menu_select;
	}
	cin.ignore(100, '\n');
return menu_select;
}

