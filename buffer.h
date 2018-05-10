#ifndef _BUFFER_H
#define _BUFFER_H

struct node {
  fractal_t *fract;
  struct node *next;
  struct node *previous;
}

struct node *new_list();

void add (fractal *added);

void remove();

#endif
