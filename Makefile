CC = gcc
MKDIR = mkdir -p
SQLITEDB = parish.sqlite3
PROG_NAME = parish
FLAGS = `pkg-config --cflags --libs gtk+-2.0` -export-dynamic

install : common.o  database.o  baptism_callback.o search_main.o search_results.o parish_print.o parish_marriage.o ${PROG_NAME}.o
	echo "Creating config directory"
	${MKDIR} ~/.${PROG_NAME}
	${CC} -Wall  -o ${PROG_NAME} common.o search_main.o baptism_callback.o ${PROG_NAME}.o parish_print.o parish_marriage.o search_results.o  database.o -l sqlite3 ${FLAGS}

common.o :
		${CC} -Wall  -c -o common.o ${PROG_NAME}_common.c ${FLAGS}

database.o :
		${CC} -Wall -c -o database.o  database.c -l sqlite3  ${FLAGS}

baptism_callback.o :
		${CC} -Wall  -c -o baptism_callback.o ${PROG_NAME}_baptism_callbacks.c ${FLAGS}

search_main.o :
		${CC} -Wall -c -o search_main.o parish_search_main.c ${FLAGS}

search_results.o :
		${CC} -Wall -c -o search_results.o parish_search_results.c ${FLAGS}

parish_print.o :
		${CC} -Wall -c -o parish_print.o parish_print.c ${FLAGS}

parish_marriage.o :
		${CC} -Wall -c -o parish_marriage.o parish_marriage_callbacks.c ${FLAGS}


${PROG_NAME}.o :
		${CC} -Wall -c -o ${PROG_NAME}.o ${PROG_NAME}_main.c ${FLAGS}


clean: 
	rm -rf *.o
	rm -rf ${PROG_NAME}
