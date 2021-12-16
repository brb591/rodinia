# C compiler
CC = g++
ICC = icc
CC_FLAGS = -g -O3 -Xclang -fopenmp
OFFLOAD_CC_FLAGS = -offload-option,mic,compiler,"-no-opt-prefetch"

all: needle needle_offload

needle: 
	$(CC) $(CC_FLAGS) needle.cpp -o needle -lomp

needle_offload:
	$(ICC) $(CC_FLAGS) $(OFFLOAD_CC_FLAGS) -DOMP_OFFLOAD needle.cpp -o needle_offload -lomp

clean:
	rm -f needle needle_offload
