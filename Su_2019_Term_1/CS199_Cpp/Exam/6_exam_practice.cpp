#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
const int SIZE = 100;

void get_message(char a[])
{
	cout << "Enter a message:\n";
	cin.get(a, SIZE, '\n');
	cin.ignore(SIZE, '\n');
return;
}

void reverse(char a[], char out[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		out[i] = a[n-i-1];
	}
	out[n+1] = '\0';
return;
}

int main(void)
{
	char message[SIZE], reversed[SIZE];
	int len;
	get_message(message);
	len = strlen(message);
	reverse(message, reversed, len);
	for(int i = 0; i < len; ++i)
	{
		cout << reversed[i];
	}	 
	cout << '\n';
return 0;
}
