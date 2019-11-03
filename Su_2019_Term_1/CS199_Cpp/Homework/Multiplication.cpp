/* 
Austen Hsiao
Assignment 1: Learn You A Multiplication For Great Good
DESC:
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));

	//Variables
	int last_correct, score, play, rand1, rand2, user_answer, diff, answer;
	char keep_playing; 
	play = 1, last_correct = 1;
	score = 0;

	//Rules of the game:
	cout << "\t ___________________________________________________________"
	     << "\n\t|This program is designed for practicing multiplication.    |\n" 
	     << "\t|The player will have up to three chances to get the correct|\n" 
	     << "\t|answer. If your answer gets closer, you will recieve a     |\n"
	     << "\t|maximum of three chances to get the correct answer.        |"
	     << "\n\t ___________________________________________________________\n";		

	while(play == 1) 
		{
		//DIsplay current score
		cout << "\nCurrent score is " << score << '\n';
		//Assign random integers (0-9) for rand1 and rand2
		rand1 = rand()%10;
		rand2 = rand()%10;
		//Display the phrase and prompt user for an answer
		cout << "\n" << rand1 << " x " << rand2 << " = ???\nEnter your answer: ";
		cin >> user_answer;
		cin.ignore(100,'\n');
		//the true answer is stored
		answer = rand1 * rand2;
		//If they get the answer correct, increment score by 1 and set last_correct to 1 so if they make a mistake next time, they will get a chance to give a new answer
		if(user_answer == answer)
			{
			cout << "Correct!\n";
			++score;
			last_correct = 1;
			}	
		//If the user_answer is within +/- 5 and the user got the last question correct, go through this else if 
		else if (user_answer != answer && user_answer <= answer + 5 && user_answer >= answer - 5 && last_correct == 1) 
			{
			diff = abs(answer - user_answer);
			cout << "Close, but not quite! Try again:\n";
			cin >> user_answer;
			cin.ignore(100,'\n');
			if (user_answer == answer) 
				{
				cout << "Correct!\n";
				++score;
				last_correct = 1;
				}
			//If the discrepancy increases, they're done
			else if (abs(answer - user_answer) > diff)
				{
				cout << "Incorrect\n";
				last_correct = 0;
				}
			else
				{
				cout << "Close, but not quite! Try one more time:\n";
				cin >> user_answer; 
				cin.ignore(100,'\n');
				//If they make it this far, if they dont give a correct answer, it doesn't matter
				if (user_answer == answer)
					{
					cout << "Correct!\n";
					++score;
					last_correct = 1;
					}
				else 
					{
					cout << "Incorrect\n";
					last_correct = 0;
					}
				}	
		 	}
		//If they're outside of the +/-5, it defaults to a loss
		else 
			{
			cout << "Incorrect\n";
			last_correct = 0;
			}
		//Ask if they want to keep playing
		cout << "Do you want to continue playing? (y/n): \n";
		cin >> keep_playing;
		cin.ignore(100,'\n');
		//If they want to keep playing, the while loop is maintained
		if (keep_playing == 'y' || keep_playing == 'Y')
			{
			play = 1;
			}
		//Otherwise, the while loop is broken and the final score is shown
		else
			{
			play = 0;
			cout << "\nFinal score: " << score << '\n'; 
			}
		}
	return 0;
}
