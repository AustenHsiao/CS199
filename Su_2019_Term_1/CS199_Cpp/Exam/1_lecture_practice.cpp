//A function that takes in an array of integers(and the size of the array) and returns the sum of all the integers
int sum_of_array(char a[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		sum = sum + a[i];
	}
return sum;
}
//call from main example: sum_of_array(array, size); 

//A function that squares every element of an integer array. An array and the size (n) is passed
void square_of_array(char a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		a[i] = a[i] * a[i];
	}
return;
}
//call from main example: square_of_array(array, size);

//A function that capitalizes every vowel in a string
void capitalize_vowels(char a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		if(isalpha(a[i])
		{
			if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			{
				toupper(a[i]);
			}
		}
	}
return;
}
//call from main example: capitalize_vowels(string, size);
