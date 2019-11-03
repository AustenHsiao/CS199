#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 10;

int ciin(void)
{
	int n;
	cout << "Enter a number for the list:\n";
	cin >> n;
	cin.ignore(SIZE,'\n');
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(SIZE,'\n');
		cout << "Enter a number for the list:\n";
		cin >> n;
	}
return n;
}

int sum_divisible(int n[])
{
	int sum = 0;
	for(int i = 0; i < SIZE; ++i)
	{
		if(n[i] % 3 != 0)
		{
			n[i] = 0;
		}
	}
	for(int a = 0; a < SIZE; ++a)
	{
		sum = sum + n[a];
	}
return sum;
}

int main(void)
{
	int number_list[SIZE];
	int number;
	for(int i = 0; i < SIZE; ++i)
	{
		number = ciin();
		number_list[i] = number;
	}
	cout << '\n';
	cout << sum_divisible(number_list);
	cout << '\n';
return 0;
}
