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
    if (strcmp(argv[o], ARGOPT_D) == 0){  //searches for option -d
      draw_every_fract = true;
  } else if ( strcmp(argv[o], ARGOPT_MAXTHREADS) == 0) {
      o++;
      if (o == argc) break;
      thread_limit = atoi(argv[o]);
    } else {
      files[files_number] = argv[o];
      files_number++;
    }
    }
  }

  log_info("Draw every fracatal option active?");
  	if (draw_every_fract) log_info("Yes.");
  	else log_info("No.");
  	log_info("%d calculations threads.", thread_limit);
  	log_info("There are %d inputs.", files_number);
  	log_info("Output file is %s.", fileOut);

    int arg[thread_limit];
  	int err = 0;

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

  log_info("Creating reader threads");
	for (o = 1; o < count_files; o++) {
		check(!pthread_create(&(reader_threads[curently_reading]), NULL,
					&reader, (void *)files[o]),
					"Error while creating reader pthread");
	} log_info("There are %d open files.", curently_reading);

	log_info("Creating compute threads");
	for (o = 0; o < thread_limit; o++) {
		check(!pthread_create(&(compute_threads[o]), NULL,
				&compute, &(arg[o])),
				"Error while creating compute pthread.");
	}

  for (o = 0; o < thread_limit; o++) {
  		struct fractal *fract_jetable;
  		check(!pthread_join(compute_threads[o], (void **) &fract_jetable),
  				"Join calculation thread problem %i.", o);
  		if ( best == NULL) {
  			best = fract_jetable;
  		} else if (best->average < fract_jetable->average) {
  			log_info("Getting best of thread %i.", o);
  			fractal_free((struct fractal *) best);
  			best = (struct fractal *) fract_jetable;
  		} else {
  			fractal_free(fract_jetable);
  		}
  	}



    /* TODO */

    return 0;
}
