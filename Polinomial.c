#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Term {
    int coef;
    int exp;
    struct Term* next;
    struct Term* prev;
}Term;

Term* insertTerm(Term* poly, int coef, int exp)
{
    Term* new1 = (Term *)malloc(sizeof(Term));
    new1->coef = coef;
    new1->exp = exp;
    new1->next = NULL;
    new1->prev = NULL;

    Term *temp = poly;

    if(poly==NULL)
    {
        poly = new1;
    }
    else
    {
        //차수를 찾는다.
        // 동일한 차수면 항을 합친다.
        //차수보다 낮은 것을 찾으면 그 앞에 끼워 넣는다.
        //맨 앞에 넣으면  poly도 바뀐다.

        while(new1->exp > temp->exp)
        {
            temp=temp->next;
        }

        if(new1->exp == temp->exp)
        {
            temp->coef = new1->coef+temp->coef;
            free(new1);
        }
        else
        {
            new1->next=temp;
            new1->prev=temp->prev;
            if(new1->prev!=NULL)
            {
                new1->prev->next=new1;
            }
            else
            {
                poly=new1;
            }
            new1->next->prev=new1;
        }
    }

    return poly;
}

void printPoly(Term* poly)
{
    Term* tmp;

    for(tmp=poly; tmp!=NULL; tmp = tmp->next)
    {
        printf("%dx^%d",tmp->coef, tmp->exp);
        if(tmp->next!=NULL)
            printf(" + ");
    }
    printf("\n");
}

int main()
{
    Term* poly1 = NULL;

    poly1 = insertTerm(poly1, 3, 2);
    poly1 = insertTerm(poly1, 3, 1);
    poly1 = insertTerm(poly1, 1, 0);
    poly1 = insertTerm(poly1, 3, 10);

    printf("P1: ");
    printPoly(poly1);

    return 0;
}
