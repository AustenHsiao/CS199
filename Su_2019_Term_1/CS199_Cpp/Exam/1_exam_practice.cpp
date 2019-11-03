#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
const int SIZE = 100;

void capitalize_first(char a[])
{
	int n = strlen(a);
	for(int i = 0 ; i < n; ++i)
	{
		if(isalpha(a[i]) != 0)
		{
			a[i] = tolower(a[i]);
		}

	}
	for(int i = 0 ; i < n; ++i)
	{
		if(a[i] == ' ')
		{
			a[i+1] = toupper(a[i+1]);
		}
	}
	if(isalpha(a[0]) != 0)
	{
		a[0] = toupper(a[0]);
	}
return;
}

int main(void)
{
	//init variable
	char message[SIZE];
	cout << "Enter a phrase:\n";
	cin.get(message,SIZE,'\n');
	cin.ignore(SIZE,'\n');
	
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(SIZE, '\n');
		cout << "Enter a phrase:\n";
		cin.get(message, SIZE, '\n');
	}
	capitalize_first(message);	
	cout << message << '\n';
return 0;
}
