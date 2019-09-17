/**
 * Single linked list with unique data
 * (like c++ std::set). 
 * 
 * Fast implementation with single malloc()
 * per node.
 * 
 */

#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

#include <stdint.h>
#include <stdbool.h>

typedef struct node Node;

typedef struct list List;

typedef struct iter Iter;

/// create the list
List * ListMake();

/// add a unique element to the list
bool ListAdd(List * list, uint16_t data);

/// delete an element from the list
bool ListDelete(List * list, uint16_t data);

/// reverse the list order
void ListReverse(List * list);

/// destroy the list
void ListDestroy(List * list);

/// get the size of the list
unsigned int ListSize(List * list);

/// display the list values
void ListDisplay(List * list);

/// dump list content into a string
void ListGetPrintableContent( List *         list,
                              char *         dest,
                              char *         sep,
                              unsigned int   limit);

/// start iteration through the list
Iter * ListIterStart(List * list);

/// advance one step
bool ListIterNext(Iter * iter);

/// get value at iterator
uint16_t ListGetValue(Iter * iter);

/// stop and destroy iterator
void ListIterStop(Iter * iter);

#endif
