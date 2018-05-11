#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <error.h>
#include <getopt.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include "libfractal/fractal.h"
#include "buffer.h"
#include "main.h"
#include "file_reader.h"
#include "compute.h"


void *compute()
{
	struct fractal *computing_fract = NULL;


	while (curently_reading != 0) {
		computing_fract = NULL;

		sem_wait(&full);
		pthread_mutex_lock(&mutex_buffer);
		computing_fract = last;
		remove_fract();
		pthread_mutex_unlock(&mutex_buffer);
		sem_post(&empty);


		int x = 0;
		int y = 0;
		int width = fractal_get_width(computing_fract);;
		int height = fractal_get_height(computing_fract);
		int value = 0;

		double average = 0;
		double total = width * height; //superficie de la fractale


		for ( y = 0; y < height ; y++) {
			for( x = 0; x < width ; x++)  {
				value = fractal_compute_value(computing_fract, x, y);
				average += (double) value;//incrémente la 'valeur' de la fractale
			}
		}

		average /= total; //divise la valeur totale de la fractale par sa superficie pour obtenir sa valeur moyenne.

		computing_fract->average = average;

		char n[line_length] = "";
		char *name = n;

		strcpy(name, computing_fract->name);
		strcat(name, ".bmp");

		if (draw_every_fract) { // genere le bitmap si l'option d est active
			write_bitmap_sdl(computing_fract, name);
		}


	}

	return (void *) computing_fract; //retourne la fractale.

		free(computing_fract); //libère la mémoire de la fractale
		exit(EXIT_FAILURE);
}
