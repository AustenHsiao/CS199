//Assignment 3
//Austen Hsiao
//This program is used to organize a business
//There are 3 main functions, (1) add employee, (2) search database by employee name, (3) display database
//functions are declared in 1_Boring_Co.h and defined in 1_Boring_Co.cpp

#include <iostream>
#include <cstring>
#include <cctype>
#include "1_Boring_Co.h"

using namespace std;

int main(void)
{
	Company boring_company;
	int selection = 0;

	while(selection != 4)
	{
		print_menu();
		selection = menu_option();
		
		switch(selection)
		{
			case 1 : boring_company.add_employee();
			break;  
			case 2 : boring_company.search();
			break;
			case 3 : boring_company.display_company();
			break; 
		}
	}
	
return 0;
}
