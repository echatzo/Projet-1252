#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include "libfractal/fractal.h"
#include "buffer.h"
#include "main.h"
#include "producer.h"
#include "compute.h"

list_length = 0;


struct node *new_list(){
  struct node *buffer = (struct node *) malloc(list_length * sizeof(struct node));
  return buffer;
}

//adds a fractal to the buffer
void add_fract (struct fractal *added){

  struct node *new = (struct node *) malloc (sizeof(struct node));

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

//removes a fractal from the buffer
void remove_fract (){
  if (first == NULL){
    return;
  }

  if (first == last){
    first = NULL;
  }

last = last -> previous;
  last -> next = NULL;
}
