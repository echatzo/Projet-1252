#ifndef _DECLARATIONS_H
#define _DECLARATIONS_H

#define SIZE_MAX 500
#define NAME_LEN 65

extern int thread_limit;
extern int list_length;
extern int files_number;
extern int curently_reading;

extern bool draw_every_fract;

extern double best_average;

extern struct fractal *best;

extern struct node *buffer;
extern struct node *first;
extern struct node *last;


extern pthread_mutex_t mutex_buffer;
extern pthread_mutex_t mutex_closing;
extern pthread_mutex_t mutex_best;

extern sem_t empty;
extern sem_t full;

extern pthread_t *read_threads;
extern pthread_t *compute_threads;

#endif
