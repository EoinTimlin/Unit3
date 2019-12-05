// Functions to work with Polynomials
//Rory Brennan
//Eoin Timlin
//Tom Meehan
//Joey Corbett
//Sean Dolan

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
      x->next = (Poly*)malloc(sizeof(Poly)); // Create memory for the next poly term
      x = x->next; // Set x to next term
      x->next= NULL; // Set the next term to NULL
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
	  printf("%.1lf",A->constant); // If there is no exponent, print [constant]x
	  A = A->next; // Go to next term
	}
      else
	{
	  printf("%.1lfx^%d", A->constant, A->power);  // Print [constant]x^[power]
          A = A->next; // Go to next term
	}
    if(A->next != NULL && A->constant >= 0) // If the next term exists and it's constant is not zero
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
  
   while (current != NULL) // While the current term in the poly exists
   { 
       next = current->next; // Store the current term's next reference
       free(current); // Delete term
       current = next; // Set the current term to the next term
   }
   
   *A = NULL; 
}
// Function to add polynomials
void addPoly(Poly *A, Poly *B, Poly *C)
{
  while(A->next && B->next) // While there is a next reference in A and in B
  {
    if(A->power > B->power) // If this term in A is higher degree than in B
    {
      C->power = A->power; // Set C power to A power
      C->constant = A->constant; // Set C constant to A constant
      A = A->next; // Go to next term in poly A
    }

    else if(A->power < B->power) // Else if this term in B is higher degree than the term in A
    {
      C->power = B->power; // Set C power to B power
      C->constant = B->constant; // Set C constant to B constant
      B = B->next; // Go to next term in poly B
    }
    else // Otherwise, if they are the same degree
    {
      C->power = A->power; // Set C power to A power
      C->constant = A->constant + B->constant; // Add A and B constants together
      A = A->next; // Go to next term in poly A
      B = B->next; // Go to next term in poly B
    }
     C->next = (Poly*)malloc(sizeof(C));
     C = C->next;
     C->next = NULL;
  }
  while(A->next || B->next) // While there is a term in A or B
  {
    if(A->next) // If there is a term in A
    {
      C->power = A->power; // Set C power to A power
      C->constant = A->constant; // Set C constant to A constant
      A = A->next; // Go to next term in poly A
    }
    if(B->next) // If there is a term in B
    {
      C->power = B->power; // Set C power to B power
      C->constant = B->constant; // Set C constant to B constant
      B = B->next; // Go to next term in poly B
    }
    C->next = (Poly*)malloc(sizeof(C));
    C = C->next;
    C->next = NULL; // Create an empty next term in poly 
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
  while(A->next != NULL){ // While the next term in the polynomial exists
   A->constant = (A->constant)*c; // multiply term's constant by c
    A = A->next; // Go to next term
  }
}

//divides a double by the polynomial
void dividePoly(Poly *A, double c){
  while(A->next != NULL){ // While the next term in the polynomial exists
    A->constant = (A->constant)/c; // Divide term's constant by c
    A = A->next; // Go to next term
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
  A->constant = (A->constant)/c; // Divides the zero power
}

// Function to return highest order of polynomial
int retHigh(Poly **A)
{
  Poly* current = *A; // First term
  int max = -32000;
  
  while(current->next != NULL) // While the next term in the polynomial exists
    {
      if(current->power > max) // If the power on the current term is greater than the max power
	{
	  if(current->constant != 0) // Checks if coefficient is not zero
	    {
	      max =  current->power; // Set the max power to the current term
	      current = current->next; // Set the next term
	    }
	  else
	    {
	      current = current->next; // Set the next term
	    }
	}
      else
	{
	  current = current->next; // Set the next term
	}
    }
  
  return max; // Return the maximum power in the polynomial
}
