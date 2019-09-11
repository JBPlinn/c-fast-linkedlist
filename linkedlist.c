#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

struct node 
{
  uint16_t data;
  struct node * next;
};

struct list 
{
  Node *       head;
  unsigned int list_size;
};


/**
 * Single node creation with (slow) memory allocation.
 *
 * @param data the data to store in the list
 * @return     pointer to the node or NULL upon error
 */
Node * createnode(uint16_t data)
{
  Node * newNode = (Node *) malloc(sizeof(Node));
  
  if(newNode == NULL)
  {
    return NULL;
  }
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

/**
 * Create the list.
 *
 * @return  pointer to the list or NULL upon error
 */
List * ListMake()
{
  List * list = (List *) malloc(sizeof(List));

  if(list == NULL)
  {
    return NULL;
  }
  
  list->head = NULL;
  
  list->list_size = 0;
  
  return list;
}


/**
 * Add unique data to the list.
 * 
 * @param   data data to insert
 * @param   list pointer to the list
 * @return  true if insertion succeeded, false if the value already in the list
 */
bool ListAdd(List * list, uint16_t data)
{
  bool ok = false;
  Node * current = NULL;
  Node * next = NULL;
  
  if(list->head == NULL)
  {
    list->head = createnode(data);
    list->list_size++;
    ok = true;
  }
  else 
  {
    current = list->head; // at beginning
    next = current;       //same slot for 1st round
    
    do
    {
      current = next;  // advance one step after 1st round

      if(current->data == data)
      {
        ok = false;
        return ok;
      }

      next = current->next; // beginning with 2nd loop advance one step

    } 
    while(next != NULL);
    
    current->next = createnode(data);
    list->list_size++;
    ok = true;
  }

  return ok;
}

/**
 * Delete a dat a from the list
 *
 * @param   data the data to delete
 * @param   list pointer to the list
 * @return  true if the data has been deleted, false if data is not present in the list
 */
bool ListDelete(List * list, uint16_t data)
{
  bool ok = false;
  Node * current = list->head;            
  Node * previous = current;           
  while(current != NULL)
  {           
    if(current->data == data)
    {      
      previous->next = current->next;
      
      if(current == list->head)
      {  
        list->head = current->next;
      }
      
      free(current);
      list->list_size--;
      if(list->list_size < 0)
         list->list_size = 0;
      ok = true;
      
      return ok;
    }                               
    previous = current;             
    current = current->next;        
  }

  return ok;                               
}                                   

/**
 * Reverse the order of the list.
 * 1st item will be the last.
 *
 * @param list pointer to the list.
 */
void ListReverse(List * list)
{
  Node * reversed = NULL;
  Node * current = list->head;
  Node * temp = NULL;
  
  while(current != NULL)
  {
    temp = current;
    current = current->next;
    temp->next = reversed;
    reversed = temp;
  }
  
  list->head = reversed;
}

/**
 * Remove all elements from the list an free list memory.
 *
 * @param list pointer to the list.
 */
void ListDestroy(List * list)
{
  Node * current = list->head;
  Node * next = current;

  if(list != NULL)
  {
    while(current != NULL)
    {
      next = current->next;
      free(current);
      current = next;
    }
    
    free(list);
  }
}

/**
 * get the actual size of the list
 *
 * @param list pointer to the list.
 * @return     size of the list
 */
unsigned int ListSize(List * list)
{
  return list->list_size;
}


/**
 * Display the size of the list and all elements in order
 * to the console.
 *
 * @param list pointer to the list
 */
void ListDisplay(List * list)
{
  Node * current = list->head;

  printf("Size = %d\n", list->list_size);

  if(list->head == NULL)
  {
    return;
  }

  for(; current != NULL; current = current->next)
  {
    printf("%d-", current->data);
  }
  printf("\n");
}

/**
 * Dump the content of the list into a string.
 *
 * @param list  pointer to the list
 * @param dest  the destination string (size is not checked)
 * @param sep   separator string between values
 * @param limit max number of elements printed, ... trailing after max exceeded
 */
void ListGetPrintableContent( List *         list,
                              char *         dest,
                              char *         sep,
                              unsigned int   limit)
{
   Node * current = list->head;
   int stridx = 0; 
   unsigned int cnt;

   if(list->head == NULL)
   {
     stridx = sprintf(dest, "\0");
     return;
   }

   for(cnt = 0; (cnt <= limit) && (current != NULL); current = current->next)
   {
     if((current->next != NULL) && (cnt < limit))
     {
        stridx = stridx + sprintf(dest + stridx, "%d%s", current->data, sep);
      }
     else
     {
        if(cnt == limit)
        {
           stridx = stridx + sprintf(dest + stridx, "...");
        }
        else
        {
           stridx = stridx + sprintf(dest + stridx, "%d", current->data);
        }
      }
     cnt++;
   }
}
