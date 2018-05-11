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

void *file_reader (char *file_name){

  FILE *to_read = NULL;
  to_read = fopen(file_name,"r");
  int line_number = countlines(to_read);

  if (to_read == NULL){
    perror("Error : ");
  }

  struct fractal *new_fract = NULL;
  char line[line_length], fract_name[name_length];
	int width, height;
  double a, b;

  int o;

  for (o=0; o < line_number; o++){

    fgets(line, line_length, to_read);

    if (line[0] != '#' && sscanf(line, "%s %d %d %lf %lf", fract_name, &width, &height, &a, &b) == 5){
      new_fract = fractal_new(fract_name, width, height, a, b);

      sem_wait(&empty);
			pthread_mutex_lock(&mutex_buffer);
      add_fract(new_fract);
			sem_wait(&full);
			pthread_mutex_lock(&mutex_buffer);
    }
    else {
      perror("Error : ");
    }
  }

  fclose(to_read);

  pthread_mutex_lock(&mutex_closing);
	curently_reading--;
	pthread_mutex_unlock(&mutex_closing);

  return NULL;
}

int countlines(FILE *to_count){

  int ch=0;
  int lines=0;

  if (to_count == NULL){
    return 0;
  }

  lines++;
  while(!feof(to_count)){
    ch = fgetc(to_count);
    if(ch == '\n')
    {
      lines++;
    }
  }
  return lines;
}
