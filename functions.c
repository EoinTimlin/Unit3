// Functions to work with Polynomials

#include <stdlib.h>
#include <stdio.h>

typedef struct Polynomials
{
  int power;
  double constant;
  struct Polynomials *next;
} Poly;

// Function add a new polynomial
void createPoly(Poly **A,double con,int pow)
{
  Poly *x, *y;
  y = *A;
  if(y == NULL)
    {
      x = (Poly*)malloc(sizeof(Poly));
      x->constant = con;
      x->power = pow;
      *A = x;
      x->next = (Poly*)malloc(sizeof(Poly));
      x = x->next;
      x->next= NULL;
    }
  else
    {
      x->constant = con;
      x->power = pow;
      x->next = (Poly*)malloc(sizeof(Poly));
      x = x->next;
      x->next= NULL;
    }
}

// Function to print polynomial
void printPoly(Poly *A) 
{ 
while(A->next != NULL) 
    { 
    printf("%.1lfx^%d", A->constant, A->power); 
    A = A->next; 
    if(A->next != NULL) 
        printf(" + "); 
    } 
}
