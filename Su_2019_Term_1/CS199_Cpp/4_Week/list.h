struct node
{
	//in each node value, we have a value and we have the address of the next node
	int value;
	node *address;
};

class linked_list
{
	//class linked_list encapsulates our linked list
	public:
		linked_list();
		void addfront(int);
//		void addback(int);
		void display();
		void displaylast();
		void everyother();
	private:
		node *head;
};
