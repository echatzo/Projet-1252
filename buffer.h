#ifndef _BUFFER_H
#define _BUFFER_H


struct node {
  struct fractal *fract;
  struct node *next;
  struct node *previous;
};

struct node *new_list();

void add_fract (struct fractal *added);

void remove_fract();

extern struct node *buffer;
extern struct node *first;
extern struct node *last;
extern int list_length;


#endif
