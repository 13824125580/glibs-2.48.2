INCLUDE=-I/home/zilong/WorkSpace/glib/libs/include \
	-I/home/zilong/WorkSpace/glib/libs/lib/glib-2.0/include \
	-I/home/zilong/WorkSpace/glib/libs/include/glib-2.0 

#LIBS=-Wl,-L/home/zilong/WorkSpace/glib/libs/lib/ -lgobject-2.0 -lglib-2.0
LIBS=/home/zilong/WorkSpace/glib/libs/lib/libgobject-2.0.so.0.4800.2 /home/zilong/WorkSpace/glib/libs/lib/libglib-2.0.so.0.4800.2
CC = gcc
all:
	$(CC) -g3 -c boy.c ${INCLUDE}
	$(CC) -g3 -c man.c ${INCLUDE}
	$(CC) -g3 -c main.c ${INCLUDE}
	$(CC) -g3 -c some.c ${INCLUDE}
	$(CC) -g3 -o simple main.o boy.o man.o  ${LIBS}
clean:
	-rm -fr *.o simple
