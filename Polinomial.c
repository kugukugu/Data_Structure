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
        return newTerm;

    Term* current = poly;

    // 맨 앞에 삽입 (가장 높은 차수)
    if (exp > current->exp) {
        newTerm->next = current;
        current->prev = newTerm;
        return newTerm;
    }

    // 중간이나 뒤에 삽입
    while (current != NULL) {
        if (exp == current->exp) {
            // 차수가 같은 항이 있으면 계수만 더함
            current->coef += coef;
            free(newTerm);
            return poly;
        }
        else if (exp > current->exp) {
            // 중간에 삽입
            newTerm->next = current;
            newTerm->prev = current->prev;
            if (current->prev)
                current->prev->next = newTerm;
            current->prev = newTerm;

            // head가 바뀌었는지 확인
            if (current == poly)
                return newTerm;
            return poly;
        }
        else if (current->next == NULL) {
            // 맨 뒤에 삽입
            current->next = newTerm;
            newTerm->prev = current;
            return poly;
        }
        current = current->next;
    }

    return poly;
}

void printPoly(Term* poly)
{
    Term* tmp;

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

    printf("P1: ");
    printPoly(poly1);

    return 0;
}
