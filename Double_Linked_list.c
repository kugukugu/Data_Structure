#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    char* data;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* create_node(char* data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = (char*)malloc(strlen(data) + 1);
    strcpy(temp->data, data);

    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

void delete_node(Node* node)
{
    free(node->data);
    free(node);
}

int add_head(Node** head, Node** tail, char* data)
{
    Node* temp = create_node(data);
    if(temp == NULL)
    {
        return 0;
    }

    if ((*head) == NULL)
    {
        (*head) = temp;
        (*tail) = temp;
        return 1;
    }

    temp->next = (*head);
    (*head)->prev = temp;
    (*head) = temp;

    return 1;
}

void add_tail(Node** head, Node** tail, char* data)
{
    Node* temp = create_node(data);
    Node* test = (*head);

    if ((*head) == NULL)
    {
        (*head) = temp;
        (*tail) = temp;
        return;
    }

    while (test->next != NULL)
    {
        test = test->next;
    }

    temp->prev = test;
    test->next = temp;
    (*tail) = temp;
}

void add_tail_fast(Node** head, Node** tail, char* data)
{
    Node* temp = create_node(data);

    if ((*tail) == NULL)
    {
        (*head) = temp;
        (*tail) = temp;
        return;
    }

    temp->prev = (*tail);
    (*tail)->next = temp;
    (*tail) = temp;
}

int add_next(Node** head, Node** tail, char* target_data, char* data)
{
    Node* temp = create_node(data);
    Node* test, *tmp;

    for (test = (*head); test != NULL; test = test->next)
    {
        if (strcmp(test->data, target_data) == 0)
        {
           /* tmp = test->next;
            test->next = temp;*/
            temp->prev = test;
            temp->next = test->next;
            test->next = temp;

            if (temp->next != NULL)
            {
                temp->next->prev = temp;
            }

            return 1;
        }
    }

    return 0;
}

int add_before(Node** head, Node** tail, char* target_data, char* data)
{
    Node* temp = create_node(data);
    Node* test, *tmp;

    for (test = *head; test != NULL; test = test->next)
    {
        if (strcmp(test->data, target_data) == 0)
        {
            temp->prev = test->prev;
            temp->next = test;
            test->prev = temp;

            if (temp->prev != NULL)
            {
                temp->prev->next = temp;
            }

            return 1;
        }
    }

    return 0;
}

int add_index(Node** head, Node** tail, int index, char* data)
{
    int i;
    Node* temp = create_node(data);
    Node *tmp = (*head);

    for(i=0; i<index; i++) // = = =//2
    {
        tmp= tmp->next;
        if(tmp==NULL)
            break;
    }

    if(tmp == NULL)
    {
            if(index ==0)
                return add_head(head, tail, data);
            if((index-1)==i)
                add_tail_fast(head, tail, data);
            return 0;
    }

    if(index==0)
    {
        return add_head(head, tail, data);
    }

    temp->next = tmp;
    temp->prev = tmp->prev;
    tmp->prev = temp;
    temp->prev->next = temp;
}

int delete_target(Node** head, Node** tail, char* target_data)
{
    Node *test;

    for (test = *head; test != NULL; test = test->next)
    {
        if (strcmp(test->data, target_data) == 0)
        {
            if(test->prev == NULL)
            {
                (*head)=test->next;

                if(test->next ==NULL)
                {
                    (*tail)=NULL;
                }

                if((*head)!=NULL)
                {
                    (*head)->prev=NULL;
                }
            }
            else
            {
                test->prev->next = test->next;

                if(test->next !=NULL)
                {
                    test->next->prev = test->prev;
                }
            }
            free(test->data);
            free(test);

            return 1;
        }
    }
}

int delete_index(Node** head, Node** tail, int index)
{

}

Node* get_node_index_tail(Node** head, Node** tail, int index)
{

}

void delete_all(Node* head)
{
     Node* temp;

     while (head != NULL)
     {
         temp = head->next;
         delete_node(head);
         head = temp;
     }
}

void reverse_list(Node **head, Node** tail)
{
    Node *current=(*head),* temp;

    while(current!=NULL)
    {
        temp=current->next;
        current->next=current->prev;
        current->prev=temp;
        current=temp;
    }

    Node *tmp =(*head);

    (*head)=(*tail);
    (*tail)=tmp;
}

void print_linkedlist(Node *head)
{
    Node *test=head;

    while(test!=NULL)
    {
        printf("%s >>", test->data);
        test = test->next;
    }
}

void print_reverse_linkedlist(Node *head)
{
    Node *test ;

    for(test=head; test->next !=NULL; test=test->next)
        ;

    while(test!=NULL)
    {
        printf("%s >>", test->data);
        test = test->prev;
    }
}

void print_from_tail(Node* tail)
{
     Node *test=tail ;

      while(test!=NULL)
    {
        printf("%s >>", test->data);
        test = test->prev;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int r= add_head(&head, &tail, "hello");
    if(r==0)
    {
        printf("fail!\n");
    }

    add_tail(&head, &tail, "world");
    add_tail_fast(&head, &tail, "nice");

    add_next(&head, &tail, "hello", "good");
    add_before(&head, &tail, "good", "very good");

    add_index(&head, &tail, 2, "bad");
    add_index(&head, &tail, 10, "too bad");

    print_linkedlist(head);
    printf("\n");

    print_reverse_linkedlist(head);
    printf("\n");

    print_from_tail(tail);
    printf("\n");

    delete_target(&head, &tail, "world");
    print_linkedlist(head);
    printf("\n");

    /*delete_index(&head, &tail, 1);
    print_linkedlist(head);
    printf("\n");

    Node* found = get_node_index_tail(&head, &tail, 1);
    printf("find node: &s\n", found->data);*/

    reverse_list(&head, &tail);
    print_linkedlist(head);
    printf("\n");

    //delete_all(head);
    //print_linkedlist(head);

    return 0;
}
