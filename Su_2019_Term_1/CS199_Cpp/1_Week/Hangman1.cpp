#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
const int max_size = 30;

//Takes any phrase and turns it into a series of underscores
void conceal(int len, char phrase[])
{
	for(int i = 0; i < len; ++i)
	{
		if(isalpha(phrase[i]) != 0)
		{
			phrase[i] = '_';
		}
		else
		{
			phrase[i] = ' ';
		}
	}
return;
}

//Shows the current state of the hangman puzzle
void show(int len, char phrase[])
{
	cout << '\n';
	for(int i = 0; i < len; ++i)
	{
		cout << phrase[i];
	}
	cout << '\n';
return;
}

//Checks a guess against the phrase
int guess(int len, char letter[], char phrase[], char compare[])
{
	int flag = 0;
	for(int i = 0; i < len; ++i)
	{
		if(letter[i] == compare[i])
		{
			phrase[i] = letter[0];
			flag = 1;
		}
	}
	if(flag == 0)
	{
		cout << "\nSorry, " << '"' << letter[0] << '"' << " is not in the phrase.\n";
		cout << '\n' << phrase << '\n';
		return 1;
	}
	else if(flag == 1)
	{
		cout << "\nGreat job, " << '"' << letter[0] << '"' << " is in the phrase.\n";
		cout << '\n' << phrase << '\n';
		return 0;
	}
return 0;
}

//Takes a guess and makes it a string of the first character so we can compare characters in a string to the original string
void make_long(int len, char letter[])
{
	for(int i = 0; i < len - 1; ++i)
	{
		letter[i+1] = letter[0];
	}
return;
}

//Displays current status of the game
void status(int counter)
{
	cout << '\n';
	if(counter == 6)
	{
		cout << "You have lost.\n";
	}
return;
}

//Draws the hangman based on the number of incorrect attempts
void hangman(int counter)
{
	if(counter > 0){cout << "¯";}
	if(counter > 1){cout << "\\_";}
	if(counter == 3){cout << "(  )";}
	else if (counter > 3){cout << "(ツ)";}
	if (counter > 4){cout << "_/";}
	if (counter > 5){cout << "¯";}    	
	cout << '\n';
return;
}

//Used to check if the player has won
int win_status(char phrase[], char compare[])
{
	if(strcmp(phrase, compare) == 0)
	{
		cout << "You win!\n";
		return 100;
	}
	else {return 0;}
}

//Clear the screen to hide the original phrase
void clear(void)
{
	for(int i = 0; i < 30; ++i)
	{
		cout << '\n';
	}
return;
}

//_________________________________________________

int main()
{
	char input_phrase[30], copied[30], letter[30];	
	int len;
	int guess_counter = 0;

//Game description
	cout <<"\nIn hangman, one person gives a phrase and\nthe second person must guess the phrase by\npicking single letters within 6 attempts.\n\n";

//Enter a phrase, maximum 30 characters. No punctuation or numbers
	cout << "Enter a phrase (Do not include punctuation and/or numbers):\n";
	cin.get(input_phrase,100,'\n');
	clear();
	len = strlen(input_phrase);
	strcpy(copied,input_phrase);
	conceal(len, input_phrase);
	show(len, input_phrase);
//make the copied string all lower case
	for(int i = 0; i < len; ++i)
	{
		copied[i] = tolower(copied[i]);
	}
//while the guess counter is not equal to 6, keep playing. If it equals 6, status(guess_counter) will tell us that we've lost
	while(guess_counter != 6)
	{
		cout << "_________________________\n";
		cout << "Enter a guess (1 letter): ";
		cin >> letter;
		cin.ignore(100,'\n');
		cout << "_________________________\n";
		make_long(len, letter);
		guess_counter = guess_counter + guess(len, letter, input_phrase, copied);
		status(guess_counter);
		hangman(guess_counter);
		guess_counter = guess_counter + win_status(input_phrase,copied);
		//Check to see if player has won
		if(guess_counter >= 100)
		{
			guess_counter = 6;
		}
	}	
return 0;
}
