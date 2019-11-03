#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 100;

void get_message(char message[])
{
	cout << "Enter a phrase:\n";
	cin.get(message,SIZE,'\n');
	cin.ignore(SIZE,'\n');
return;
}

void remove_things(char message[], char out[])
{
	int len = strlen(message), count = 0;
	for(int i = 0; i < len; ++i)
	{
		if(isalpha(message[i]) || isdigit(message[i]))
		{
			out[count++] = message[i];
		}
	}
return;
}

int main(void)
{
	char message[SIZE], new_message[SIZE] = {' '};
	int len;
	get_message(message);
	remove_things(message, new_message);
	len = strlen(new_message);
	for(int i = 0; i < len; ++i)	
	{
		cout << new_message[i];
	}	
	cout << '\n';	
return 0;
}
