//Midterm 1
//Austen Hsiao
//Cipher. User enters a phrase and how many letters to shift the message. The original message and the resulting coded message is returned

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 500;

//Prompt user for a message
void get_message(char a[])
{
	cout << "Enter a message:\n";
	cin.get(a, SIZE, '\n');
	cin.ignore(SIZE,'\n');
return;
}

int shift()
{
	int shiftnum = 0;
	cout << "Specify a shift (-25 to 25):\n";
	cin >> shiftnum;
	cin.ignore(SIZE, '\n');
	while(cin.fail() || shiftnum > 25 || shiftnum < -25)
	{
		cin.clear();
		cin.ignore(SIZE, '\n');
		cout << "Invalid input, specify a shift (-25 to 25):\n";
		cin >> shiftnum;
		cin.ignore(SIZE,'\n');
	}
//	while(shiftnum > 25 || shiftnum < -25)
//	{
//		cout << "Invalid input, specify a shift (-25 to 25):\n";
//		cin >> shiftnum;
//		cin.ignore(SIZE, '\n');	
//	}
return shiftnum;
}

int checklowernum(int a)
{
	if(a < 97)
	{
		while(a < 97)
		{
			a = a + 26;
		}
	}
	else if(a > 122)
	{
		while(a > 122)
		{
			a = a - 26;
		}
	}
return a;
}

int checkbiggernum(int A)
{
	if(A < 65)
	{
		while(A < 65)
		{
			A = A + 26;
		}
	}
	else if(A > 90)
	{
		while(A > 90)
		{
			A = A - 26;
		}
	}
return A;
}

void cipher(char a[], char b[], int shifty)
{
	int len = strlen(a), charnum;
	for(int i = 0; i < len; ++i)
	{
		if(isalpha(a[i]) && isupper(a[i]))
		{
			charnum = char(((int(a[i]) % 65) + shifty) + 65);
			b[i] = char(checkbiggernum(charnum));
		}
		else if(isalpha(a[i]) && islower(a[i]))
		{
			charnum = (((int(a[i]) % 97) + shifty) + 97);
			b[i] = char(checklowernum(charnum));
		}
		else
		{
			b[i] = a[i];
		}
	}
	//added 8/21/19. After mt
	b[len] = '\0';
return;
}

int main(void)
{
	char message[SIZE], secret[SIZE];
	int shiftnum, len;
	get_message(message);
	shiftnum = shift();
	cipher(message, secret, shiftnum);
	len = strlen(message);
	for(int i = 0; i < len; ++i)
	{
		cout << message[i];
	}
	cout << '\n';
	for(int j = 0; j < len; ++j)
	{
		cout << secret[j];
	}
	cout << '\n';	
return 0;
}
