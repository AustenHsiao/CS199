#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

struct node
{
	int value;
	node *next;
};

class stuff
{
	public:
		stuff()
		{
			head = NULL;		
		}
		
		void add(int x)
		{
			node *current, *previous;			

			if(!head)
			{
				head = new node;
				head->value = x;
				head->next = NULL;
			}
			else
			{
				current = head->next;
				previous = head;
				while(current)
				{	
					previous = current;
					current = current->next;
				}
				current = new node;
				current->value = x;
				current->next = NULL;
				previous->next = current;
			}
		}

		int count_nodes(void)
		{
			int count = 0;
			node *temp;
		
			temp = head;
			while(temp)
			{
				++count;
				temp = temp->next;
			}
		return count;
		}

		void insert_middle(int x) //FUNCTION FOR QUESTION 1; inserts a node in the middle of the LL
		{
			node *temp, *insert;
			int index;

			if(!head)
			{
				head = new node;
				head->value = x;
				head->next = NULL;
			}
			else
			{
				index = int(count_nodes())/int(2);
				temp = head;
				for(int i = 0; i < index-1; ++i)
				{
					temp = temp->next;
				}
				insert = new node;
				insert->value = x;
				insert->next = temp->next;
				temp->next = insert;
			}
		}
	
		void remove_divisible_3() //FUNCTION FOR QUESTION 2; removes any nodes that are divisible by 3
		{
			node *current, *previous;

			if(!head)
			{
				cout << "No list\n";
			}
			else if ((head->value)%3 == 0 && head->next == NULL)
			{
				head = NULL;
			}
			else
			{
				previous = head;
				while((previous->value)%3 == 0)
				{
					head = previous->next;
					delete previous;
					previous = head;
				}
				current = previous;
				while(current != NULL && previous != NULL)
				{	
					current = previous->next;
					if((current->value)%3 == 0)
					{
						previous->next = current->next;
						delete current;
						
					}
					previous = previous->next;
				}
			}
		}

		void add_evenodd(int x) //FUNCTION FOR QUESTION 3: Makes a linked list where all evens are first (in the order they were entered) followed by the odds. Begins with an empty head
		{
			node *current, *temp;
			int eo = x % 2;
			
			if(!head)
			{
				head = new node;
				head->value = x;
				head->next = NULL;
			}
			else
			{
				if(eo == 0) //EVEN
				{
					temp = new node;
					temp->value = x;

					current = head;
					while(current && current->next != NULL && (current->next->value) % 2 == 0)
					{
						current = current->next;
					}
					temp->next = current->next;
					current->next = temp;				
				}
				else //eo == 1
				{
					temp = new node;
					temp->value = x;

					current = head;
					while(current->next != NULL)
					{
						current = current->next;
					}
					temp->next = current->next;
					current->next = temp;				
				}
			}
		}

		void remove_everyother() //FUNCTION FOR QUESTION 4: Removes every other node in the linked list
		{
			node *current, *previous, *temp;
			
			current = head;
			previous = head;
			temp = head;
			if(!head)
			{
				cout << "No list\n";
			}
			else
			{
				current = head->next;
				while(current)
				{
					temp = current;
					current = current->next;
					delete temp;
					previous->next = current;
					previous = current;
					if(current)
					{
						current = current->next;
					}
				}

			}
		}
		
		void display_one(node *a)
		{
			cout <<  a->value << ' ';
		}

		void reverse() //FUNCTION FOR QUESTION 5: Reverse a linked list; create a new linked list, adding from the back, then take out from the front to reverse i?
		{
		}

		void display(void)
		{
			node *temp;
			temp = head;
			
			while(temp)
			{
				cout << temp->value << ' ';
				temp = temp->next;
			}
			cout << '\n';
		}
	private:
		node *head;
};

int main(void)
{
	//create a linked list
	stuff list;
//	for(int i = 0; i < 11; ++i)
//	{
//		list.add(i);
		//list.add_evenodd(i);
//	}
	list.add(0);
	list.add(1);
	list.insert_middle(10);
//	list.remove_divisible_3();
//	list.remove_everyother();
	list.display();
//	list.reverse(head);

}
