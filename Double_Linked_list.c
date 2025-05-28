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
    Node* temp = (Node *)malloc(sizeof(Node));
    temp->data = (char*)malloc(strlen(data)+1);
    strcpy(temp->data, data);

    temp->prev=NULL;
    temp->next=NULL;

    return temp;
}

void delete_node(Node* node)
{
    free(node->data);
    free(node);
}

void add_head(Node**head, Node**tail, char* data)
{
    Node* temp = create_node(data);

    if((*head)==NULL)
    {
        (*head)=temp;
        (*tail)=temp;
        return;
    }

    temp->next = (*head);
    (*head)->prev = temp;
    (*head)=temp;
}

void add_tail(Node**head, Node**tail, char* data)
{
    Node* temp = create_node(data);
    Node* test = (*head) ;

     if((*head)==NULL)
    {
        (*head)=temp;
        (*tail)=temp;
        return;
    }

    while(test->next!=NULL)
    {
        test = test->next;
    }

    temp->prev = test;
    test->next = temp;
    (*tail)=temp;
}

void add_tail_fast(Node**head, Node**tail, char* data)
{
    Node* temp = create_node(data);

    if((*tail)==NULL)
    {
        (*head)=temp;
        (*tail)=temp;
        return;
    }

    temp->prev = (*tail);
    (*tail)->next = temp;
    (*tail)=temp;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    add_head(&head, &tail, "hello");
    add_tail(&head, &tail, "world");
    add_tail_fast(&head, &tail, "nice");


    return 0;
}
