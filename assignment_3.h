#ifndef ASSIGNMENT_3_H_INCLUDED
#define ASSIGNMENT_3_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct Polynomials
{
  int power;
  double constant;
  struct Polynomials *next;
} Poly;

// Creates a function to add 2 polynomials.
void addPoly(Poly *A, Poly *B, Poly *C);
// Creates a function that subtracts 2 polynomials.
void subtractPoly(Poly *A, Poly *B, Poly *C);
// Creates a function that multiplies a polynomial.
void multiplyPoly(Poly *A, double c);
// Creates a function that divides a polynomial.
void dividePoly(Poly *A, double c);
// Function that normalises a polynomial
void normalPoly(Poly *A);
// Creates a function that deletes a polynomial.
void deletePoly(Poly **A);
// Creates a function that creates a polynomial.
void createPoly(Poly **A,double con,int pow);
// Creates a function that returns the highest order of polynomial.
int retHigh(Poly **A);
// Creates a function that prints a polynomial.
void printPoly(Poly *A);

#endif // ASSIGNMENT_3_H_INCLUDED
