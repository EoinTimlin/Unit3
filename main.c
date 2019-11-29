// main function

#include "assignment_3.h"

int main()
{
  //Creating Polynomials
  printf("\n");
  printf("Testing creating polynomials....\n");
 
  Poly *poly1 = NULL;
  createPoly(&poly1,5,3);
  createPoly(&poly1,4,1);
  createPoly(&poly1,2,0);

  Poly *poly2 = NULL;
  createPoly(&poly2,6,3);
  createPoly(&poly2,3,2);
  createPoly(&poly2,8,0);

  printf("Poly 1:\n");
  printf("Expected: 5.0x^3 + 4.0x^1 + 2.0\n");
  printf("Actual: ");
  printPoly(poly1);
  printf("\n");

  printf("Poly 2:\n");
  printf("Expected: 6.0x^3 + 3.0x^2 + 8.0\n");
  printf("Actual: ");
  printPoly(poly2);
  printf("\n\n");

  printf("Testing adding polynomials (P1 + P2)....\n");
  printf("Poly 3:\n");
  // Add Polynomials
  // Poly for addition
  Poly *poly3 = NULL;
  poly3 = (Poly*)malloc(sizeof(poly3));
  addPoly(poly1, poly2, poly3);

  printf("Expected: 11.0x^3 + 3.0x^2 + 4.0x^1 + 10.0\n");
  printf("Actual: ");
  printPoly(poly3);
  printf("\n\n");

  printf("Testing subtracting polynomials (P1 - P2)....\n");
  printf("Poly 4:\n");
  // Subtract Polynomials
   //Poly for Subtraction
  Poly *poly4 = NULL;
  poly4 = (Poly*)malloc(sizeof(poly4));
  subtractPoly(poly1, poly2, poly4);

  printf("Expected: -1.0x^3 - 3.0x^2 + 4.0x^1 - 6.0\n");
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
      printf("Failed\n\n");
    }
  
  // Testing order function
  int highorder;
  highorder = retHigh(&poly2);
  printf("Order of Polynomial 2: \n");
  printf("Expected: 3 \nActual: %d \n\n",highorder);

  //Testing multiply function
  printf("Testing multiply function..\n");
  printf("Polynomial: ");
  Poly *poly6 = NULL;
  createPoly(&poly6,1,6);
  createPoly(&poly6,5,5);
  createPoly(&poly6,3.5,3);
  createPoly(&poly6,4,1);
  createPoly(&poly6,2,0);

  printPoly(poly6);
  printf("\n");
  multiplyPoly(poly6,2);

  printf("Multiplied by 2: ");
  printPoly(poly6);
  printf("\n\n");
  
  //Testing Divide function
  printf("Testing divide function..\n");
  printf("Polynomial: ");
  Poly *poly7 = NULL;
  createPoly(&poly7,1,6);
  createPoly(&poly7,5,5);
  createPoly(&poly7,3.5,3);
  createPoly(&poly7,4,1);
  createPoly(&poly7,2,0);

  printPoly(poly7);
  printf("\n");
  dividePoly(poly7,2);

  printf("Divided by 2: ");
  printPoly(poly7);
  printf("\n\n");
  return 0;
}
