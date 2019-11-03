//Monte Carlo simulation to find the prbability of selecting a blue marble out of a bag of blue and green marbles.
//User will enter the number of trials, number blue marbles, and number of green marbles

#include <iostream>
#include <cctype>
#include <cstring> 
#include <cstdlib>
#include <ctime>

using namespace std;

int blue_marbles(void)
{
	int blue;
	cout << "Enter the number of blue marbles:\n";
	cin >> blue;
	cin.ignore(100,'\n');
return blue;
}

int green_marbles(void)
{
	int green;
	cout << "Enter the number of green marbles:\n";
	cin >> green;
	cin.ignore(100,'\n');
return green;
}

int num_trials(void)
{
	int trials;
	cout << "Enter the number of trials:\n";
	cin >> trials;
	cin.ignore(100,'\n');
return trials;
}

double blue_probability(int trials, int blue, int green)
{
	srand(time(0));
	int random, counter = 0;
	for(int i = 0; i < trials; ++i)
	{
		random = rand() % (blue + green) + 1;
//		cout << random;
		if(random <= blue)
		{
			++counter;
		}
	}
return double (counter/(1.0*trials));
}

int main()
{
	int blue, green, trials;
//	double blue_prob, green_prob;	

	trials = num_trials();
	blue = blue_marbles();
	green = green_marbles();
	
	cout << "The probability of drawing a blue marble in a bag of " << blue << " blue marbles and " << green << " green marbles, out of " << trials << " trials is: " <<  blue_probability(trials, blue, green);	
	cout << '\n';
return 0;
}
