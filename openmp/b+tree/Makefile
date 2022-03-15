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

b+tree.out:	./main.o ./kernel/kernel_cpu.o ./kernel/kernel_cpu_2.o ./util/timer/timer.o ./util/num/num.o
	$(CC)	$(CCFLAGS) ./main.o ./kernel/kernel_cpu.o ./kernel/kernel_cpu_2.o ./util/timer/timer.o ./util/num/num.o -o b+tree.out $(LDFLAGS)

main.o:	./common.h ./main.h ./main.c
	$(CC)	$(CCFLAGS) ./main.c -c -o ./main.o

./kernel/kernel_cpu.o:	./common.h ./kernel/kernel_cpu.h ./kernel/kernel_cpu.c
	$(CC)	$(CCFLAGS) ./kernel/kernel_cpu.c -c -o ./kernel/kernel_cpu.o

./kernel/kernel_cpu_2.o:./common.h ./kernel/kernel_cpu_2.h ./kernel/kernel_cpu_2.c
	$(CC)	$(CCFLAGS) ./kernel/kernel_cpu_2.c -c -o ./kernel/kernel_cpu_2.o

./util/timer/timer.o:	./common.h ./util/timer/timer.h ./util/timer/timer.c
	$(CC)	$(CCFLAGS) ./util/timer/timer.c -c -o ./util/timer/timer.o

./util/num/num.o:	./common.h ./util/num/num.h ./util/num/num.c
	$(CC)	$(CCFLAGS) ./util/num/num.c -c -o ./util/num/num.o

clean:
	rm	*.o *.out ./kernel/*.o ./util/timer/*.o ./util/num/*.o output.txt
