#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char* data;
    struct Node* next;
};

struct Queue
{
    struct Node* head;
    struct Node* tail;
};

// 전달받은 data로 새로운 노드를 생성
struct Node* create_node(char* data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = (char*)malloc(strlen(data) + 1);
    strcpy(temp->data, data);
    temp->next = NULL;
    return temp;
}

// 전달받은 node에 대해 메모리 해제
void delete_node(struct Node* node)
{
    free(node->data);
    free(node);
}

void init_queue(struct Queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(struct Queue* q, char* data)
{
    struct Node* temp = create_node(data);

    if (q->head == NULL)
    {
        q->head = temp;
    }

    if (q->tail != NULL)
    {
        q->tail->next = temp;
    }

    q->tail = temp;
}

char* dequeue(struct Queue* q, char* temp)
{
    struct Node* tmp = q->head;

    if (q->head == NULL)
    {
        temp[0] = '\0';
        return;
    }

    strcpy(temp, q->head->data);
    q->head = q->head->next;
    delete_node(tmp);

    return temp;
}

void clear_queue(struct Queue* q)
{
    struct Node* temp = q->head;

    while (q->head != NULL)
    {
        q->head = q->head->next;
        delete_node(temp);
        temp = q->head;
    }
}

void print_queue(struct Queue* q)
{
    struct Node* tmp ;

    for (tmp = q->head; tmp != NULL; tmp = q->head->next) {
        printf("%s >> ", tmp->data);
    }
    printf("\n");

}

int main()
{
    struct Queue q;
    char temp[100];

    init_queue(&q);

    enqueue(&q, "hello");
    enqueue(&q, "world");
    enqueue(&q, "nice");

    dequeue(&q, temp);
    printf("%s, ", temp);

    return 0;
}
