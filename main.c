#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h>
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


  buffer_size = thread_limit;
	buffer = new_list();

    /* TODO */

    return 0;
}
