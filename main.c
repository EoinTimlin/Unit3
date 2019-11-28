#include "assignment_3.h"

int main()
{
  Poly *poly = NULL;
  createPoly(&poly,5,2);
  createPoly(&poly,4,1);
  createPoly(&poly,2,0);

  printPoly(poly);
  printf("\n");

  deletePoly(&poly);
  if(poly == NULL)
    {
      printf("Fully Deleted\n");
    }
  
  return 0;
}
