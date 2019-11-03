const int SIZE = 500;
struct Employee 
{
	char *name;
	char *title;
	char *description;
	char *paytype;
	int pay;
	int managerof;
	char **report;
};

class Company
{
	public:
		Company();	
		~Company();
		void add_employee(void);
		void search(void);
		void display_company(void);
	private:
		Employee company_list[SIZE];
		int number_of_employees;
};

void print_menu(void);
int menu_option(void);
