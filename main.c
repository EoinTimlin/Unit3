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

  printPoly(poly1);
  printf("Expected: 5x^2 + 4x^1 + 2x^0\n");
  printf("Actual: ");
  printf("\n");

  printPoly(poly2);
  printf("Expected: 6x^3 + 3x^2 + 8x^0\n");
  printf("Actual: ");
  printf("\n");

  // Add Polynomials
  addPoly(poly1, poly2, poly3);

  printPoly(poly3);
  printf("Expected: 6x^3 + 8x^2 + 4x^1 + 10x^0\n");
  printf("Actual: ");
  printf("\n");

  // Subtract Polynomials  
  subtractPoly(poly1, poly2, poly4);

  printPoly(poly4);
  printf("Expected: 6x^3 + 2x^2 + 4x^1 + -6x^0");
  printf("Actual: ");
  printf("\n");

  // Testing delete function
  printf("Deleting Polynomial....\n");
  deletePoly(&poly3);
  if(poly == NULL)
    {
      printf("Polynomial fully deleted\n");
    }
  else
    {
      printf("Failed\n");
    }
  
  // Testing order function
  int highorder;
  highorder = retHigh(&poly2);
  printf("Order of Polynomial: \n");
  printf("Expected: 6 Actual: %d \n",highorder);

  return 0;
}

