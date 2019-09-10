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

/// create the list
List * ListMake();

/// add a unique element to the list
bool ListAdd(uint16_t data, List * list);

/// delete an element from the list
bool ListDelete(uint16_t data, List * list);

/// display the list values
void ListDisplay(List * list);

/// reverse the list order
void ListReverse(List * list);

/// destroy the list
void ListDestroy(List * list);

#endif
