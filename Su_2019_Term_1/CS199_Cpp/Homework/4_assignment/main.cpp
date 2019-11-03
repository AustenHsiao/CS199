//Austen Hsiao
//Assignment 4: activity list
//This program allows users to organize their activities. They can add or remove an entry, print all activities, and filter all activities by type

#include <iostream>
#include <cctype>
#include <cstring>
#include "activities.h"

using namespace std;

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
}
