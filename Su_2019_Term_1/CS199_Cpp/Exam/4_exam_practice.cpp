#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
const int SIZE = 100;

void getphrase(char a[])
{
	cout << "Enter a phrase:\n";
	cin.get(a, SIZE, '\n');
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(SIZE, '\n');
		cout << "Enter a phrase:\n";
		cin.get(a, SIZE, '\n');
	}
return;
}

int lookfore(char a[])
{
	int len = strlen(a), counter = 0;
	
	for(int i = 0; i < len; ++i)
	{
		if(a[i] == 'e')
		{
			counter++;
		}
	}
return counter;
}

int main(void)
{
	//Variables
	char message[SIZE];

	//Get phrase and count es	
	getphrase(message);
	cout << "The number of 'e's is " << lookfore(message) << '\n';

return 0;
}
