#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654
#define MAX_VALOR_RESISTENCIA  150000000
#define MAX_VALOR_CAPACITOR 0.00001
#define MAX_STR 100
#define MENSAJE_MENU_PRINCIPAL "Seleccione el MENU\nMenu Frecuencia--> 0\nMenu Calidad-->1\nSalir--> 2\n"
typedef enum{A=0,B=1,C=2,D=3,E=4}opc_calc_t;
typedef enum{Fecuencia=0, Calidad=1}opc_menu_t;
typedef enum{ERROR,OK}status_t;
typedef enum{TRUE,FALSE}boole_t;
/*PROTOTIPOS*/
status_t leer_valor(float*); 
status_t leer_opcion(opc_menu_t*);
float calcular_valor_R1_para_frequencia(float,float,float,float);
float calcular_valor_R2_para_frequencia(float,float,float,float);
float calcular_valor_R3_para_frequencia(float,float,float,float);
float calcular_valor_F0_para_frequencia(float,float,float,float);
float calcular_valor_C_para_frequencia(float,float,float,float);
float calcular_valor_R1_para_calidad(float,float,float);
float calcular_valor_R2_para_calidad(float,float,float);
float calcular_valor_R3_para_calidad(float,float,float);
float calcular_valor_Q_para_calidad (float,float,float);
status_t validar_R1(float);
status_t validar_R2(float);
status_t validar_R3(float);
status_t validar_C(float);
/*PROTOTIPOS*/


int main(void){

bool_t salir;
char str[MAX_LARGO];
float valor_f0, valor_r1, valor_r2, valor_r3, valor_c, valor_q;
opc_t opc_seleccionada_f, opc_seleccionada_q;
opc_menu_t opc_seleccionada_menu;
size_t largo = MAX_LARGO;



while(salir!=TRUE){

printf("%s",MENSAJE_MENU_PRINCIPAL);
status_t leer_opcion(opc_menu_t



if(opc_seleccionada_menu==0){

printf("Conociendo la formula de frecuencia:\nSeleccione la opcion correspondiente a la incognita que desea calcular\nOPCION A--> R1 (EN OHMIOS)\nOPCION B--> R2 (EN OHMIOS)\nOPCION C--> R3 (EN OHMIOS)\nOPCION D--> FO (EN HERTZ)\nOPCION E--> C (EN FARADIOS)\n");

opc_seleccionada_f=(char)my_scan(str,largo);


switch(opc_seleccionada_f){

case 'A':
	printf("Selecciono la opcion A\n");

	printf("Ingrese el valor de F0:\n");
	valor_f0=my_scan(str,largo);
	printf("Ingrese el valor de R2:\n");
	valor_r2=my_scan(str,largo);
	if(validar_R2(valor_r2) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de R3:\n");
	valor_r3=my_scan(str,largo);
	if(validar_R3(valor_r3) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de C:\n");
	valor_c=my_scan(str,largo);
	if(validar_C(valor_c) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	

	printf("El Valor de R1 es: %f\n", calc_R1(valor_f0,valor_r2,valor_r3,valor_c));
	break;

case 'B':
	printf("Selecciono la opcion B\n");

	printf("Ingrese el valor de F0:\n");
	valor_f0=my_scan(str,largo);
	printf("Ingrese el valor de R1:\n");
	valor_r1=my_scan(str,largo);
	if(validar_R1(valor_r1) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("Ingrese el valor de R3:\n");
	valor_r3=my_scan(str,largo);
	if(validar_R3(valor_r3) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de C:\n");
	valor_c=my_scan(str,largo);
	if(validar_C(valor_c) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("El Valor de R1 es: %f\n", calc_R2(valor_f0,valor_r1,valor_r3,valor_c));
	break;

case 'C':
	printf("Selecciono la opcion C\n");

	printf("Ingrese el valor de F0:\n");
	valor_f0=my_scan(str,largo);
	printf("Ingrese el valor de R2:\n");
	valor_r2=my_scan(str,largo);
	if(validar_R2(valor_r2) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de R1:\n");
	valor_r1=my_scan(str,largo);
	if(validar_R1(valor_r1) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("Ingrese el valor de C:\n");
	valor_c=my_scan(str,largo);
	if(validar_C(valor_c) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("El Valor de R1 es: %f\n", calc_R3(valor_f0,valor_r2,valor_r1,valor_c));
	break;

case 'D':
	printf("Selecciono la opcion A\n");

	printf("Ingrese el valor de R1:\n");

	valor_r1=my_scan(str,largo);
	if(validar_R1(valor_r1) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("Ingrese el valor de R2:\n");
	valor_r2=my_scan(str,largo);
	if(validar_R2(valor_r2) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de R3:\n");
	valor_r3=my_scan(str,largo);
	if(validar_R3(valor_r3) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de C:\n");
	valor_c=my_scan(str,largo);
	if(validar_C(valor_c) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("El Valor de R1 es: %f\n", calc_F0(valor_r1,valor_r2,valor_r3,valor_c));
	break;

case 'E':
	printf("Selecciono la opcion A\nIngrese el valor de: ");

	printf("Ingrese el valor de F0:\n");
	valor_f0=my_scan(str,largo);
	printf("Ingrese el valor de R2:\n");
	valor_r2=my_scan(str,largo);
	if(validar_R2(valor_r2) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de R3:\n");
	valor_r3=my_scan(str,largo);
	if(validar_R3(valor_r3) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de R1:\n");
	valor_r1=my_scan(str,largo);
	if(validar_R1(valor_r1) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("El Valor de R1 es: %f\n", calc_C(valor_f0,valor_r2,valor_r3,valor_r1));
	break;
default:
	fprintf(stderr,"ERROR OPCION ELEGIDA\n");
	break;
	}
}
if(opc_seleccionada_menu == 1){

printf("Conociendo la formula de Calidad:\nSeleccione la opcion correspondiente a la incognita que desea calcular\nOPCION A--> R1 (EN OHMIOS)\nOPCION B--> R2 (EN OHMIOS)\nOPCION C--> R3 (EN OHMIOS)\nOPCION D--> Q\n");

opc_seleccionada_q=my_scan(str,largo);

switch(opc_seleccionada_q){

case 'A':
	printf("Selecciono la opcion A\n");

	printf("Ingrese el valor de R2:\n");
	valor_r2=my_scan(str,largo);
	if(validar_R2(valor_r2) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de R3:\n");
	valor_r3=my_scan(str,largo);
	if(validar_R3(valor_r3) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de Q:\n");
	valor_q=my_scan(str,largo);

	printf("El Valor de R1 es: %f\n", calc_R1_q(valor_r2,valor_r3,valor_q));
	break;

case 'B':
	printf("Selecciono la opcion B\n");

	printf("Ingrese el valor de R1:\n");
	valor_r1=my_scan(str,largo);
	if(validar_R1(valor_r1) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("Ingrese el valor de R3:\n");
	valor_r3=my_scan(str,largo);
	if(validar_R3(valor_r3) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de Q:\n");
	valor_q=my_scan(str,largo);

	printf("El Valor de R1 es: %f\n", calc_R2_q(valor_r1,valor_r3,valor_q));
	break;

case 'C':
	printf("Selecciono la opcion C\n");

	printf("Ingrese el valor de R2:\n");
	valor_r2=my_scan(str,largo);
	if(validar_R2(valor_r2) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de R1:\n");
	valor_r1=my_scan(str,largo);
	if(validar_R1(valor_r1) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("Ingrese el valor de Q:\n");
	valor_q=my_scan(str,largo);
	printf("El Valor de R1 es: %f\n", calc_R3_q(valor_r2,valor_r1,valor_q));
	break;

case 'D':
	printf("Selecciono la opcion D\n");

	printf("Ingrese el valor de R1:\n");
	valor_r1=my_scan(str,largo);
	if(validar_R1(valor_r1) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}
	printf("Ingrese el valor de R2:\n");
	valor_r2=my_scan(str,largo);
	if(validar_R2(valor_r2) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	
	printf("Ingrese el valor de R3:\n");
	valor_r3=my_scan(str,largo);
if(validar_R3(valor_r3) == 1){
	fprintf(stderr,"ERROR, VALOR FUERA DE RANGO\n");
	return 1;
	}	

	printf("El Valor de R1 es: %f\n", calc_Q(valor_r1,valor_r2,valor_r3));
	break;

default:
	fprintf(stderr,"ERROR OPCION ELEGIDA\n");
	break;
}

}







return 0;
}


status_t leer_valor(float* val){

char * temp[MAX_STR];
double numero_double;
if(msj==NULL || val==NULL) return ERROR_PUNTERO;

if(fgets(str,MAX_STR,stdin)==NULL) return ERROR_OBTENIENDO_DATOS;

*val=strtod(str,&temp);

if(*temp!='\n')return ERROR_DATOS_INGRESADOS;

return  OK;

}

float calc_R1(float valor_f0,float valor_r2,float valor_r3,float valor_c){
float r1;
r1=1/((4*PI*PI*valor_f0*valor_f0*valor_c*valor_c*valor_r2)-valor_r3);
return r1;
}

float calc_R2(float valor_f0,float valor_r1,float valor_r3,float valor_c){
float r2;
r2=(pow(sqrt(1+valor_r1/valor_r3),2)/(2 * PI *valor_c * valor_f0)) / valor_r1;
return r2;
}

float calc_R3(float valor_f0,float valor_r2,float valor_r1,float valor_c){
float r3;
r3=1/((pow(valor_f0 *  2 * PI * valor_c * (sqrt(valor_r1 * valor_r2)),2) -1) / valor_r1);
return r3;
}

float calc_F0(float valor_r1,float valor_r2,float valor_r3,float valor_c){
float f0;
f0=(sqrt(1+(valor_r1/valor_r3)))/(2 * PI *valor_c * (sqrt(valor_r1 * valor_r2)));
return f0;
}

float calc_C(float valor_f0,float valor_r2,float valor_r3,float valor_r1){
float c;
c =(sqrt(1+(valor_r1/valor_r3)))/(2 * PI * valor_f0 * (sqrt(valor_r1 * valor_r2)));
return c;
}

size_t validar_R1(float valor_r1){
return ((0>valor_r1 || MAX_VALOR_RESISTENCIA<valor_r1)?1:0);
}

size_t validar_R2(float valor_r2){
return ((0>valor_r2 || MAX_VALOR_RESISTENCIA<valor_r2)?1:0);
}

size_t validar_R3(float valor_r3){
return ((0>valor_r3 || MAX_VALOR_RESISTENCIA<valor_r3)?1:0);
}

size_t validar_C(float valor_c){
return ((0>valor_c || MAX_VALOR_CAPACITOR<valor_c)?1:0);
}

float calc_R1_q(float valor_r2,float valor_r3,float valor_q){
float r1;
r1=1/(((4*valor_q*valor_q)-(valor_r2/valor_r3))/valor_r2);
return r1;
}

float calc_R2_q(float valor_r1,float valor_r3,float valor_q){
float r2;
r2=((4*valor_q*valor_q)/(1+valor_r1/valor_r3))*valor_r1;
return r2;
}

float calc_R3_q(float valor_r2,float valor_r1,float valor_q){
float r3;
r3=1/((4*valor_q*valor_q-valor_r2/valor_r1)/valor_r2);
return r3;
}

float calc_Q(float valor_r1,float valor_r2,float valor_r3){
float q;
q = (0.5)* sqrt((valor_r2/valor_r1)*(1+valor_r1/valor_r3));
return q;
}

