//Restuarant menu struct function

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
const int size = 50;

struct menu
{
	char name[size];
	char price[size];
};

int add_entry(int n , menu & menu_list)
{
	cout << "Enter a name for the entry:\n";
	cin.get(menu_list.name, size, '\n');
	cin.ignore(100, '\n');
	
	cout << "Enter a price for the entry:\n";
	cin.get(menu_list.price, size, '\n');
	cin.ignore(100, '\n');;	
return 1;
}

int keep_going(void)
{
	char answer;

	cout << "Do you have more entries to input? (Y/N):\n";
	cin >> answer;
	cin.ignore(100,'\n');
	if(answer == 'Y' || answer == 'y')
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

void display_menu(menu& menu_list)
{	
//	for(int i = 0; i < n; ++i)
//	{
	cout << menu_list.name << '\t' << menu_list.price << '\n';
//	}
}


int main(void)
{
	//declare
	menu restaurant[size];	
	int n = 0;

	//add things to it
	do
	{
		n = n + add_entry(n, restaurant[n]);
		
	}
	while(keep_going() != 0);
	cout << '\n';
	cout << "________________MENU_______________\n";
	for(int i = 0; i < n; ++i)
	{
		display_menu(restaurant[i]);
	}
return 0;
}
