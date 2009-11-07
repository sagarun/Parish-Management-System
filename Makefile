CC = gcc
MKDIR = mkdir -p
SQLITEDB = parish.sqlite3
PROG_NAME = parish
FLAGS = `pkg-config --cflags --libs gtk+-2.0` -export-dynamic

install : common.o callback.o ${PROG_NAME}.o database.o
	echo "Creating config directory"
	${MKDIR} ~/.${PROG_NAME}
	${CC} -Wall -o ${PROG_NAME} common.o baptism_callback.o ${PROG_NAME}.o database.o -l sqlite3 ${FLAGS}

common.o :
	${CC} -Wall -c -o common.o ${PROG_NAME}_common.c ${FLAGS}

callback.o :
	${CC}  -Wall -c -o baptism_callback.o ${PROG_NAME}_baptism_callbacks.c ${FLAGS}

${PROG_NAME}.o :
	${CC} -Wall -c -o ${PROG_NAME}.o ${PROG_NAME}_main.c ${FLAGS}

database.o :
	${CC} -Wall -c -o database.o database.c -l sqlite3 ${FLAGS}

clean: 
	rm -rf *.o
	rm -rf ${PROG_NAME}
	rm -rf ${SQLITEDB}
