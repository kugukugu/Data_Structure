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
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coef = coef;
    newTerm->exp = exp;
    newTerm->next = NULL;
    newTerm->prev = NULL;

    // 다항식이 비어있을 경우
    if (poly == NULL)
    {
            poly = newTerm;
    }
    else
    {
            Term* tmp = poly;
            Term* tmp2 = NULL;

            while(tmp !=NULL)
            {
                if(newTerm->exp >= tmp->exp)
                    break;
                if(tmp->next == NULL)
                {
                    tmp2 = tmp;
                }
                tmp=tmp->next;
            }

            if(tmp == NULL)
            {
                newTerm->prev = tmp2;
                tmp2->next = newTerm;
            }
            else
            {
                if(tmp->exp == newTerm->exp)
                {
                    tmp->coef += newTerm->coef;
                    free (newTerm) ;

                    if(tmp->coef == 0)  //계수가 0이다. 삭제 대상 항
                    {
                        if(tmp->prev == NULL)
                        {
                            poly =tmp->next;
                            if(poly != NULL)
                            {
                                poly->prev = NULL;
                            }
                        }
                        else
                        {
                            tmp->prev->next = tmp->next;
                            if(tmp->prev -> next != NULL)
                            {
                                tmp->next->prev= tmp->prev;
                            }
                        }
                        free(tmp);
                    }
                }
                else
                {
                    newTerm->next = tmp;
                    newTerm->prev = tmp->prev;
                    tmp->prev = newTerm;

                    if(newTerm->prev !=NULL)
                    {
                        newTerm->prev->next = newTerm;
                    }
                    else
                    {
                        poly = newTerm;
                    }
                }
            }
    }

    return poly;
}

void printPoly(Term* poly)
{
    Term* tmp;

    printf("P1: ");

    for (tmp = poly; tmp != NULL; tmp = tmp->next)
    {
        printf("%dx^%d", tmp->coef, tmp->exp);
        if (tmp->next != NULL)
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
    poly1 = insertTerm(poly1, 2, 0);
    poly1 = insertTerm(poly1, 3, 10);
    poly1 = insertTerm(poly1, -3, 10);

    printPoly(poly1);

    return 0;
}
