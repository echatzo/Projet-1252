Projet 1252


run `make` in order to compile,
then run `$ ./main [-d] [--maxthreads n] file1 file2 ... fileN Outputfile` to use it

the `-d` option generates a BMP file for every fractal
the `--maxthreads n` option sets a maximum of `n` calculation threads

If you want to delete the .o just run `make shallowclean`
and if you want to delete every generate file, even the executable, run `make deepclean`
