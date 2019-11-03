
#include "unistd.h"
#include "sys/io.h"
#include "sys/perm.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "RTC_utils.h"
#include "ejercicios.h"

//funciones ejercicio 1:

void ejercicio_1(){	//funcion principal

	int data[CANTIDAD_REGISTROS_1];
  	int i;
	char* descripcion[CANTIDAD_REGISTROS_1] = {"segundos", "segundos alarma", "minutos", "minutos alarma", "hora", "hora alarma", "dia de la semana", "dia del mes", "mes", "ult 2 digitos del anio", "Registro A lectura/escritura (UIP)", "Registro B lectura/escritura (interrupciones)", "Registro C solo lectura (flags)", "Registro D solo lectura (VRT) avisa error"};

	perm(PUERTO_BASE,2,1); //le doy permisos a los puertos 70(RTC) y 71
  check_uip_state();

	printf("\n");
	printf("N° Registro|\t   BCD|\t\tHexadecimal|\t\t\tDescripcion|\t\t\tN° de bits en 1|\n");

  	for (i = 0x00 ; i < CANTIDAD_REGISTROS_1; i++) {
			data[i]=in(i);
			printf(" %d\t\t",i);
			imprime_bcd(data[i]);
    			printf("%02X\t",data[i]);
			printf("%51s\t",*(descripcion+i));
			printf("%9d",cantidad_de_unos(data[i]));
			printf(" \n");
  	}
}


int cantidad_de_unos(unsigned char reg){ //cuenta la cantidad de unos
  int aux, i, x=0;
  for(i=8; i>0; i--){
    aux = reg & (0x01); // comparo el ultimo bit con un AND, devuelve 1 o 0
    if(aux!=0){
	x++;
    }
    reg>>=1; //reg=reg>>1 --> Me corro a la izquierda un bit --> ejemplo: si tengo 11001 >>1 queda 11100
  }
  return x;
}


void imprime_bcd(unsigned char reg){
	int i;
	unsigned char aux[14];

	for(i=7;i>-1;i--){
		aux[i]=reg & (0x01);
		reg >>= 1;
	}
	printf(" ");
	for(i=0; i<8; i++){
		printf("%u",aux[i]);
	}
	printf("\t");

}

//Funciones ejercicio 2
void ejercicio_2(){
int aux=0;

	printf(" ejercicio 2 \n" );

				do{
					printf("\n\nElija una opción: \n  1) Setear alarma. \n  2) Setear alarma cada minuto.\n  3) Volver al menú \n\n");
					scanf("%d", &aux);
					switch(aux){

						case 1:
							alarma_determinada_teclado();
							break;
						case 2:
							alarma_cada_minuto();
							break;
						case 3:
							printf("Volviendo al menu... \n");
							break;
						default:
							printf("Opción incorrecta. Vuelva a intentarlo. \n");
							break;
					}
				}while(aux!=3);
}

void alarma_determinada_teclado(){
	unsigned char tiempo_alarma[3];  //obs: tiempo_alarma[0]==segundos, tiempo_alarma[1]==minutos, tiempo_alarma[2]==horas
  	int i;
	int c;

	perm(PUERTO_BASE, 2, 1);
  	check_uip_state();

	
	printf("Setear la alamra-->\nInsertar horario neto de alarma en formato HH:MM:SS. \n");
	printf("OBS: la hora actual es %02x:%02x:%02x\n",in(0x04),in(0x02),in(0x00));

	//scanf ("%hhx:%hhx:%hhx", &(tiempo_alarma[0]), &(tiempo_alarma[1]), &(tiempo_alarma[2])); //guarda con scanf los valores ingresados por el usuario
	scanf ("%hhx:%hhx:%hhx", &(tiempo_alarma[0]), &(tiempo_alarma[1]), &(tiempo_alarma[2]));
	//scanf ("%hhx", &(tiempo_alarma[1]));
	//scanf ("%hhx", &(tiempo_alarma[2]));
	printf("%02x:%02x:%02x\n",tiempo_alarma[0],tiempo_alarma[1],tiempo_alarma[2]);

	out(tiempo_alarma[2], 0x01); //pone el valor asignado en seg en el registro "segundos alarma"
	out(tiempo_alarma[1], 0x03); //pone el valor asignado en min en el registro "minutos alarma"
	out(tiempo_alarma[0], 0x05); //pone el valor asignado en hora en el registro "hora alarma".

	c = in(0x0C); // lectura de registro c para borrar eventos anteriores.

	printf ("Esperando la alarma.\n");

	for (i = 0; i < 180; i++){
		c = in (0x0C);

		if (c & 0x20){ //operador de bits : AND entre el registro C y el bit  00100000 --> me va a dar TRUE unicamente si esta en 1
			printf ("Alarma!!!!!!!!\n");
		}

		usleep(500000); //son usegundos --> 500000*10^{-6} seg= 0.5 seg
	} //0.5 segundos*180 vueltas ==> 90 segundos

	perm(PUERTO_BASE,2,0); //quito los permisos
	printf("\n");
	return;

}

void alarma_cada_minuto(){

	unsigned char tiempo_alarma[3]; //obs: tiempo_alarma[0]==segundos, tiempo_alarma[1]==minutos, tiempo_alarma[2]==horas
  	int i;
	int reg_c;

	perm(PUERTO_BASE, 2, 1);
  	check_uip_state();

	tiempo_alarma[0]=0x00;
	tiempo_alarma[1]=0xFF; //los numeros entre 0x0C y 0xFF establecen un "don t care" => hace que se active la alarma cada 1 unidad
	tiempo_alarma[2]=in(0x04);

	out (tiempo_alarma[0], 0x01);
	out (tiempo_alarma[1], 0x03);
	out (tiempo_alarma[2], 0x05);

	reg_c = in (0x0C); // lectura de registro c para borrar eventos anteriores. ==> tiene el flag de alarma

	printf ("Esperando la alarma.\n");
	for (i = 0; i < 180; i++){
		reg_c = in (0x0C); //00001100

		if (reg_c & 0x20){
			printf ("Alarma!!!!!\n");
		}

		usleep(500000);
	}

	perm(PUERTO_BASE,2,0); //quito los permisos
	printf("\n");
	return;

}

/*void _setear_alarma(*unsigned char tiempo_alarma){

	out (tiempo_alarma[0], 0x01);
	out (tiempo_alarma[1], 0x03);
	out (tiempo_alarma[2], 0x05);
	c = in (0x0C);
	printf ("Esperando la alarma.\n");
	for (i = 0; i < 180; i++){
		c = in (0x0C);

		if (c & 0x20){
			printf ("Alarma!!!!!!!!\n");
		}

		usleep(500000);
	}

	perm(PUERTO_BASE,2,0); //quito los permisos
	printf("\n");
	return;


}
*/

//Funciones ejercicio 3

void ejercicio_3(){
	unsigned char reg_a, reg_b, reg_c;
	int i;

	printf("\n");

	perm(PUERTO_BASE,2,1);
	check_uip_state();


	reg_a = in(0x0A); //leo el registro 0A (0001010) --> el registro a
	reg_a = reg_a | (MASCARA_FRECUENCIA_SQW); //aplico una máscara para setear la frecuencia
	//se ingresa en hexa (el valor se va a usar de mascar con el registro A) segun tabla del datasheet --> 1111 => 2Hz

	out(reg_a,0x0A); //Seteo el registro A con la frecuencia a 2Hz.(setea velocidad clock)


	reg_b = in(0x0B);//leo el registro 0B(0001011)
	reg_b = reg_b | (0x40);// modifico el b para activar el PIE (periodic interrupt enable) que me habilita las interrupciones periodicas --> b|0100000
	out(reg_b,0x0B);//Seteo el registro A con el PIE activado

	printf("\n\n");
	for(i=0;i<10;i++){
		printf("%d",i);
		printf("------|------");
	}
	printf("10\n");
	/*printf("0-------+-------1-------+-------2-------+-------3-------+-------4-------+-------5-------+-------6-------+-------7-------+-------8-------+-------9-------+-------10\n");*/

	fflush(stdout); //limpia el buffer (imprime por pantalla lo que tiene stdout)

	check_uip_state();
	reg_c = in(0x0C); //Leo el registro, ya que al leerlo borra el FLAG

	for(i=0;i<80;i++){ //como tengo la escala de 10, al usar octavos de segundo, se divide en 80 partes.
		
		if(reg_c & 0x40){  //checkeo el bit PF (periodic flag) si está en 1 indica que es necesario que se produzca la interrupción
			printf( CARACTER_PULSO);
		}
		else{
			printf(CARACTER_DELAY); //cuando esté en 0
		}
		usleep(125000); //Espero 1/8 de segundo por cada 4 da 1/2 segundo, 1/2 segundo = 2Hz.
		reg_c = in(0x0C); //limpio el registro
		fflush(stdout);//Limpio el buffer antes de arrancar el nuevo ciclo
	}
	perm(PUERTO_BASE,2,0); //quito los permisos.
	printf("\n");
	return;
}

//Funciones ejercicio 4

void ejercicio_4(){
	unsigned char dato_transmitido;
	unsigned char tiempo_alarma[3]; //obs: tiempo_alarma[0]==segundos, tiempo_alarma[1]==minutos, tiempo_alarma[2]==horas

	perm(PUERTO_BASE, 2, 1);
  	check_uip_state();

	tiempo_alarma[0]=in(0x00);//seg
	tiempo_alarma[1]=in(0x02);//min
	tiempo_alarma[2]=in(0x04);//h


	printf("La hora actual es %02X:%02X:%02X\n",tiempo_alarma[2],tiempo_alarma[1],tiempo_alarma[0]);

	imprime_bcd(tiempo_alarma[1]);//bcd de los minutos
	printf("\n");

	dato_transmitido= ~(tiempo_alarma[1]); //el valor que se va a transmitir --> con el ~ se lo niega

	printf("Dato a transmitir(negado para compensar que llega negado a la impresora): ");
	imprime_bcd(dato_transmitido);
	printf("\n");

	perm(PUERTO_BASE, 2, 0); //quito los permisos a los ports 70 y 71.


	perm(PUERTO_IMPRESORA ,3 ,1); //Permiso a ports de la impresora

	outb(dato_transmitido, PUERTO_IMPRESORA); //Envio el dato negado por el registro de datos
	outb(0x00, PUERTO_PARALELO_CONTROL); // pongo en 0 el registro de control.
	usleep(DELAY_STROBE); //
	outb(0x01, PUERTO_PARALELO_CONTROL); // Lo vuelvo a poner en 1 el registro de control

	perm(PUERTO_IMPRESORA, 3, 0); //Quito los permisos de la impresora.

	return;
}
