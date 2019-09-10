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
  Node * head; 
};

unsigned int list_size;

Node * createnode(uint16_t data);

Node * createnode(uint16_t data)
{
  Node * newNode = malloc(sizeof(Node));
  
  if(!newNode) 
  {
    return NULL;
  }
  newNode->data = data;
  newNode->next = NULL;
  list_size++;

  return newNode;
}

List * ListMake()
{
  List * list = malloc(sizeof(List));

  if(!list) 
  {
    return NULL;
  }
  
  list->head = NULL;
  
  list_size = 0;
  
  return list;
}

void ListDisplay(List * list) 
{
  Node * current = list->head;
  
  if(list->head == NULL) 
  {
    return;
  }
  
  printf("Size = %d\n", list_size);
  
  for(; current != NULL; current = current->next) 
  {
    printf("%d-", current->data);
  }
  printf("\n");
}

/**
 *  add unique data to list
 * 
 * */
bool ListAdd(uint16_t data, List * list)
{
  bool ok = false;
  Node * current = NULL;
  
  if(list->head == NULL)
  {
    list->head = createnode(data);
    ok = true;
  }
  else 
  {
    current = list->head; 
    
    while((current->next != NULL))
    {
      if(current->data == data)
      {
        ok = false;
        return ok;
      }
      current = current->next;
    }
    current->next = createnode(data);
    ok = true;
  }

  return ok;
}

bool ListDelete(uint16_t data, List * list)
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
      list_size--;
      ok = true;
      
      return ok;
    }                               
    previous = current;             
    current = current->next;        
  }

  return ok;                               
}                                   

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

void ListDestroy(List * list)
{
  Node * current = list->head;
  Node * next = current;
  
  while(current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  
  free(list);
}
