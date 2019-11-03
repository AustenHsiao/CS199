int count(node *head)
{
	if(!head)
	{
		return 0;
	}
	else if(head->next = NULL)
	{
		return 1;
	}	
	head = head->next;
	return 1 + count(head); 
}

bool search(
