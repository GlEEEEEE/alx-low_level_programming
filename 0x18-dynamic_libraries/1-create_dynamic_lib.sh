#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic -c -fPIC *.c
gcc -shared -o liball.so *.o
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
gcc -shared -o liball.so *.c
export LD_LIBRARY_PATH.:$LD_LIBRARY_PATH
