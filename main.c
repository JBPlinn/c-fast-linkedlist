#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**
 * Test programm for the linkedlist lib.
 * 
 */
int main(void)
{
  bool ret;
  List * list = ListMake();

  // add test:
  ListAdd(1, list);
  ListAdd(20, list);
  ListAdd(2, list);
  ListAdd(5, list);
  ListAdd(8, list);
  ListAdd(9, list);
  ret = ListAdd(13, list);
  printf("ListAdd(13)=%d\n", ret);
  printf("display=\n");
  ListDisplay(list);

  // add already present value:
  ret = ListAdd(2, list);
  printf("re-ListAdd(2)=%d\n", ret);
  printf("readd 2 - display=\n");
  ListDisplay(list);

  // delete test:
  ret = ListDelete(2, list);
  printf("delete(2) = %d - display=\n", ret);

  // delete already deleted value:
  ret = ListDelete(2, list);
  printf("re-delete(2) = %d - display=\n", ret);

  ListDisplay(list);
  ListDelete(1, list);
  printf("delete 1 display=\n");
  ListDisplay(list);

  // reverse test:
  ListReverse(list);
  printf("Reversed: ");
  ListDisplay(list);

  // delete to empty test :
  ret = ListDelete(13, list);
  printf("delete 13 =%d\n", ret);
  ret = ListDelete(9, list);
   printf("delete  9 =%d\n", ret);  
  ret = ListDelete(8, list);
   printf("delete  8 =%d\n", ret);
  ret = ListDelete(5, list);
   printf("delete  5 =%d\n", ret);
  ret = ListDelete(20, list);
  printf("delete 20 =%d\n", ret);

  ListDisplay(list);

  // destroy test:
  ListDestroy(list);
  return 0;
}
