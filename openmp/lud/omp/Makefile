# Makefile for LU Decomposition
#
#

UNAME_S := $(shell uname -s)

# DEBUG can be set to YES to include debugging info, or NO otherwise
DEBUG          := NO

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

lud_omp: lud.o lud_omp.o ../common/common.o
	$(CC) $(CCFLAGS) lud.o lud_omp.o ../common/common.o -o lud_omp $(LDFLAGS)

lud.o: lud.c
	$(CC) $(CCFLAGS) lud.c -c -I../common

lud_omp.o: lud_omp.c
	$(CC) $(CCFLAGS) lud_omp.c -c -I../common

../common/common.o: ../common/common.c ../common/common.h
	$(CC) $(CCFLAGS) ../common/common.c -c -o ../common/common.o -I../common

clean:
	rm -f *.o ../common/*.o lud_omp