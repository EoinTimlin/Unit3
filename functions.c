// Functions to work with Polynomials


#include "assignment_3.h"

// Function add a new polynomial
void createPoly(Poly **A,double con,int pow)
{
  Poly *x, *y;
  y = *A;
  if(y == NULL) // Check if there free memory at location
    {
      x = (Poly*)malloc(sizeof(Poly)); // Create memory for a poly term
      x->constant = con; // Set the constant
      x->power = pow; // Set the power
      *A = x; 
      x->next = (Poly*)malloc(sizeof(Poly)); 
      x = x->next;
      x->next= NULL;
    }
  else // If there is not free memory
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
while(A->next != NULL) // While next part in polynomial isn't NULL, loop through polynomial
    { 
    printf("%.1lfx^%d", A->constant, A->power); // Print a part of the expression in the form (constant)x^(power)
    A = A->next; 
    if(A->next != NULL) 
        printf(" + "); // Print a + between the parts
    } 
}

// Function to delete polynomial
void deletePoly(Poly **A)
{
  Poly* current = *A; 
  Poly* next; 
  
   while (current != NULL) // While there is used memory in this location
   { 
       next = current->next; 
       free(current); // Clear memory location
       current = next; 
   }
   
   *A = NULL; 
}
// Function to add polynomials A and B together
void addPoly(Poly *A, Poly *B, Poly *C)
{
  while(A->next && B->next) 
  {
    if(A->power > B->power) // If this term in A is higher degree than in B
    {
      C->power = A->power; // Set this term on C to the term in A
      C->constant = A->constant;
      A = A->next;
    }

    else if(A->power < B->power) // Else if this term in B is higher degree than the term in A
    {
      C->power = B->power; // Set this term in C to the term in B
      C->constant = B->constant;
      B = B->next;
    }
    else // Otherwise, if they are the same degree
    {
      C->power = A->power;
      C->constant = A->constant + B->constant; // Add the term's constants together
      A = A->next;
      B = B->next;
    }
     C->next = (Poly*)malloc(sizeof(C));
     C = C->next;
     C->next = NULL;
  }
  while(A->next || B->next) // While there is a term in A or B
  {
    if(A->next) // If there is a term in A
    {
      C->power = A->power;
      C->constant = A->constant; // Set the next term in C to A
      A = A->next;
    }
    if(B->next) // If there is a term in B
    {
      C->power = B->power;
      C->constant = B->constant; // Set the next term in C to B
      B = B->next;
    }
    C->next = (Poly*)malloc(sizeof(C)); 
    C = C->next;
    C->next = NULL;
  }
}
// Function to subtract polynomials A and B from each other
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
  for (int i = A->power;i>-1;i--){
    A->constant = (A->constant)*c;
    A = A->next;
  }
}

//divides a polynomial by a double
void dividePoly(Poly *A, double c){
  for (int i = A->power;i>-1;i--){
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
