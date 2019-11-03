Este Tp tiene como objetivo manejar funciones que operan a bajo nivel sobre los registros del CLOCK de una PC para acceder a los puertos de Hardware.
(se debe correr con sudo y en algunos sistemas operativos es imposible conseguir el acceso al clock)

Consignas:---------------------------------------------------------------------------------------------

Resolver los siguientes problemas accediendo a los puertos (ports) de hardware en C sobre Linux.
Todos los ítems deben ser resueltos por un único programa que implemente un menú y muestre en
pantalla el nombre y legajo del autor.
1) Mostrar el contenido de los registros 0 al 13. El contenido se debe mostrar en forma de tabla
donde cada fila corresponde a un registro y con las siguientes columnas correctamente
alineadas y en el orden en que figuran:
Binario (los bits tal cual se leen)
Hexadecimal (que corresponde a los bits tal cual se leen)
Descripción
Cantidad de bits en “1” que hay en el valor
2) Utilizando el RTC programar una alarma que se active:
a) A determinada hora ingresada por teclado (HH:MM:SS).
b) Cada minuto.
Al activarse la alarma debe aparecer un mensaje que lo informe.
3) Utilizando el RTC obtener un tren de pulsos de 2Hz realizando un muestreo del registro C y
graficarlo en pantalla en tiempo real usando caracteres simples, por ejemplo:
0---+---1---+---2---+---3---+---4---+---5---+---6---+---7---+---8---+---9---+---
___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|

El programa debe graficar al menos 10 segundos. No omitir la escala de tiempo como se ve en el
ejemplo de arriba.
4) Enviar por el puerto paralelo el campo minutos de la hora obtenida del RTC. Muestre en pantalla
el valor que escribe en el puerto y el valor que debería leer del otro lado.


Notas sobre TP PROGRAMACIÓN a bajo nivel - Lucas Mancini------------------------------------------------------------------------

general:
-System clock and RTC
Every PC includes a chip called a Real Time Clock (RTC) which is independent of all the other chips and is used to maintain the time even when the system is powered off. 
Besides the time keeping feature, the RTC can generate different types of interrupts.
Tablas:
-Tabla de puertos RTC:

+-------+------------------+
| Port  |  	Use     	|
+-------+------------------+
| 0x70  | RTC Address Port
+-------+------------------+
| 0x71  | RTC Data Port
+-------+------------------+

-Tabla interrna de los puertos RTC
+-------------------------+----------------------------------+
| RTC internal address	|      	Value Stored        	|
+-------------------------+----------------------------------+
| 0x00                	|   	Current Time Seconds   	|
+-------------------------+----------------------------------+
| 0x01                	|      	Alarm Seconds       	|
+-------------------------+----------------------------------+
| 0x02                	|   	Current Time Minutes   	|
+-------------------------+----------------------------------+
| 0x03                	|      	Alarm Minutes       	|
+-------------------------+----------------------------------+
| 0x04                	|    	Current Time Hours    	|
+-------------------------+----------------------------------+
| 0x05                	|       	Alarm Hours        	|
+-------------------------+----------------------------------+
| 0x06                	|  	Day of Week (Sunday = 1)	|
+-------------------------+----------------------------------+
| 0x07                	|      	Date of Month       	|
+-------------------------+----------------------------------+
| 0x08                	|          	Month           	|
+-------------------------+----------------------------------+
| 0x09                	| 	Year (The last two digits)   |
+-------------------------+----------------------------------+
| 0x32                	|     	Current Century      	|
|                     	|	(The first two year digits)   |
+-------------------------+----------------------------------+
| 0x0a                	|    	Status Register A     	|
+-------------------------+----------------------------------+
| 0x0b                	|    	Status Register B     	|
o tambien, con mas info (del 0 al 9):



-Tabla de bits del Registro B
 
+--------------+---------------------------------------------------+
|                            	Status Register B             	|
+--------------+---------------------------------------------------+
| Bit Position |           	Interpretation                  	|
+--------------+---------------------------------------------------+
|  7       	|        	Enable Cycle Update                	|
+--------------+---------------------------------------------------+
|  6       	|     	Enable Periodic Interrupt             	|
+--------------+---------------------------------------------------+
|  5       	|      	Enable Alarm Interrupt               	|
+--------------+---------------------------------------------------+
|  4       	|    	Enable Update-End Interrupt            	|
+--------------+---------------------------------------------------+
|  3       	|     	Enable Square Wave Output             	|
+--------------+---------------------------------------------------+
|  2       	|  	Data Mode : 0 – BCD  /  1 – Binary       	|
+--------------+---------------------------------------------------+
|  1       	| 12/24 Hour Mode : 0 – 12 Hour /  1 – 24 Hour  	|
+--------------+---------------------------------------------------+
|  0       	| Day light saving enabled : 1 enabled / 0 disabled |
+--------------+---------------------------------------------------+


-funcion ioperm:
int ioperm(unsigned long from, unsigned long num, int turn_on);
DESCRIPTION      
      ioperm() sets the port access permission bits for the calling thread
       for num bits starting from port address from.  If turn_on is nonzero,
       then permission for the specified bits is enabled; otherwise it is
       disabled.  If turn_on is nonzero, the calling thread must be
       privileged (CAP_SYS_RAWIO).

-funcion outb:
void outb(unsigned char value, unsigned short int port);
DESCRIPTION
   This family of functions is used to do low-level port input and  output.
   The  out* functions do port output the
   b-suffix functions are byte-width.



-funcion inb:
the in* functions do port input; the
   b-suffix functions are byte-width.


-funcion definida in():


/* Esta funcion lee un byte del registro del RTC cuyo nro se recibe */

unsigned char in (unsigned char reg){

  outb (reg, PUERTO_BASE); 

  return inb(PUERTO_BASE + 1);
}


-ejercicio 1: 

Mostrar el contenido de los registros 0 al 13. El contenido se debe mostrar en forma de tabla donde cada fila corresponde a un registro y con las siguientes columnas correctamente alineadas y en el orden en que figuran: Binario (los bits tal cual se leen) Hexadecimal (que corresponde a los bits tal cual se leen) Descripción Cantidad de bits en “1” que hay en el valor.

Pasos de la función:

-pedir permisos para el puerto RTC → 0x70 y 0x71
	ioperm(puerto base → 0x70, cantidad a abrir → 2, permiso: Si → 1);

-checkear estado de uip: 


// Checkear el estado del UIP, si está en 1 (actualizando los registros anteriores) espera 1984μs, si esta en 0 hay al menos 244μs para trabajar

//obs: segun tabla el septimo bit del registro 0x0A denota si se esta por actualizar un registor

void check_uip_state(){
  unsigned char a;
  a = in (0x0A); 
// se revisa el registro 0x0A,,, ya que nos interesa el 7mo bit de este registro, para ver si se es esta por pasar de 59--> 00 en algun registro

  if((a & 0x80) != 0) {
 //0x80 == 10000000 tiene un 1 en la 7ma posicion, al hacer la operacion AND con el registro vamos a obtener un TRUE cuando se presente la accion del 7mo bit

  	usleep(1984); //espera para que no haya problemas de R/W
	}
}




-imprimir formato de la tabla
printf("N° Registro|\t   BCD|\t\tHexadecimal|\t\t\tDescripcion|\t\t\tN° de bits en 1|\n");

-imprimir contenido de la tabla:

  	for (i = 0x00 ; i < CANTIDAD_REGISTROS_1; i++) {
   	 data[i]=in(i);
   	 printf(" 	%d\t\t",i);
   	 imprime_bcd(data[i]);
   		 printf("	%02X\t",data[i]);
   	 printf("%51s\t",*(descripcion+i));
   	 printf("%9d",cantidad_de_unos(data[i]));
   	 printf(" \n");
      }



-ejercicio 2:  item a
Configurar alarma segun el ingreso por le teclado

pasos:

-permisos: perm(PUERTO_BASE, 2, 1);

-chequear uip:  check_uip_state();

-print de la hora actual: 

	printf("OBS: la hora actual es %02X:%02X:%02X\n",in(0x00),in(0x02),in(0x04));

-scanear el ingreso del usuario:
	scanf ("%hhx", &(tiempo_alarma[0]));
   	 scanf ("%hhx", &(tiempo_alarma[1]));
  	  scanf ("%hhx", &(tiempo_alarma[2]));

-ingreso de los valores de la alarma en los registros correspondientes (ver tabla)

out(tiempo_alarma[0], 0x01); //pone el valor asignado en seg en el registro "segundos alarma"
out(tiempo_alarma[1], 0x03); //pone el valor asignado en min en el registro "minutos alarma"
out(tiempo_alarma[2], 0x05); //pone el valor asignado en hora en el registro "hora alarma".-


















-deteccion de alarma por flag en el registro C:



reg_c = in (0x0C); // lectura de registro c para borrar eventos anteriores.

printf ("Esperando la alarma.\n");

	for (i = 0; i < 180; i++){ 
		reg_c = in (0x0C); //00001100
		
		if (reg_c & 0x20){
			printf ("Alarma!!!!!\n");
		}

		usleep(500000);   
	}

-ejercicio 2:  item b

-setear alarma con dont care en el pin de minutos para que la alarma se repita cada minuto

	tiempo_alarma[0]=0x00;
	tiempo_alarma[1]=0xFF; //0xFF hace que se repita indefinidamente

Es parecido al item anterior pero se establece un dont care:


-ejercicio 3:

-lectura de registro A + mascara para seteo de frecuencia + escritura
	reg_a = in(0x0A); //leo el registro 0A (0001010) --> el registro a
	reg_a = reg_a | (MASCARA_FRECUENCIA_SQW); //aplico una máscara para setear la frecuencia 
	out(reg_a,0x0A); //Seteo el registro A con la frecuencia a 2Hz.(setea velocidad clock)

	
-lectura de registro B + mascara para activar PIE + escritura
reg_b = in(0x0B);//leo el registro 0B(0001011)
	reg_b = reg_b | (0x40);// modifico el b para activar el PIE (periodic interrupt enable) que me habilita las interrupciones periodicas --> b|0100000
	out(reg_b,0x0B);//Seteo el registro A con el PIE activado







-impresion de guia para pulsos + flush del flujo de salida:

	printf("0---+---1---+---2---+---3---+---4---+---5---+---6---+---7---+---8---+---9---+---10\n");

	fflush(stdout); //limpia el buffer (imprime por pantalla lo que tiene stdout)

-impresion de pulsos con el PIE y la frecuencia definida en el REG_A:

	for(i=0;i<80;i++){ //como tengo la escala de 10, al usar octavos de segundo, se divide en 80 partes.
		state=(reg_c & 0x40);//checkeo el bit PF (periodic flag)

		if(state==1){  //si está en 1 indica que es necesario que se produzca la interrupción
			printf( CARACTER_PULSO);
		}
		else{
			printf(CARACTER_DELAY); //cuando esté en 0
		}
		usleep(125000); //Espero 1/8 de segundo por cada 4 da 1/2 segundo, 1/2 segundo = 2Hz.
		reg_c = in(0x0C); //limpio el registro
		fflush(stdout);//Limpio el buffer antes de arrancar el nuevo ciclo
	}







-ejercicio 4: 

-permisos a puerto paralelo:
	perm(PUERTO_IMPRESORA ,3 ,1); //Permiso a ports de la impresora

-envio de dato negado con outb (el dato salio del clock)
	outb(dato_transmitido, PUERTO_IMPRESORA);
 //Envio el dato negado por el registro de datos
-control STROBE se pone en 0, se espera un delay y luego se pone en 1

	outb(0x00, PUERTO_PARALELO_CONTROL); // pongo en 0 el registro de control.
	usleep(DELAY_STROBE); //
outb(0x01, PUERTO_PARALELO_CONTROL); // Lo vuelvo a poner en 1 el registro de control

-permisos a puerto paralelo:
	perm(PUERTO_IMPRESORA, 3, 0); //Quito los permisos de la impresora.

