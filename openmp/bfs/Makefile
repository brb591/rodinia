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

all: bfs bfs_offload

bfs: bfs.cpp 
	$(CC) $(CCFLAGS) bfs.cpp -o bfs $(LDFLAGS)

bfs_offload: bfs.cpp
	$(ICC) $(CCFLAGS) -DOMP_OFFLOAD bfs.cpp -o bfs_offload

clean:
	rm -f bfs bfs_offload result.txt
	rm -rf bfs.dSYM
