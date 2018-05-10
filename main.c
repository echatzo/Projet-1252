#include <stdio.h>
#include <stdlib.h>
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
pthread_t *calculator_threads;

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

  buffer_size = thread_limit;
	buffer = new_list();

  reader_threads = (pthread_t *) malloc(count_files * sizeof(pthread_t));
	calculator_threads = (pthread_t *) malloc(count_files * sizeof(pthread_t));
    /* TODO */

    return 0;
}
