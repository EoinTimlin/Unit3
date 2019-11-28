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
// Function to add polynomials
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
// Function to subtract polynomials
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

//multiplies a double by the polynomial
void multiplyPoly(Poly *A, double c){
  while(A->next != NULL){
   A->constant = (A->constant)/c;
    A = A->next;
  }
}

//divides a double by the polynomial
void dividePoly(Poly *A, double c){
  while(A->next != NULL){
    A->constant = (A->constant)/c;
    A = A->next;
  }
}


// Function to normalise a polynomial
void normalPoly(Poly *A){
  
  double c;
  c = A->constant;
  
  for (int i = A->power;i>-1;i--){
    A->constant = (A->constant)/c;
    A = A->next;
  }
  
}

// Function to return highest order of polynomial
int retHigh(Poly **A)
{
  Poly* current = *A;
  int max = -32000;
  
  while(current->next != NULL)
    {
      if(current->power > max)
	{
	  if(current->constant != 0) // Checks if coefficient is not zero
	    {
	      max =  current->power;
	      current = current->next;
	    }
	  else
	    {
	      current = current->next;
	    }
	}
      else
	{
	  current = current->next;
	}
    }
  
  return max;
}
