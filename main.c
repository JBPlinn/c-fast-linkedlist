#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

/**
 * Test programm for the linkedlist lib.
 * 
 */
int main(void)
{
  bool ret;
  List * list = ListMake();

  // add test:
  ListAdd(list, 1);
  ListAdd(list,20);
  ListAdd(list,2);
  ListAdd(list,5);
  ListAdd(list,8);
  ListAdd(list,9);
  ret = ListAdd(list,13);
  printf("ListAdd(13)=%d\n", ret);
  printf("display=\n");
  ListDisplay(list);

  // add already present value:
  ret = ListAdd(list, 2);
  printf("re-ListAdd(2)=%d\n", ret);
  printf("readd 2 - display=\n");
  ListDisplay(list);

  // delete test:
  ret = ListDelete(list, 2);
  printf("delete(2) = %d - display=\n", ret);

  // delete already deleted value:
  ret = ListDelete(list, 2);
  printf("re-delete(2) = %d - display=\n", ret);

  ListDisplay(list);
  ListDelete(list, 1);
  printf("delete 1 display=\n");
  ListDisplay(list);

  // reverse test:
  ListReverse(list);
  printf("Reversed: ");
  ListDisplay(list);

  //dump content test:
  char str[256];
  char sep[]=",";

  ListGetPrintableContent(list, str, sep, 10);

  printf("get content full= [%s]\n", str);

  ListGetPrintableContent(list, str, sep, 3);

  printf("get content restricted= [%s]\n", str);

  // delete to empty test :
  ret = ListDelete(list, 13);
  printf("delete 13 =%d\n", ret);
  ret = ListDelete(list, 9);
   printf("delete  9 =%d\n", ret);  
  ret = ListDelete(list, 8);
   printf("delete  8 =%d\n", ret);
  ret = ListDelete(list, 5);
   printf("delete  5 =%d\n", ret);
  ret = ListDelete(list, 20);
  printf("delete 20 =%d\n", ret);

  ListDisplay(list);

  // destroy test:
  ListDestroy(list);

 printf("-------------------------------\n");

  List * list2;
  list2 = ListMake();

  ret = ListAdd(list2,6000);

  bzero(str, 256);
  ListGetPrintableContent(list2, str, sep, 10);

  printf("add 6000 = %d - get content full= [%s]\n", ret, str);
  
  ListDisplay(list2);
  ret = ListAdd(list2,6000);

  bzero(str, 256);
  ListGetPrintableContent(list2, str, sep, 10);
  printf("readd 6000 = %d - get content full= [%s]\n", ret, str);
  ListDisplay(list2);
  
  ret = ListAdd(list2,6000);
  bzero(str, 256);
  ListGetPrintableContent(list2, str, sep, 10);

  printf("readd 6000 = %d - get content full= [%s]\n", ret, str);
  ListDisplay(list2);

  ListDestroy(list2);

  printf("-------------------------------\n");

  List * list3;
   list3 = ListMake();

   ListAdd(list3, 1);
   ListAdd(list3,20);
   ListAdd(list3,2);
   ListAdd(list3,5);

   ListDisplay(list3);

   Iter * pIterator;
   pIterator = ListIterStart(list3);

   uint16_t val;

   val = ListGetValue(pIterator);
   printf("iter 1 = %d\n", val);
   ret = ListIterNext(pIterator);
   printf("next = %d\n", ret);

   val = ListGetValue(pIterator);
   printf("iter 2 = %d\n", val);
   ret = ListIterNext(pIterator);
   printf("next = %d\n", ret);

   val = ListGetValue(pIterator);
   printf("iter 3 = %d\n", val);
   ret = ListIterNext(pIterator);
   printf("next = %d\n", ret);

   val = ListGetValue(pIterator);
   printf("iter 4 = %d\n", val);
   ret = ListIterNext(pIterator);
   printf("next = %d\n", ret);

   val = ListGetValue(pIterator);
    printf("iter 5 = %d\n", val);
    ret = ListIterNext(pIterator);
    printf("next = %d\n", ret);

    ListIterStop(pIterator);
   ListDestroy(list3);

  return 0;
}
