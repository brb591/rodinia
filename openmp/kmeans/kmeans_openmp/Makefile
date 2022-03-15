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

kmeans: cluster.o getopt.o kmeans.o kmeans_clustering.o 
	$(CC) $(CCFLAGS) cluster.o getopt.o kmeans.o kmeans_clustering.o  -o kmeans $(LDFLAGS)

%.o: %.[ch]
	$(CC) $(CCFLAGS) $< -c

cluster.o: cluster.c 
	$(CC) $(CCFLAGS) cluster.c -c
	
getopt.o: getopt.c 
	$(CC) $(CCFLAGS) getopt.c -c
	
kmeans.o: kmeans.c 
	$(CC) $(CCFLAGS) kmeans.c -c

kmeans_clustering.o: kmeans_clustering.c kmeans.h
	$(CC) $(CCFLAGS) kmeans_clustering.c -c

clean:
	rm -f *.o *~ kmeans 
