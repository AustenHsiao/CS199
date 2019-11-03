//Write a function that takes in user input up to 100 numbers, only taking in even numbers between 50 and 100

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//They can input 100 numbers by passing in an array
int even_number(int len, int array[100], int output[])
{
	int n = 0;
	for(int i = 0; i < len; ++i)
	{
		if(array[i] > 50 && array[i] < 100 && array[i] % 2 == 0)
		{
			output[n] = array[i];
			++n;
		}
	}	
return n;
}

int main()
{
	int list_input[101] = {1,2,3};
	int len;
	int list_output[101] = {0};
	for(int i = 0; i < 101; ++i)
	{
		list_input[i] = i;
	}	
	len = even_number(100, list_input, list_output);
	for(int i = 0; i < len; ++i)
	{
		cout << list_output[i] << ' ';
	}
	cout << '\n';
return 0;
}
