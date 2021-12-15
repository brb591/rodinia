CC = clang
CC_FLAGS = -Xclang -fopenmp -g -O2

ifdef OUTPUT
override OUTPUT = -DOUTPUT
endif

# link objects(binaries) together
heartwall: main.o ./AVI/avilib.o ./AVI/avimod.o
	$(CC) $(CC_FLAGS) main.o ./AVI/avilib.o ./AVI/avimod.o -o heartwall -lm -lomp

# compile main function file into object (binary)
main.o: main.c define.c kernel.c
	$(CC) $(CC_FLAGS) main.c -c -I./AVI
	#gcc $(OUTPUT) main.c -I./AVI -c -O3 -fopenmp

./AVI/avilib.o ./AVI/avimod.o:
	cd AVI; make;

# delete all object files
clean:
	rm -f *.o AVI/*.o heartwall
