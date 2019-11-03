#include <iostream>
#include <cctype>
#include <cstring>
#include "list.h"

using namespace std;

int main(void)
{
	linked_list numbers;
//	numbers.addfront(5);
	numbers.addfront(4);
	numbers.addfront(3);
	numbers.addfront(2);
	numbers.addfront(1);
//	numbers.display();
//	cout << '\n';
	numbers.displaylast();
//	numbers.everyother();
	cout << '\n';
return 0;
}
