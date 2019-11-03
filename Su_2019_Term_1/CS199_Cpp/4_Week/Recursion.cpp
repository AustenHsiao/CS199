#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

//return true if all numbers in an array are even// Answer given by Jeff
bool even_array(int a[], int length)
{
	if(length == 0)
	{
		return true;
	}
	return (a[length - 1] % 2 == 0 && even_array(a, length - 1));
	//if we pass in {1,2,3,4}. The list is not length == 0, so it only executes the last return line (13). It checks the parity of the last number (TRUE), then checks the parity of the last number if we reduce the end index by 1-- so we're checking the second to last number (FALSE). It keeps doing this and ''anding'' the logic together, so if there are any FALSE statements, it will return FALSE.
}	

//check if a word is a palindrome
bool palindrome(char *a, int first, int numelements)
{	
	//If the string is empty or contains 1 char, its a palindrome
	if((numelements-first) == 0 || (numelements-first) == 1)
	{
		return true;
	}	
	//if first and last are equal, return TRUE&&if the next and second to last are equal, etc
	return (a[first]==a[numelements-1]) && palindrome(a, ++first, --numelements);
}

//Sum the digits of a number
int recursive_sum(int number, int digits)
{
	int div;
	
	if(digits == 0)
	{return 0;}
	if(digits == 1)
	{return number;}
	div = pow(10,digits-1);
	return number/div + recursive_sum(number%div, --digits);;
}	

int string_len(char *a, int index)
{
	if(!a[index])
	{
		return 0;
	}
//	if(a[index])	
//	{
//		return 1;
//	}
	return 1 + string_len(a, ++index); 

}

int main(void)
{
	char buffer[500];
	char *d_string;
	int length;

	int a[] = {1,2,3,4};

/*Return true if all numbers in the array are even
	if(even_array(a, 4) == true)
	{
		cout << "Is evens\n";
	}
	else
	{
		cout << "Has odds\n";
	}
*/	

/*palindrome
	cout << "Enter a word: ";
	cin.get(buffer,500,'\n');
	cin.ignore(500, '\n');
	
	d_string = new char[strlen(buffer) + 1];
	strcpy(d_string, buffer);

	length = strlen(d_string);

	if(palindrome(d_string, 0, length))
	{
		cout << "Is a palindrome.\n";
	}
	else {cout << "Is not a palindrome.\n";}
*/

/*recursive_sum
	cout << recursive_sum(123456,6) << '\n';
*/
/*recursive string length
	cout << "Enter a word: ";
	cin.get(buffer,500,'\n');
	cin.ignore(500, '\n');
	
	d_string = new char[strlen(buffer) + 1];
	strcpy(d_string, buffer);
	
	cout << string_len(d_string, 0) << '\n';
*/
return 0;
}
