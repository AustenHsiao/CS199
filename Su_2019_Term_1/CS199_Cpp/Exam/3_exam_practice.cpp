#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 10;

int even_sort(int a[], int even[])
{
	int count = 0;
	for(int i = 0; i < SIZE; ++i)
	{	
		if(a[i] % 2 == 0)
		{
			even[count++] = a[i];
		}
	}
return count;
}

int odd_sort(int a[], int odd[])
{
	int count = 0;
	for(int i = 0; i < SIZE; ++i)
	{	
		if(a[i] % 2 != 0)
		{
			odd[count++] = a[i];
		}
	}
return count;
}

void merge(int even[], int n, int odds[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		even[n+i] = odds[i];
	}
return;
}

int main(void)
{
	//Variables
	int number_list[SIZE], even[SIZE], odd[SIZE], number = 0, even_numbers, odd_numbers;
	
	//Input list elements
	for(int i = 0; i < SIZE; ++i)
	{
		cout << "Enter number " << i << " for the list:\n";
		cin >> number;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n'); 
			cout << "Enter number " << i << " for the list:\n";
			cin >> number;
		}
		number_list[i] = number;
	}

	//Sort into respective lists, save the number of even and odd numbers	
	even_numbers = even_sort(number_list, even);
	odd_numbers = odd_sort(number_list, odd);

	//Merge
	merge(even, even_numbers, odd, odd_numbers);

	//Display
	for(int i = 0; i < SIZE; ++i)
	{
		cout << even[i] << ' ';
	}
	cout << '\n';
return 0;
}
