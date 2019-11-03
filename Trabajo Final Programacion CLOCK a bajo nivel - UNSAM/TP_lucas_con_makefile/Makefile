all: TP_IMPAR_LUCAS_MANCINI

TP_IMPAR_LUCAS_MANCINI: main.o ejercicios.o RTC_utils.o
	gcc main.o ejercicios.o RTC_utils.o -o TP_IMPAR_LUCAS_MANCINI

main:
	gcc -c main.c

ejercicios:
	gcc -c ejercicios.c

RTC_utils: 
	gcc -c RTC_utils.c

clean:
	rm -rf *o TP_IMPAR_LUCAS_MANCINI

