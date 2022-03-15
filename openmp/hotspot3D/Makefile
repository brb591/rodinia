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

3D: 3D.c
	$(CC) $(CCFLAGS) 3D.c -o 3D $(LDFLAGS)

clean:
	rm -f 3D *.out
	rm -rf 3D.dSYM
