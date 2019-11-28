// Functions to work with Polynomials


#include "assignment_3.h"

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

// Function to delete polynomial
void deletePoly(Poly **A)
{
  Poly* current = *A; 
  Poly* next; 
  
   while (current != NULL)  
   { 
       next = current->next; 
       free(current); 
       current = next; 
   }
   
   *A = NULL; 
}

void addPoly(Poly *A, Poly *B, Poly *C)
{
  while(A->next && B->next)
  {
    if(A->power > B->power)
    {
      C->power = A->power;
      C->constant = A->constant;
      A = A->next;
    }

    else if(A->power < B->power)
    {
      C->power = B->power;
      C->constant = B->constant;
      B = B->next;
    }
    else
    {
      C->power = A->power;
      C->constant = A->constant + B->constant;
      A = A->next;
      B = B->next;
    }
     C->next = (Poly*)malloc(sizeof(C));
     C = C->next;
     C->next = NULL;
  }
  while(A->next || B->next)
  {
    if(A->next)
    {
      C->power = A->power;
      C->constant = A->constant;
      A = A->next;
    }
    if(B->next)
    {
      C->power = B->power;
      C->constant = B->constant;
      B = B->next;
    }
    C->next = (Poly*)malloc(sizeof(C));
    C = C->next;
    C->next = NULL;
  }
}

subtractPoly(Poly *A, Poly *B, Poly *C)
{
while(A->next && B->next)
  {
    if(A->power > B->power)
    {
      C->power = A->power;
      C->constant = A->constant;
      A = A->next;
    }

    else if(A->power < B->power)
    {
      C->power = B->power;
      C->constant = B->constant;
      B = B->next;
    }
    else
    {
      C->power = A->power;
      C->constant = A->constant - B->constant;
      A = A->next;
      B = B->next;
    }
     C->next = (Poly*)malloc(sizeof(C));
     C = C->next;
     C->next = NULL;
  }
  while(A->next || B->next)
  {
    if(A->next)
    {
      C->power = A->power;
      C->constant = A->constant;
      A = A->next;
    }
    if(B->next)
    {
      C->power = B->power;
      C->constant = B->constant;
      B = B->next;
    }
    C->next = (Poly*)malloc(sizeof(C));
    C = C->next;
    C->next = NULL;
  }
}
