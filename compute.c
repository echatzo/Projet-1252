#include <assert.h>
#include <error.h>
#include <getopt.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "buffer.h"
#include "compute.h"
#include "file_reader.h"
#include "libfractal/fractal.h"
#include "main.h"

void *compute(void)
{
	struct fractal *computing_fract = NULL;


	while (curently_reading != 0) {
		computing_fract = NULL;

		sem_wait(&full);
		pthread_mutex_lock(&mutex_buffer);
		computing_fract = dequeue();
		pthread_mutex_unlock(&mutex_buffer);
		sem_post(&empty);

		check(!computing_fract, "dequeue error.");

		int x = 0;
		int y = 0;
		int width = fractal_get_width(computing_fract);;
		int height = fractal_get_height(computing_fract);
		int value = 0;

		double average = 0;
		double total = width * height;

		log_info("Lancement du calcul de fractales");
		for ( y = 0; y < height ; y++) {
			for( x = 0; x < width ; x++)  {
				value = fractal_compute_value(computing_fract, x, y);
				average += value;
			}
			log_info("Vous etes ici");
		}

		average /= total;

		computing_fract->average = average;

		char n[SIZE_MAX] = "";
		char *name = n;

		strcpy(name, computing_fract->name);
		strcat(name, ".bmp");

		if (draw_every_fract) { // option d active
			write_bitmap_sdl(computing_fract, name);
		}

		log_info("Fin du calcul de fractales");
	}

	return (void *) computing_fract;

	error:
		free(computing_fract);
		exit(EXIT_FAILURE);
}
