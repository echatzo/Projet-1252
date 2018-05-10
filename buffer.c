#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


struct node *new_list(){
  struct node *buffer = (node *) malloc(list_length * sizeof(node));
  return buffer;
}

void add (fractal *added){

  struct node *new;

  new -> fract = added;
  new -> next = first;
  new -> previous = NULL;

  if (first == NULL){
    first = new;
    last = first;
    list_length = 1;
  } else {
    first -> previous = new;
    first = new;
    list_length++;
  }
}

void remove (){
  if (first == NULL){
    return;
  }

  if (first == last){
    first = NULL;
  }

last = last -> previous;
  last -> next = NULL;
}
