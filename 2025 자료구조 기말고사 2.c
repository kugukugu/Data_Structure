#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define NOTOK -1

struct mystr
{
	struct mystr *next, *prev;
	int age;
	char name[128];
};

struct mystr *head = 0;

int add(char *name, int age)
{
	struct mystr *ptr;
	struct mystr *new = malloc(sizeof(struct mystr));
	if(new==NULL)
	{
		printf("fail to malloc.1\n");
		return NOTOK;
	}

	new->age=age;
	strcpy(new->name, name);
	new->next=NULL;
	new->prev=NULL;
	
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		for(ptr=head; ptr->next!=NULL; ptr=ptr->next)
			;
		ptr->next=new;
		new->prev=ptr;
	}

	return OK;
}

int delete(char *name)
{
	struct mystr *test;

	for(test=head; test!=NULL; test=test->next)
	{
		if(strcmp(name, test->name)==0)
		{
			if(test->prev==NULL)
			{
				head=test->next;
				if(head!=NULL)
				{
					head->prev=NULL;
				}
			}
			else
			{
				test->prev->next=test->next;
				if(test->next!=NULL)
				{
					test->next->prev=test->prev;
				}
			}
			free(test);

			return OK;
		}
	}

	return NOTOK;
}

void reverse(void)
{
	struct mystr *current, *next, *last;

	for(last=head; last->next!=NULL; last=last->next)
	;

	current=head;

	while(head!=NULL)
	{
		next = current->next;
		head=next;
		current->next=current->prev;
		current->prev=next;
		current = next;
	}

	head=last;
}

int insert(char *toname, char *name, int age)
{
	struct mystr *test;
	struct mystr *new = malloc(sizeof(struct mystr));

	new->age=age;
	strcpy(new->name,name);
	new->next=NULL;
	new->prev=NULL;

	printf("--Insert[%s] before[%s]--\n\n", name, toname);

	for(test=head; test!=NULL; test=test->next)
	{
		if(strcmp(toname, test->name)==0)
		{
			if(test->prev==NULL)
			{
				test->prev=new;
				head=new;
				new->next=test;
			}
			else
			{
				new->next=test;
				new->prev=test->prev;
				new->prev->next=new;
				new->next->prev=new;	
			}
			return OK;
		}
	}
	
	return NOTOK;
}

void print(void)
{
	struct mystr *test;

	printf("--print list----\n");

	for(test=head; test!=NULL; test=test->next)
	{
		printf("name=[%s]\tage=[%d]\n", test->name, test->age);
	}
	printf("\n");

}

int main()
{
	add("kim", 21);
	add("hong", 23);
	add("park", 20);
	add("lee", 22);
	print();

	delete("hong");
	print();

	insert("lee", "choi", 21);
	print();

	reverse();
	print();

	return 0;
}
