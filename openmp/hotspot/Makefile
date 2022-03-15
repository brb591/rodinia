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
# C compiler
ICC = icc
OFFLOAD_CC_FLAGS = -offload-option,mic,compiler,"-no-opt-prefetch"

all: hotspot hotspot_offload 


hotspot: hotspot_openmp.cpp Makefile 
	$(CC) $(CCFLAGS) hotspot_openmp.cpp -o hotspot $(LDFLAGS)

hotspot_offload: hotspot_openmp.cpp Makefile
	$(ICC) $(CC_FLAGS) $(OFFLOAD_CC_FLAGS) -DOMP_OFFLOAD hotspot_openmp.cpp -o hotspot_offload

clean:
	rm -f hotspot hotspot_offload output.out
	rm -rf hotspot.dSYM
