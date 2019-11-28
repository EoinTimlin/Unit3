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
  printf("\n");

  printPoly(poly2);
  printf("\n");

  // Add Polynomials
  addPoly(poly1, poly2, poly3);

  printPoly(poly3);
  printf("\n");

  // Subtract Polynomials  
  subtractPoly(poly1, poly2, poly4);

  printPoly(poly4);
  printf("\n");

  deletePoly(&poly3);
  if(poly3 == NULL)
    {
      printf("Fully Deleted\n");
    }

  return 0;
}

