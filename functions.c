// Functions to work with Polynomials

#include "assignment_3.h"

// Function add a new polynomial
void createPoly(Poly **A,double con,int pow)
{
  Poly *x, *y;
  y = *A;
  if(y == NULL) // Check if there free memory at location
    {
      x = (Poly*)malloc(sizeof(Poly)); //Create memory for a poly term
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
  
  while(A->next != NULL) // While next term in poly isn't NULL, loop through poly
    {
      if(A->power == 0)
	{
	  printf("%.1lf",A->constant); //Print a part of the expression in the form (constant)x^(power)
	  A = A->next;
	}
      else
	{
	  printf("%.1lfx^%d", A->constant, A->power); 
          A = A->next;
	}
    if(A->next != NULL && A->constant >= 0) 
        printf(" + "); // Print a + between the parts (Positive)
    else
      printf(" "); // Print space for negative numbers
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
// Function to add polynomials
void addPoly(Poly *A, Poly *B, Poly *C)
{
  while(A->next && B->next) // While there term in A and in B
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
      C->power = A->power; // Set the next term in C to A
      C->constant = A->constant;
      A = A->next;
    }
    if(B->next) // If there is a term in B
    {
      C->power = B->power; // Set the next term in C to B
      C->constant = B->constant;
      B = B->next;
    }
    C->next = (Poly*)malloc(sizeof(C));
    C = C->next;
    C->next = NULL;
  }
}
// Function to subtract polynomials
void subtractPoly(Poly *A, Poly *B, Poly *C) 
{
while(A->next && B->next) // While there term in A and in B
  {
    if(A->power > B->power) // If this term in A is higher degree than in B
    {
      C->power = A->power;
      C->constant = A->constant; // Set this term in C to A
      A = A->next;
    }

    else if(A->power < B->power) // Else if this term in B is higher degree than the term in A
    {
      C->power = B->power;
      C->constant = -B->constant; // Set this term in C to B
      B = B->next;
    }
    else // Otherwise, if they are the same degree
    {
      C->power = A->power; 
      C->constant = A->constant - B->constant; // Constant is the difference between constant A and constant B 
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
      C->constant = A->constant; // Set this term to A
      A = A->next;
    }
    if(B->next) // If there is a term in B
    {
      C->power = B->power;
      C->constant = B->constant; // Set term to B
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
   A->constant = (A->constant)*c;
    A = A->next;
  }
}

//divides a double by the polynomial
void dividePoly(Poly *A, double c){
  while(A->next != NULL){
    A->constant = (A->constant)/c; // Divide by constant c
    A = A->next;
  }
}


// Function to normalise a polynomial
void normalPoly(Poly *A){
  double c;
  c = A->constant;
  while(A->power != 0){ // While terms power isn't 0
    A->constant = (A->constant)/c; // Divide by highest term's constant
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
