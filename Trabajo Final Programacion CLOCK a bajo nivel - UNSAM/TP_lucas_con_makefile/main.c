/*
Alumno: Lucas Mancini
Materia: Programación.
*/

//BIBLIOTECAS NECESARIAS
#include "unistd.h"
#include "sys/io.h"
#include "sys/perm.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "ejercicios.h"
#include "RTC_utils.h"


//MACROS con Datos alumno:
#define NOMBRE_ALUMNO "Alumno:Lucas Mancini"
#define DNI "Dni:39322331"
#define MATERIA "Materia:Programacion"
#define NOMBRE_TP "------Trabajo Práctico de Programación------"

//MACROS de opciones de Menu:
#define FRASE_INICIAL "Elija una de las siguientes opciones:"
#define OPCION_1 " 1) Mostrar el contenido de los registros del 0 al 13. "
#define OPCION_2 " 2) Programar alarma."
#define OPCION_3 " 3) Tren de pulso de 2Hz por 10 segundos."
#define OPCION_4 " 4) Mostrar el campo hora por puerto paralelo y el valor que debería leer."
#define OPCION_5 " 5) Salir del programa."
#define MSG_EXIT_PROGRAMA "Saliendo del programa."
#define MSG_OPCION_INCORRECTA "Opción inválida. \nPor favor, inténtelo nuevamente."

//DECLARACIONES FUNCIONES:

void menu_inicial();

//MAIN
int main(){

	printf("\n\n%s\n\n",NOMBRE_TP);
	printf("%s %s %s \n",NOMBRE_ALUMNO, DNI, MATERIA);

	menu_inicial();

	return 0;
}


//FUNCIONES:
void menu_inicial(){
	int opcion_main_menu=1;
	do{
		printf("\n\n %s\n",FRASE_INICIAL);
		printf(" %s \n",OPCION_1);
		printf(" %s \n",OPCION_2);
		printf(" %s \n",OPCION_3);
		printf(" %s \n",OPCION_4);
		printf(" %s \n\n",OPCION_5);


		scanf("%d", &opcion_main_menu);

		switch(opcion_main_menu)
			{
			case 1:
				ejercicio_1();
				break;
			case 2:
				ejercicio_2();

				break;
			case 3:
				ejercicio_3();
				break;
			case 4:
				ejercicio_4();
				break;
			case 5:
				printf("%s \n", MSG_EXIT_PROGRAMA);
				break;
			default:
			printf("%s \n",MSG_OPCION_INCORRECTA);
			break;
			}
	 } while(opcion_main_menu!=5);

}
