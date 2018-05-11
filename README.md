
Projet 1252, group 86 [Clement Chardon and Edouard Chatzopoulos]


-- How to use this program : -----------

run `make` in order to compile,
then run `$ ./main [-d] [--maxthreads n] file1 file2 ... fileN Outputfile` to use it

the `-d` option generates a BMP file for every fractal
the `--maxthreads n` option sets a maximum of `n` calculation threads



for a simpler use we included a "quick run" option to run the program with two calculation threads which takes all the .txt files in tests/inputs/ as inputs
with -d option on by defaults.



-- And then ? : ------------------------

If you want to get rid of the generated files and executables simply run `make clean`

-- Running tests :  --------------------

there are also some Cunit test files for libractal which you can use by running `make test`
