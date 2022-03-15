UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC = gcc
	CCFLAGS = -g -fopenmp -O2
	LDFLAGS = -lm
endif
ifeq ($(UNAME_S),Darwin)
	CC = clang
	CCFLAGS = -Xclang -fopenmp -g -O2
	LDFLAGS = -lm -lomp
endif

all : nn hurricane_gen

clean :
	rm -rf *.o nn hurricane_gen

nn : nn_openmp.o
	$(CC) $(CCFLAGS) nn_openmp.o -o nn $(LDFLAGS) 

hurricane_gen : hurricane_gen.o
	$(CC) $(CCFLAGS) hurricane_gen.o -o hurricane_gen $(LDFLAGS)

nn_openmp.o: nn_openmp.c
	$(CC) $(CCFLAGS) nn_openmp.c -c

hurricane_gen.o: hurricane_gen.c
	$(CC) $(CCFLAGS) hurricane_gen.c -c
