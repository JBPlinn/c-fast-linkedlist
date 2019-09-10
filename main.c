#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void)
{
  bool ret;
  List * list = ListMake();
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

ret = ListAdd(2, list);
  printf("ListAdd(2)=%d\n", ret);
printf("readd 2 - display=\n");
 ListDisplay(list);

  ret = ListDelete(2, list);
printf("delete(2) = %d - display=\n", ret);

  ret = ListDelete(2, list);
printf("re-delete(2) = %d - display=\n", ret);

  ListDisplay(list);
  ListDelete(1, list);
printf("delete 1 display=\n");

  ListDisplay(list);

  ListReverse(list);
  printf("Reversed: ");
  ListDisplay(list);
  ListDestroy(list);
  return 0;
}
