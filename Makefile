CC = gcc
PROG_NAME = parish
FLAGS = `pkg-config --cflags --libs gtk+-2.0` -export-dynamic

install : callback.o ${PROG_NAME}.o
	${CC} -Wall -o ${PROG_NAME} callback.o ${PROG_NAME}.o ${FLAGS}

callback.o :
	${CC}  -Wall -c -o callback.o ${PROG_NAME}_callbacks.c ${FLAGS}

${PROG_NAME}.o :
	${CC} -Wall -c -o ${PROG_NAME}.o ${PROG_NAME}_main.c ${FLAGS}

clean: 
	rm -rf *.o
	rm -rf ${PROG_NAME}
