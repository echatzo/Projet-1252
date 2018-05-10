#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include "libfractal/fractal.h"
#include "buffer.h"
#include "main.h"
#include "file_reader.h"
#include "compute.h"


struct node *new_list(){
  struct node *buffer = (struct node *) malloc(list_length * sizeof(struct node));
  return buffer;
}

void add (struct fractal *added){

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
