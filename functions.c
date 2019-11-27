// Functions to work with Polynomials

#include <stdlib.h>
#include <stdio.h>

typedef struct Polynomials
{
  int power;
  double constant;
  struct Polynomials *next;
} Poly;
