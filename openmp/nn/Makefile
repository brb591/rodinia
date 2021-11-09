LOCAL_CC = gcc -g -O3 -Wall
CC = clang
CC_FLAGS = -Xclang -fopenmp -g -O2
CFLAGS = -lm -fopenmp -Wall


all : nn hurricane_gen

clean :
	rm -rf *.o nn hurricane_gen

nn : nn_openmp.o
	$(CC) $(CC_FLAGS) nn_openmp.o -o nn -lm -lomp 

hurricane_gen : hurricane_gen.o
	$(CC) $(CC_FLAGS) hurricane_gen.o -o hurricane_gen -lm -lomp

nn_openmp.o: nn_openmp.c
	$(CC) $(CC_FLAGS) nn_openmp.c -c

hurricane_gen.o: hurricane_gen.c
	$(CC) $(CC_FLAGS) hurricane_gen.c -c
