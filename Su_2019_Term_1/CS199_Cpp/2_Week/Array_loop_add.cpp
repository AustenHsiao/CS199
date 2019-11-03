//Write a function that takes in an array and the length. Returns the sum of the elements
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int sum_of_array(int length, char string[])
{
	int sum = 0;
	for(int i = 0; i < length; ++i)
	{	
		sum = sum + string[i];
	}
return sum;
}

int main()
{
	char list[] = {5, 4, 3, 2, 1};
	int len = strlen(list);
	cout << '\n' << sum_of_array(len, list) << '\n';
return 0;
}
