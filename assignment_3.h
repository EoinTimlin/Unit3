#ifndef ASSIGNMENT_3_H_INCLUDED
#define ASSIGNMENT_3_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>


// Creates a function to add 2 poloynomials.
void addPoly(Poly *A, Poly *B);
// Creates a function that multiplies 2 poloynomials.
void multiplyPoly(Poly *A, Poly *B);
// Creates a function that subtracts 2 polynomials.
void subtractPoly(Poly *A, Poly *B);
// Function that normalises a polynomial
void normalPoly(Poly *A);
// Creates a function that deletes a poloynomial.
void deletePoly(Poly **A);
// Creates a function that creates a polynomial.
void createPoly(Poly **A,double con,int pow);
// Creates a function that prints a polynomial.
void printPoly(Poly *A);

#endif // ASSIGNMENT_3_H_INCLUDED
