//Write a function that takes in a integer 0- 100 that determines the users grade (<60 -> F, <70 -> D, <80 -> C , etc)
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

char user_letter_grade(int grade)
{
	char letter;
	int reduced_grade = grade / 10;
	switch(reduced_grade)
	{
		case 0 : 
		case 1 : 
		case 2 :
		case 3 :
		case 4 :
		case 5 : letter = 'F';
			 break; 
		case 6 : letter = 'D';
			 break;
		case 7 : letter = 'C';
			 break;
		case 8 : letter = 'B';
			 break; 
		case 9 :
		case 10: letter = 'A';
			 break;
		default: letter = '?';
	}
return letter;
}

int user_grade(void)
{
	int grade;
	cout << "Enter grade percentage:\n";
	cin >> grade;
	cin.ignore(100,'\n');
return grade;
}

int main()
{
	int percent_grade;
	percent_grade = user_grade();
	cout << "Grade: " << user_letter_grade(percent_grade) << '\n';	
return 0;
}
