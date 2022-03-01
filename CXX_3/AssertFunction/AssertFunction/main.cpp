//
//  main.cpp
//  AssertFunction
//
//  Created by Wataru Oshima on 2020/03/09.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

/* assert example */
#include <stdio.h>      /* printf */
#include <assert.h>     /* assert */

void print_number(int* myInt) {
  assert (myInt!=NULL);
  printf ("%d\n",*myInt);
}

int main ()
{
  int a=10;
  int * b = NULL;
  int * c = NULL;

  b=&a;

  print_number (b);
  print_number (c);

  return 0;
}
