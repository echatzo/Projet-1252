#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h>
#include "libfractal/fractal.h"
#include "buffer.h"
#include "main.h"
#include "file_reader.h"

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
    /* TODO */

    return 0;
}
