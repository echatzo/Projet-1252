#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#include "file_reader.h"
#include "buffer.h"
#include "compute.h"
#include "libfractal/fractal.h"
#include "main.h"

void *file_reader (char *file_name){

  FILE *to_read = NULL;
  *to_read = fopen(file_name,"r");

  if (to_read == NULL){
    perror("Error : ");
  }

  struct fractal *new_fract = NULL;
  char line[500], fract_name[64];
	int width, height;
  double a, b;

  while(fgets(line, 500, to_read)){
    if (line[0] != '#' && sscanf(line, "%s %d %d %lf %lf", fract_name, &width, &height, &a, &b) == 5){
      new_fract = fractal_new(fract_name, width, height, a, b);
    }
    else {
      perror("Error : ");
    }
  }
  return NULL;
}
