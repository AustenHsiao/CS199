//Austen Hsiao
//Assignment 2: Character database
//

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;
const int size = 50;

//structs are super lists
struct super_list
{
	char name[size];
	char surname[size];
	char occupation[size];
	char role[size];
	char relation_to_arthur[size];
};

//case 1. Load by file
int case1(super_list *a, int n)
{
	//set up loadfile and initialize variable(s)
	ifstream loadfile;
	char filename[size];
	int b = 0;

	cout << "\nInput files must be formatted as: (NAME)=(SURNAME)=(OCCUPATION)=(ROLE)=(RELATION TO ARTHUR)";
	cout << "\nEnter the filename you want to load:\n";
	cin.get(filename, size, '\n');
	loadfile.open(filename);
	while(!loadfile)
	{
		cin.clear();
		cin.ignore(size,'\n');
		cout << "File not found. Double check and re-enter the filename you want to load (Type 'exit' to return to menu):\n";
		cin.get(filename, size, '\n');
		cin.ignore(size, '\n');
		if(strcmp(filename,"exit") == 0)
		{
			return 0;
		}
		loadfile.open(filename);
	}

	loadfile.get(a[n].name,size,'=');
	loadfile.ignore();
	while(!loadfile.eof())	
	{
		loadfile.get(a[n].surname,size,'=');
		loadfile.ignore();
		loadfile.get(a[n].occupation,size,'=');
		loadfile.ignore();
		loadfile.get(a[n].role,size,'=');
		loadfile.ignore();
		loadfile.get(a[n].relation_to_arthur,size,'\n');
		loadfile.ignore(size,'\n');
		loadfile.get(a[++n].name,size,'=');
		++b;
		loadfile.ignore();	
	}	
	cout << "\n...File loaded successfully!\n";
//n is going to be how many characters (elements) are added to the list (array of structs). Return n so we can keep track of how many characters we have. It's n+1 because the indexing starts at 0
return b;
}

//Case 2 is adding new characters. Can add multiple, but at least must add 1
int case2(super_list *a, int n)
{
	char answer1;
	int characters_added = 1;

	cout << "\n\nAre you entering multiple characters? (Y/N)\n";
	cin >> answer1;
	cin.ignore(size,'\n');
	if(answer1 == 'Y' || answer1 == 'y')
	{
		cout << "How many characters are you adding?\n";
		cin >> characters_added;
		cin.ignore(size,'\n');
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(size,'\n');
			cout << "Invalid input. How many characters are you adding?\n";
			cin >> characters_added;
		} 
	}
	else
	{
		cout << "\nEntering 1 character...\n";
	}
	for(int i = 0; i < characters_added; ++i)
	{
		cout << "Enter character" << i + 1 << "'s name:\n";		
		cin.get(a[n+i].name, size, '\n');
		cin.ignore(size, '\n');

		cout << "Enter character" << i + 1 << "'s surname:\n";
		cin.get(a[n+i].surname, size, '\n');
		cin.ignore(size, '\n');

		cout << "Enter character" << i + 1 << "'s occupation:\n";
		cin.get(a[n+i].occupation, size, '\n');
		cin.ignore(size, '\n');
		
		cout << "Enter the character" << i + 1 << "'s role:\n";
		cin.get(a[n+i].role, size, '\n');
		cin.ignore(size, '\n');
		
		cout << "Enter the character" << i + 1 << "'s relation to Arthur:\n";
		cin.get(a[n+i].relation_to_arthur, size, '\n');
		cin.ignore(size, '\n');
	}
	cout << "\n...List updated successfully!\n";
return characters_added;	
}

//Case 3: search by name or surname
void case3(super_list *a, int n)
{
	int one_or_two;
	char filter_name[size];
	int len;

	cout << "\n\nEnter 1 to search by first name OR enter 2 to search by surname:\n";
	cin >> one_or_two;
	cin.ignore(size, '\n');
	while(one_or_two != 1 && one_or_two != 2)
	{
		cin.clear();
		cin.ignore(size, '\n');
		cout << "\nInvalid input. Enter '1' to search by first name OR enter '2' to search by surname:\n";
		cin >> one_or_two;
		cin.ignore(size, '\n');
	} 
	if(one_or_two == 1)
	{
		cout << "\nSearch by first name. Enter a name:\n";
		cin.get(filter_name, size, '\n');
		cin.ignore(size, '\n');
		cout << "\n\n::SEARCH RESULTS::\nNAME = SURNAME = OCCUPATION = ROLE = RELATION TO ARTHUR\n\n";
		for(int i = 0; i < n; ++i)
		{
			len = strlen(a[i].name);
			for(int j = 0; j < len; ++j)
			{
				a[i].name[j] = tolower(a[i].name[j]);
			}	
			if(strcmp(a[i].name, filter_name) == 0)
			{
				cout << a[i].name << " = " << a[i].surname << " = " << a[i].occupation << " = " << a[i].role << " = " << a[i].relation_to_arthur << '\n';
			}
		}
	}
	else if(one_or_two == 2)
	{
		cout << "\nSearch by surname. Enter a surname:\n";
		cin.get(filter_name, size, '\n');
		cin.ignore(size, '\n');
		cout << "NAME = SURNAME = OCCUPATION = ROLE = RELATION TO ARTHUR\n";
		for(int i = 0; i < n; ++i)
		{
			len = strlen(a[i].surname);
			for(int j = 0; j < len; ++j)
			{
				a[i].surname[j] = tolower(a[i].surname[j]);
			}	
			if(strcmp(a[i].surname, filter_name) == 0)
			{
				cout << a[i].name << " = " << a[i].surname << " = " << a[i].occupation << " = " << a[i].role << " = " << a[i].relation_to_arthur << '\n';
			}
		}
	}
}

//Display all results
void case4(super_list *a, int n)
{	
	cout << "\n\nCHARACTER LIST = NAME = SURNAME = OCCUPATION = ROLE = RELATION TO ARTHUR\n\n";
	for(int i = 0; i < n; ++i)
	{
		cout <<  a[i].name << " = " << a[i].surname << " = " << a[i].occupation << " = " << a[i].role << " = " << a[i].relation_to_arthur << '\n';
	}
}

//save to an output file
void case5(super_list *a, int n)
{
	char filename[size];
	ofstream fout;

	cout << "Save as filename:\n";
	cin.get(filename, size, '\n');
	cin.ignore(size, '\n');
	fout.open(filename, ios::app);
	fout << "_________________________________________________________________________________________________";
	fout << "\n\nCHARACTER LIST\nNAME=SURNAME = OCCUPATION = ROLE = RELATION TO ARTHUR\n\n";
	for(int i = 0; i < n; ++i)
	{
		fout << a[i].name << " = " << a[i].surname << " = " << a[i].occupation << " = " << a[i].role << " = " << a[i].relation_to_arthur << '\n';
	}
	fout << "\n_________________________________________________________________________________________________";
	cout << "\n...File saved successfully!\n";
}

int main_menu(void)
{
	int select = 0;

	cout << "\tMENU OPTIONS:\n";
	cout << "\t1. Load an external file\n";
	cout << "\t2. Add character(s) to the database\n";
	cout << "\t3. Search for a character by name or surname\n";
	cout << "\t4. Display all characters\n";
	cout << "\t5. Save As... and exit program\n";
	cout << "\t6. Quit without saving\n";
	cout << "Select an option (1-6):\n\n";
	cin >> select;
	cin.ignore(size,'\n');
	while(cin.fail() || select > 6 || select < 1)
	{
		cin.clear();
		cin.ignore(size, '\n');
	cout << "Invalid input. Please select an option (1-6):\n";
		cin >> select;
		cin.ignore(size, '\n');
	} 
return select;	
}

int main(void)
{
	//Description
	cout << "\nThis program serves as an index for the characters in the children's show, \"Arthur\";\ndesigned for children and people who grew up without cable.\n"; 	
	
	//initialize the struct
	super_list Arthur[size];
	int number_of_characters = 0;
	int select = 0;

	do
	{
		cout << "\n";
		select = main_menu();
		cout << '\n';
		switch(select)
		{
			//load external file 
			case 1 : number_of_characters = number_of_characters + case1(Arthur, number_of_characters);
				 break;
			//enter characters + data manually
			case 2 : number_of_characters = number_of_characters + case2(Arthur, number_of_characters);
				 break;
			//search by character name
			case 3 : case3(Arthur, number_of_characters);
				 break;
			//display all characters in the current list
			case 4 : case4(Arthur, number_of_characters);
				 break;
			//save and quit
			case 5 : case5(Arthur, number_of_characters);
				 break;
			//quit without saving
			case 6 : return 0;
		}			
	}
	while(select != 5);
return 0;
}
