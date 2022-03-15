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

# link objects(binaries) together
srad: main.o
	$(CC) $(CCFLAGS) main.o -o srad $(LDFLAGS)

# compile main function file into object (binary)
main.o: main.c define.c graphics.c
	$(CC) $(CCFLAGS) main.c -c

# delete all object files
clean:
	rm *.o srad
