struct node
{
  char *name;
  int priority;
  node *next;
};

class waiting_room
{
  public:
    waiting_room();
    ~waiting_room();
    void admit_patient(void);
    void see_patient(void);
    void display(void);
    void patient_info(node*);
  private:
    node *head;
};
