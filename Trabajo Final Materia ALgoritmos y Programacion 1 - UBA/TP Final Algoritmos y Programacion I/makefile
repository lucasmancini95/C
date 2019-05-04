CC= gcc
CFLAGS= -Wall -ansi -pedantic -g

all: inventory clean

inventory: main.o register.o inventory.o product.o html.o setting.o util.o vector.o xml.o
	$(CC) $(CFLAGS) -o inventory main.o register.o inventory.o product.o html.o setting.o util.o vector.o xml.o

main.o: main.c main.h setting.h vector.h product.h html.h xml.h inventory.h register.h type.h
	$(CC) $(CFLAGS) -o main.o -c main.c

register.o: register.c register.h type.h lang.h util.h
	$(CC) $(CFLAGS) -o register.o -c register.c

inventory.o: inventory.c inventory.h type.h
	$(CC) $(CFLAGS) -o inventory.o -c inventory.c

product.o: product.c product.h type.h
	$(CC) $(CFLAGS) -o product.o -c product.c

html.o: html.c html.h type.h product.h
	$(CC) $(CFLAGS) -o html.o -c html.c

setting.o: setting.c setting.h type.h
	$(CC) $(CFLAGS) -o setting.o -c setting.c

util.o: util.c util.h type.h
	$(CC) $(CFLAGS) -o util.o -c util.c

vector.o: vector.c vector.h type.h util.h
	$(CC) $(CFLAGS) -o vector.o -c vector.c

xml.o: xml.c xml.h product.h type.h
	$(CC) $(CFLAGS) -o xml.o -c xml.c

clean:
	rm *.o
