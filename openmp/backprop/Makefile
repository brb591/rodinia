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

backprop: backprop.o facetrain.o imagenet.o backprop_kernel.o 
	$(CC) $(CCFLAGS) backprop.o facetrain.o imagenet.o backprop_kernel.o -o backprop $(LDFLAGS)

%.o: %.[ch]
	$(CC) $(CCFLAGS) $< -c

facetrain.o: facetrain.c backprop.h
	$(CC) $(CCFLAGS) facetrain.c -c
	
backprop.o: backprop.c backprop.h
	$(CC) $(CCFLAGS) backprop.c -c

backprop_kernel.o: backprop_kernel.c backprop.h
	$(CC) $(CCFLAGS) backprop_kernel.c -c

imagenet.o: imagenet.c backprop.h
	$(CC) $(CCFLAGS) imagenet.c -c

clean:
	rm -f *.o *~ backprop
