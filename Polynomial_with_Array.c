#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POLY 100

int poly1[MAX_POLY];
int poly2[MAX_POLY];
int add_poly[MAX_POLY];
int mul_poly[MAX_POLY];

int insertTerm(int* poly, int coef, int exp)
{
    if(exp >= MAX_POLY || exp<0)
    {
            return -1;
    }

    poly[exp]+=coef;

    return 0;
}

void print_poly(int* poly)
{
    int i, flag = 0;

    for(i=MAX_POLY-1; i>=0; i--)
    {
        if(poly[i]!=0)
        {
            if(flag  != 0)
                printf(" + ");

            flag = 1;
            printf("%dx^%d", poly[i], i);
        }
    }
    printf("\n");
}

void addpoly(int* add_poly, int* poly1, int* poly2)
{
    int i;

   for(i=MAX_POLY-1; i>=0; i--)
    {
       add_poly[i]=poly1[i]+poly2[i];
    }
}

void mulpoly(int* mul_poly, int* poly1, int* poly2)
{
    int i, j;

    for(i=MAX_POLY-1; i>=0; i--)
    {
        if(poly1[i] !=0)
        {
            for(j=MAX_POLY-1; j>=0; j--)
            {
                if(poly2[j] != 0)
                    insertTerm(mul_poly, poly1[i]*poly2[j], i+j);
            }
        }
    }
}

int evalPoly(int* add_poly, int x)
{
    int i, sum=0;

    for(i=0; i<MAX_POLY; i++)
    {
        if(add_poly[i]!=0)
        {
            sum += add_poly[i] * (int)pow(x, i);
        }
    }

    return sum;
}

int main()
{
    insertTerm(poly1, 3, 2);
    insertTerm(poly1, 2, 5);
    insertTerm(poly1, 2, 4);

    printf("poly1: ");
    print_poly(poly1);

    insertTerm(poly2, 5, 2);
    insertTerm(poly2, 1, 3);
    insertTerm(poly2, 6, 1);

    printf("poly2: ");
    print_poly(poly2);

    addpoly(add_poly, poly1, poly2);

    printf("add_poly: ");
    print_poly(add_poly);

    mulpoly(mul_poly, poly1, poly2);

    printf("mul_poly: ");
    print_poly(mul_poly);

    int r = evalPoly(poly2, 3);
    printf("%d\n", r);

    return 0;
}
