#include "assignment_3.h"

int main()
{
  //Creating Polynomials 
  Poly *poly1 = NULL;
  createPoly(&poly1,5,2);
  createPoly(&poly1,4,1);
  createPoly(&poly1,2,0);

  Poly *poly2 = NULL;
  createPoly(&poly2,6,3);
  createPoly(&poly2,3,2);
  createPoly(&poly2,8,0);
  
  //Poly for addition
  Poly *poly3 = NULL;
  poly3 = (Poly*)malloc(sizeof(poly3));

  //Poly for Subtraction
  Poly *poly4 = NULL;
  poly4 = (Poly*)malloc(sizeof(poly4));

  printf("Expected: 5x^2 + 4x^1 + 2x^0\n");
  printf("Actual: ");
  printPoly(poly1);
  printf("\n");

  printf("Expected: 6x^3 + 3x^2 + 8x^0\n");
  printf("Actual: ");
  printPoly(poly2);
  printf("\n");

  // Add Polynomials
  addPoly(poly1, poly2, poly3);

  printf("Expected: 6x^3 + 8x^2 + 4x^1 + 10x^0\n");
  printf("Actual: ");
  printPoly(poly3);
  printf("\n\n");

  // Subtract Polynomials  
  subtractPoly(poly1, poly2, poly4);

  printf("Expected: 6x^3 + 2x^2 + 4x^1 + -6x^0");
  printf("Actual: ");
  printPoly(poly4);
  printf("\n\n");

  // Testing delete function
  printf("Deleting Polynomial 3 ....\n");
  deletePoly(&poly3);
  if(poly3 == NULL)
    {
      printf("Polynomial fully deleted\n\n");
    }
  else
    {
      printf("Failed\n");
    }
  
  // Testing order function
  int highorder;
  highorder = retHigh(&poly2);
  printf("Order of Polynomial 2: \n");
  printf("Expected: 3 Actual: %d \n\n",highorder);

  //Testing multiply function
  Poly *poly6 = NULL;
  createPoly(&poly6,1,6);
  createPoly(&poly6,5,5);
  createPoly(&poly6,3.5,3);
  createPoly(&poly6,4,1);
  createPoly(&poly6,2,0);

  multiplyPoly(poly6,2);
  printf("Expected: 2x^6 + 10x^5 + 7x^3 + 8x^1 + 4\n");
  printf("Actual: ");
  printPoly(poly6);
  printf("\n\n");
  
  //Testing Divide function
  Poly *poly7 = NULL;
  createPoly(&poly7,1,6);
  createPoly(&poly7,5,5);
  createPoly(&poly7,3.2,3);
  createPoly(&poly7,4,1);
  createPoly(&poly7,2,0);

  dividePoly(poly7,2);
  printf("Dividing 1x^6 + 5x^5 + 3.2x^3 + 4x^1 + 2 by 2\n");
  printf("Expected: 0.5x^6 + 2.5x^5 + 1.6x^3 + 2x^1 + 1\n");
  printf("Actual:");
  printPoly(poly7);
  printf("\n\n");
  return 0;
}

