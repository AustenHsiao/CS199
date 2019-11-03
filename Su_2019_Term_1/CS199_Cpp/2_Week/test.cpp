#include <iostream>

using namespace std;
const int SIZE = 50;

struct animals
{
	char name[SIZE];
	int population;
};	

void input(animals &a, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << "Enter a name for the animal:\n";
		cin.get(a[i].name, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		cout << "Enter population:\n";
		cin >> a[i].population;
		cin.ignore();
	}
}

int main(void)
{
//	animals a[SIZE] = animals mammals[SIZE];
	animals mammals[SIZE];
	input(mammals, 2);
//	cout << mammals << '\n';
//	cout << a << '\n';
return 0;
}
