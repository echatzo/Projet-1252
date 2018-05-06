#include <stdlib.h>
#include "fractal.h"

struct fractal *fractal_new(const char *name, int width, int height, double a, double b)
{
  fractal_t *fract = (fractal_t *) malloc(sizeof(fractal_t *));
  check_mem(fract);
  int n = 64;
  strncpy(fract->name, name, (size_t) n);

  f->values = (int *) malloc(height * width * sizeof(int));
  check_mem(fract);

  fract->h = height;
  fract->w = width;
  fract->a = a;
  fract->b = b;


  return fract;
  error:
    if(fract) free(fract);
    if(fract->values) fractal_free(fract->values);
    exit(EXIT_FAILURE);
}

void fractal_free(struct fractal *f)
{
    free(f->values);
    free(f);
}

const char *fractal_get_name(const struct fractal *f)
{
    return f->name;
}

int fractal_get_value(const struct fractal *f, int x, int y)
{
    int width = fractal_get_width(f);
    int linpos = y*width+x;
    return f->values[linpos];
}

void fractal_set_value(struct fractal *f, int x, int y, int val)
{
  int width = fractal_get_width(f);
  int linpos = y*width+x;
  f->values[linpos] = val;
}

int fractal_get_width(const struct fractal *f)
{
    return f->w;
}

int fractal_get_height(const struct fractal *f)
{
    return f->h;
}

double fractal_get_a(const struct fractal *f)
{
    return f->a;
}

double fractal_get_b(const struct fractal *f)
{
    return f->b;
}
