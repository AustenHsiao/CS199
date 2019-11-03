struct node
{
	char *name;
	char *type;
	char *location;
	char *date;
	char *time;
	int duration;	
	node *next;
};

class schedule
{
	public:
		schedule();
		~schedule();
		void add();
		void display_all();
		void display_one(node *a);
		void search();
		void remove();
		void remove_node(node *a);
		void check();
		void remove_one(node *a);
	private:
		node *head;
		node *headcopy;
};

void menu();
int menu_option();
