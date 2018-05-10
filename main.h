#ifndef _MAIN_H
#define _MAIN_H

//maximum number of calculation threads
extern int thread_limit;
//true if d option is in use, false otherwise
extern bool draw_every_fract;
//number of files
extern int files_number;
//number of files curently read
extern int curently_reading;
//size of the buffer
extern int buffer_size;
//buffer
extern struct node *buffer;
extern struct node *first;
extern struct node *last;
//best average of the fractales
extern double best_average;
//factal which has the best average
extern struct fractal *best;
//threads
extern pthread_mutex_t mutex_buffer;
extern pthread_mutex_t mutex_closing;
extern pthread_mutex_t mutex_best;
extern sem_t empty;
extern sem_t full;

//producer and consumer
extern pthread_t *read_threads;
extern pthread_t *compute_threads;

#endif
