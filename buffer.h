#ifndef _BUFFER_H
#define _BUFFER_H

struct node {
  struct fractal *fract;
  struct node *next;
  struct node *previous;
};

struct node *new_list();

void add (struct fractal *added);

void remove_fract();

#endif
