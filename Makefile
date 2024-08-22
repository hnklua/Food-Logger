CPP = g++
FLAGS = -Wall -pedantic -g 

EXEC = foodLogger
OBJS = main.o

default: ${EXEC}

clean:
	rm -f ${EXEC}
	rm -f *.o

run: ${EXEC}
	./${EXEC} ${ARGS}

debug: ${EXEC}
	ddd ./${EXEC}

${EXEC}: ${OBJS}
	${CPP} ${FLAGS} -o ${EXEC} ${OBJS} -lm

.cpp.o:
	${CPP} ${FLAGS} -c $<

valgrind: ${EXEC}
	LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libasan.so.6 valgrind --leak-check=full --show-leak-kinds=all ./${EXEC}

main.o: main.cpp foodHash.hpp foodItem.hpp readCSV.hpp userData.hpp

