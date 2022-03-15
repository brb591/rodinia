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

srad: srad.cpp
	$(CC) $(CCFLAGS) srad.cpp -o srad $(LDFLAGS)

clean:
	rm -f srad
	rm -rf srad.dSYM