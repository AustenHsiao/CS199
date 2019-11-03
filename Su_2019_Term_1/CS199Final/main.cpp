#include <iostream>
#include "list.h"
using namespace std;

int main(void)
{
  waiting_room w;
  int option;
  bool loop = true;

  while(loop)
  {
      cout << endl;
      cout << "1. Admit a new patient" << endl;
      cout << "2. Doctor available" << endl;
      cout << "3. Display triage list" << endl;
      cout << "4. Exit" << endl;
      cout << "-----------------------------------" << endl << endl;
      cout << "Enter an option: ";
      cin >> option;
      cin.ignore(100, '\n');
      switch(option)
      {
        case 1: w.admit_patient();  
                break;
        case 2: w.see_patient();    
                break;
        case 3: w.display();        
                break;
        case 4: loop = false;       
                break;
        default: cout << "Invalid selection." << endl; break;
      }

  }
  cout << "Goodbye" << endl;

  return 0;
}
