#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *file_reader (char *name){

  File *to_read = NULL;
  to_read = fopen(name,"r");

  if (to_read == NULL){
    perror("Error : ");
  }

  fractal_t *new_fract = NULL;
  char line[500], name[65];
	int width, height;
  double a, b;

  while(fgets(line, 500, to_read)){
    if (line[0] != '#' && sscanf(line, "%s %d %d %lf %lf", name, &width, &height, &a, &b) == 5){
      new_fract = fractal_new(name, width, height, a, b);
    }
    else {
      perror("Error : ");
    }
  }
  return NULL;
}
