#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue
{
    int head ;
    int tail ;
    char* list[100];
};

void init_queue(struct Queue* q)
{
    q->head = -1;
    q->tail = -1;

    for(int i=0; i<100; i++)
    {
        q->list[i] = NULL;
    }
}

void enqueue(struct Queue* q, char* data)
{
    if (q->head == -1)
    {
        q->head = 0;
    }

    q->list[++(q->tail)]=(char*)malloc(strlen(data)+1);
    strcpy(q->list[q->tail], data);
}

void dequeue(struct Queue* q, char* temp)
{
    if (q->head == -1)
    {
        temp[0] = '\0';
        return;
    }

    strcpy(temp, q->list[q->head]);
    free (q->list[q->head]);
    q->list[q->head]=NULL;

    if(q->list[q->head+1]!=NULL)
    {
            q->head ++;
    }
    else
    {
            q->head = -1;
            q->tail = -1;
    }
}

void clear_queue(struct Queue* q)
{
        int i;

        for(i=q->head; i<=q->tail; i++)
        {
            free(q->list[i]);
            q->list[i]=NULL;
        }

        q->head = -1;
        q->tail =-1;
}

void print_queue(struct Queue* q)
{
        if(q->head==-1)
        {
            return;
        }

        int i;

        for(i=q->head; i<=q->tail; i++)
        {
            printf("%s >> ", q->list[i]);
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
    printf("%s\n", temp);

    print_queue(&q);
    clear_queue(&q);
    print_queue(&q);

    return 0;
}
