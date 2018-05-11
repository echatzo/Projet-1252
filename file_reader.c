#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

#include "file_reader.h"
#include "buffer.h"
#include "compute.h"
#include "libfractal/fractal.h"
#include "main.h"
#include "declarations.h"

void *file_reader (char *file_name){

  FILE *to_read = NULL;
  to_read = fopen(file_name,"r");

  if (to_read == NULL){
    perror("Error : ");
  }

  struct fractal *new_fract = NULL;
  char line[line_length], fract_name[name_length];
	int width, height;
  double a, b;

  while(fgets(line, line_length, to_read)){
    if (line[0] != '#' && sscanf(line, "%s %d %d %lf %lf", fract_name, &width, &height, &a, &b) == 5){
      new_fract = fractal_new(fract_name, width, height, a, b);

      sem_wait(&empty);
			pthread_mutex_lock(&mutex_buffer);
			sem_wait(&full);
			pthread_mutex_lock(&mutex_buffer);
    }
    else {
      perror("Error : ");
    }
  }

  pthread_mutex_lock(&mutex_closing);
	curently_reading=0;
	pthread_mutex_unlock(&mutex_closing);

  return NULL;
}
