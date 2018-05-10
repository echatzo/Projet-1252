#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <error.h>
#include <getopt.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include "libfractal/fractal.h"
#include "buffer.h"
#include "main.h"
#include "file_reader.h"


#define ARGOPT_D "-d"
#define ARGOPT_MAXTHREADS "--maxthreads"

bool draw_every_fract = false;

int thread_limit = 1;

int files_number = 0;

int buffer_size = 0;
struct node *buffer = NULL;
struct node *first = NULL;
struct node *last = NULL;

double best_average = 0;
struct fract *best = NULL;

pthread_mutex_t mutex_buffer;
pthread_mutex_t mutex_closing;
pthread_mutex_t mutex_best;
sem_t empty;
sem_t full;

pthread_t *reader_threads;
pthread_t *compute_threads;

int main(int argc, char *argv[])
{
  const char *files[argc];
	const char *fileOut = argv[argc-1]; //finds output file name

  int o = 0;
  for (o = 1; o < argc - 1; o ++){
    if (strcmp(argv[o], ARGOPT_D) == 0){  //searches if every fractal needs to be drawn
      draw_every_fract = true;
  } else if ( strcmp(argv[o], ARGOPT_MAXTHREADS) == 0) { //searches for a maximum amount of threads
      o++;
      if (o == argc) break;
      thread_limit = atoi(argv[o]);
    } else {
      files[files_number] = argv[o];
      files_number++;
    }
    }
  }



    int arg[thread_limit];
  	int e = 0;

  	for (o = 0; o < count_files; o++)  {
  		printf("File %d : %s.\n", o+1, files[o]);
  	}

  	pthread_mutex_init(&mutex_buffer, NULL);
  	pthread_mutex_init(&mutex_closing, NULL);
  	pthread_mutex_init(&mutex_best, NULL);
  	sem_init(&empty, 0, thread_limit);
  	sem_init(&full, 0, 0);

  buffer_size = thread_limit;
	buffer = new_list();

  reader_threads = (pthread_t *) malloc(files_number * sizeof(pthread_t));
	compute_threads = (pthread_t *) malloc(files_number * sizeof(pthread_t));


	for (o = 1; o < count_files; o++) {
		pthread_create(&(reader_threads[curently_reading]), NULL,
					&reader, (void *)files[o]);
	}


	for (o = 0; o < thread_limit; o++) {
	pthread_create(&(compute_threads[o]), NULL, &compute, &(arg[o]));
	}

  for (o = 0; o < thread_limit; o++) {
  		struct fractal *fract_jetable;
      pthread_join(compute_threads[o], (void **) &fract_jetable);
  		if ( best == NULL) {
  			best = fract_jetable;
  		} else if (best->average < fract_jetable->average) {
  			fractal_free((struct fractal *) best);
  			best = (struct fractal *) fract_jetable;
  		} else {
  			fractal_free(fract_jetable);
  		}
  	}

    e = write_bitmap_sdl(best, fileOut);

    return e;
    error:
      exit(EXIT_FAILURE);
}
