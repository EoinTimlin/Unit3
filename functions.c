// Functions to work with Polynomials

#include <stdlib.h>
#include <stdio.h>

typedef struct Polynomials
{
  double power;
  double constant;
  struct Node *next;
} Poly;
