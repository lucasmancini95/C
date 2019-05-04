#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654
#define MAX_VALOR_RESISTENCIA  150000000
#define MAX_VALOR_CAPACITOR 0.00001
#define MAX_STR 100
#define MENSAJE_MENU_PRINCIPAL "Seleccione el MENU\nMenu Frecuencia--> 0\nMenu Calidad-->1\nSalir--> 2\n"
#define MENSAJE_REINICIAR "Presione la letra \"r\" si desea reiniciar o cualquier letra para terminar el programa\n"
#define MENSAJE_MENU_FRECUENCIA "Seleccione la opcion correspondiente:\nR1-->0\nR2-->1\nR3-->2\nF0-->3\nC-->4\nLuego ingrese en el orden R1,R2,R3,F0,C saltenado el que desea conocer\n"
#define MENSAJE_MENU_CALIDAD "Seleccione la opcion correspondiente:\nR1-->0\nR2-->1\nR3-->2\nQ-->3\nLuego ingrese en el orden R1,R2,R3,Q saltenado el que desea conocer\n"
#define MSG_FINALIZACION "Eligio la opcion de salir\n"

typedef enum{R1=0,R2=1,R3=2,F0=3,C=4}opc_calc_frec_t;
typedef enum{R1q=0,R2q=1,R3q=2,Q=3}opc_calc_calidad_t;
typedef enum{Fecuencia=0, Calidad=1, Salir=2}opc_menu_t;
typedef enum{ERROR,OK}status_t;
typedef enum{TRUE,FALSE}boole_t;
/*PROTOTIPOS*/
status_t leer_valor(float*);
status_t leer_opcion_menu_principal(opc_menu_t*);
status_t leer_opcion_menu_frecuencia(opc_calc_frec_t*);
status_t leer_opcion_menu_calidad(opc_calc_calidad_t*);


status_t menu_principal(opc_menu_t);
status_t menu_frecuencia(void);
status_t menu_calidad(void);

status_t calcular_valor_R1_frequencia(float*,float*,float*,float*,float*);
status_t calcular_valor_R2a_frequencia(float*,float*,float*,float*,float*);
status_t calcular_valor_R3_frequencia(float*,float*,float*,float*,float*);
status_t calcular_valor_F(float*,float*,float*,float*,float*);
status_t calcular_valor_Capacitancia(float*,float*,float*,float*,float*);
status_t calcular_valor_Calidad (float*,float*,float*,float*);
status_t validar_R1(float);
status_t validar_R2(float);
status_t validar_R3(float);
status_t validar_C(float);
/*PROTOTIPOS*/

int main(void){

opc_menu_t opc_seleccionada_menu;
boole_t opc_salir=FALSE;
char c;


while(opc_salir!=TRUE){
opc_salir=TRUE;
printf("%s",MENSAJE_MENU_PRINCIPAL);
if(leer_opcion_menu_principal(&opc_seleccionada_menu)!=OK){fprintf(stderr,"ERROR LEYENDO OPCION MENU PRINCIPAL\n"); return EXIT_FAILURE;}
if(menu_principal(opc_seleccionada_menu)!=OK){fprintf(stderr,"ERROR MENU PRINCIPAL\n");return EXIT_FAILURE;}
printf("%s",MENSAJE_REINICIAR);
c=getchar();
if(c=='r') opc_salir=FALSE;
}
return 0;
}

status_t menu_principal(opc_menu_t opc_seleccionada_menu){

switch(opc_seleccionada_menu){

	case 0:
			if(menu_frecuencia() !=OK) return ERROR;
			break;
	case 1:
			if(menu_calidad() !=OK) return ERROR;
			break;
	
	case 2:
			printf("%s",MSG_FINALIZACION);
			break;	
	default:
			fprintf(stderr,"ERROR OPCION ELEGIDA MENU PRINCIPAL\n");
			return ERROR;
}

return OK;
}



status_t menu_frecuencia(void){
float valor_f0, valor_r1, valor_r2, valor_r3, valor_c;

printf("%s",MENSAJE_MENU_FRECUENCIA);
opc_calc_frec_t opc_seleccionada_frecuencia;

if(leer_opcion_menu_frecuencia(&opc_seleccionada_frecuencia)!=OK);

switch(opc_seleccionada_frecuencia){

	case 0:
			if(leer_valor(&valor_r2)!=OK) return ERROR;
			if(leer_valor(&valor_r3)!=OK) return ERROR;
			if(leer_valor(&valor_f0)!=OK) return ERROR;
			if(leer_valor(&valor_c)!=OK) return ERROR;
			if(calcular_valor_R1_para_frequencia(&valor_r1,&valor_r2,&valor_r3,&valor_f0,&valor_c) !=OK) return ERROR;
			printf("%f\n",valor_r1);
			break;
	case 1:
			if(leer_valor(&valor_r1)!=OK) return ERROR;
			if(leer_valor(&valor_r3)!=OK) return ERROR;
			if(leer_valor(&valor_f0)!=OK) return ERROR;
			if(leer_valor(&valor_c)!=OK) return ERROR;
			if(calcular_valor_R2_para_frequencia(&valor_r1,&valor_r2,&valor_r3,&valor_f0,&valor_c) !=OK) return ERROR;
			printf("%f\n",valor_r2);			
			break;
	
	case 2:
			if(leer_valor(&valor_r1)!=OK) return ERROR;
			if(leer_valor(&valor_r2)!=OK) return ERROR;
			if(leer_valor(&valor_f0)!=OK) return ERROR;
			if(leer_valor(&valor_c)!=OK) return ERROR;
			if(calcular_valor_R3_para_frequencia(&valor_r1,&valor_r2,&valor_r3,&valor_f0,&valor_c) !=OK) return ERROR;
			printf("%f\n",valor_r3);			
			break;

	case 3:
			if(leer_valor(&valor_r1)!=OK) return ERROR;
			if(leer_valor(&valor_r2)!=OK) return ERROR;
			if(leer_valor(&valor_r3)!=OK) return ERROR;
			if(leer_valor(&valor_c)!=OK) return ERROR;
			if(calcular_valor_F0_para_frequencia(&valor_r1,&valor_r2,&valor_r3,&valor_f0,&valor_c) !=OK) return ERROR;
			printf("%f\n",valor_f0);
			break;
	case 4:
			if(leer_valor(&valor_r1)!=OK) return ERROR;
			if(leer_valor(&valor_r2)!=OK) return ERROR;
			if(leer_valor(&valor_r3)!=OK) return ERROR;
			if(leer_valor(&valor_f0)!=OK) return ERROR;
			if(calcular_valor_C_para_frequencia(&valor_r1,&valor_r2,&valor_r3,&valor_f0,&valor_c) !=OK) return ERROR;
			printf("%f\n",valor_c);
			break;

	default:
			fprintf(stderr,"ERROR OPCION ELEGIDA MENU FRECUENCIA\n");
			return ERROR;
}

return OK;
}

status_t calcular_valor_R1_para_frequencia(float* pvalor_r1,float* pvalor_r2,float* pvalor_r3,float* pvalor_f0,float* pvalor_c){

if(pvalor_f0==NULL || pvalor_r1==NULL || pvalor_r2==NULL || pvalor_r3==NULL || pvalor_c==NULL) return ERROR;

if( (validar_R1(*pvalor_r1)!=OK) || (validar_R2(*pvalor_r2)!=OK) || (validar_R3(*pvalor_r3)!=OK) || (validar_C(*pvalor_c)!=OK) ) return ERROR;


*pvalor_r1=1/((4*PI*PI*(*pvalor_f0)*(*pvalor_f0)*(*pvalor_c)*(*pvalor_c)*(*pvalor_r2))-(*pvalor_r3));
return OK;
}

status_t calcular_valor_R2_para_frequencia(float* pvalor_r1,float* pvalor_r2,float* pvalor_r3,float* pvalor_f0,float* pvalor_c){

if(pvalor_f0==NULL || pvalor_r1==NULL || pvalor_r2==NULL || pvalor_r3==NULL || pvalor_c==NULL) return ERROR;

if( (validar_R1(*pvalor_r1)!=OK) || (validar_R2(*pvalor_r2)!=OK) || (validar_R3(*pvalor_r3)!=OK) || (validar_C(*pvalor_c)!=OK) ) return ERROR;

*pvalor_r2=(pow(sqrt(1+(*pvalor_r1)/(*pvalor_r3)),2)/(2 * PI *(*pvalor_c) * (*pvalor_f0))) / (*pvalor_r1);
return OK;
}

status_t calcular_valor_R3_para_frequencia(float* pvalor_r1,float* pvalor_r2,float* pvalor_r3,float* pvalor_f0,float* pvalor_c){

if(pvalor_f0==NULL || pvalor_r1==NULL || pvalor_r2==NULL || pvalor_r3==NULL || pvalor_c==NULL) return ERROR;

if( (validar_R1(*pvalor_r1)!=OK) || (validar_R2(*pvalor_r2)!=OK) || (validar_R3(*pvalor_r3)!=OK) || (validar_C(*pvalor_c)!=OK) ) return ERROR;

*pvalor_r3=1/((pow((*pvalor_f0) *  2 * PI * (*pvalor_c) * (sqrt((*pvalor_r1) * (*pvalor_r2))),2) -1) / (*pvalor_r1));
return OK;
}

status_t calcular_valor_F0_para_frequencia(float* pvalor_r1,float* pvalor_r2,float* pvalor_r3,float* pvalor_f0,float* pvalor_c){

if(pvalor_f0==NULL || pvalor_r1==NULL || pvalor_r2==NULL || pvalor_r3==NULL || pvalor_c==NULL) return ERROR;

if( (validar_R1(*pvalor_r1)!=OK) || (validar_R2(*pvalor_r2)!=OK) || (validar_R3(*pvalor_r3)!=OK) || (validar_C(*pvalor_c)!=OK) ) return ERROR;

*pvalor_f0=(sqrt(1+((*pvalor_r1)/(*pvalor_r3))))/(2 * PI *(*pvalor_c) * (sqrt((*pvalor_r1) * (*pvalor_r2))));
return OK;
}

status_t calcular_valor_C_para_frequencia(float* pvalor_r1,float* pvalor_r2,float* pvalor_r3,float* pvalor_f0,float* pvalor_c){

if(pvalor_f0==NULL || pvalor_r1==NULL || pvalor_r2==NULL || pvalor_r3==NULL || pvalor_c==NULL) return ERROR;

if( (validar_R1(*pvalor_r1)!=OK) || (validar_R2(*pvalor_r2)!=OK) || (validar_R3(*pvalor_r3)!=OK) || (validar_C(*pvalor_c)!=OK) ) return ERROR;

*pvalor_c =(sqrt(1+((*pvalor_r1)/(*pvalor_r3))))/(2 * PI * (*pvalor_f0) * (sqrt((*pvalor_r1) * (*pvalor_r2))));
return OK;
}

status_t menu_calidad(void){

float valor_r1, valor_r2, valor_r3, valor_q;
opc_calc_calidad_t opc_seleccionada_calidad;

printf("%s",MENSAJE_MENU_CALIDAD);


if(leer_opcion_menu_calidad(&opc_seleccionada_calidad)!=OK);

switch(opc_seleccionada_calidad){

	case 0:
			if(leer_valor(&valor_r2)!=OK) return ERROR;
			if(leer_valor(&valor_r3)!=OK) return ERROR;
			if(leer_valor(&valor_q)!=OK) return ERROR;

			if(calcular_valor_R1_para_calidad(&valor_r1,&valor_r2,&valor_r3,&valor_q) !=OK) return ERROR;
			printf("%f\n",valor_r1);
			break;
	case 1:
			if(leer_valor(&valor_r1)!=OK) return ERROR;
			if(leer_valor(&valor_r3)!=OK) return ERROR;
			if(leer_valor(&valor_q)!=OK) return ERROR;
			if(calcular_valor_R2_para_calidad(&valor_r1,&valor_r2,&valor_r3,&valor_q) !=OK) return ERROR;
			printf("%f\n",valor_r2);			
			break;
	
	case 2:
			if(leer_valor(&valor_r1)!=OK) return ERROR;
			if(leer_valor(&valor_r2)!=OK) return ERROR;
			if(leer_valor(&valor_q)!=OK) return ERROR;
			if(calcular_valor_R3_para_calidad(&valor_r1,&valor_r2,&valor_r3,&valor_q) !=OK) return ERROR;
			printf("%f\n",valor_r3);			
			break;

	case 3:
			if(leer_valor(&valor_r1)!=OK) return ERROR;
			if(leer_valor(&valor_r2)!=OK) return ERROR;
			if(leer_valor(&valor_r3)!=OK) return ERROR;

			if(calcular_valor_Q_para_calidad(&valor_r1,&valor_r2,&valor_r3,&valor_q) !=OK) return ERROR;
			printf("%f\n",valor_q);
			break;


	default:
			fprintf(stderr,"ERROR OPCION ELEGIDA MENU CALIDAD\n");
			return ERROR;
}

return OK;
}

/*FUNCIONES CALCULO CALIDAD*/

status_t calcular_valor_R1_para_calidad(float* pvalor_r1,float* pvalor_r2,float* pvalor_r3,float* pvalor_q){

if( pvalor_r1==NULL || pvalor_r2==NULL || pvalor_r3==NULL || pvalor_q==NULL) return ERROR;

if( (validar_R1(*pvalor_r1)!=OK) || (validar_R2(*pvalor_r2)!=OK) || (validar_R3(*pvalor_r3)!=OK)){ fprintf(stderr,"ERROR DATO INGRESADO\n"); return ERROR;}

*pvalor_r1=1/(((4*(*pvalor_q)*(*pvalor_q))-((*pvalor_r2)/(*pvalor_r3)))/(*pvalor_r2));
return OK;
}

status_t calcular_valor_R2_para_calidad(float* pvalor_r1,float* pvalor_r2,float* pvalor_r3,float* pvalor_q){

if( pvalor_r1==NULL || pvalor_r2==NULL || pvalor_r3==NULL || pvalor_q==NULL) return ERROR;

if( (validar_R1(*pvalor_r1)!=OK) || (validar_R2(*pvalor_r2)!=OK) || (validar_R3(*pvalor_r3)!=OK) ){fprintf(stderr,"ERROR DATO INGRESADO\n"); return ERROR;}

*pvalor_r2=((4*(*pvalor_q)*(*pvalor_q))/(1+(*pvalor_r1)/(*pvalor_r3)))*(*pvalor_r1);
return OK;
}

status_t calcular_valor_R3_para_calidad(float* pvalor_r1,float* pvalor_r2,float* pvalor_r3,float* pvalor_q){

if( pvalor_r1==NULL || pvalor_r2==NULL || pvalor_r3==NULL || pvalor_q==NULL) return ERROR;

if( (validar_R1(*pvalor_r1)!=OK) || (validar_R2(*pvalor_r2)!=OK) || (validar_R3(*pvalor_r3)!=OK) ){fprintf(stderr,"ERROR DATO INGRESADO\n"); return ERROR;}

*pvalor_r3=1/((4*(*pvalor_q)*(*pvalor_q)-(*pvalor_r2)/(*pvalor_r1))/(*pvalor_r2));
return OK;
}

status_t calcular_valor_Q_para_calidad(float* pvalor_r1,float* pvalor_r2,float* pvalor_r3,float* pvalor_q){

if( pvalor_r1==NULL || pvalor_r2==NULL || pvalor_r3==NULL || pvalor_q==NULL) return ERROR;

if( (validar_R1(*pvalor_r1)!=OK) || (validar_R2(*pvalor_r2)!=OK) || (validar_R3(*pvalor_r3)!=OK) ){fprintf(stderr,"ERROR DATO INGRESADO\n"); return ERROR;}

*pvalor_q = (0.5)* sqrt(((*pvalor_r2)/(*pvalor_r1))*(1+(*pvalor_r1)/(*pvalor_r3)));
return OK;
}

/*FUNCIONES VALIDAR*/

status_t validar_R1(float valor_r1){

if(0>valor_r1 || MAX_VALOR_RESISTENCIA<valor_r1)return ERROR;

return OK;
}

status_t validar_R2(float valor_r2){
if(0>valor_r2 || MAX_VALOR_RESISTENCIA<valor_r2)return ERROR;
return OK;
}

status_t validar_R3(float valor_r3){
if(0>valor_r3 || MAX_VALOR_RESISTENCIA<valor_r3)return ERROR;
return OK;
}

status_t validar_C(float valor_c){
if(0>valor_c || MAX_VALOR_CAPACITOR<valor_c)return ERROR;
return OK;
}


/*FUNCIONES LEER*/

status_t leer_valor(float* val){
char str[MAX_STR];
char * temp;

if(val==NULL) return ERROR;

if(fgets(str,MAX_STR,stdin)==NULL) return ERROR;

*val=strtod(str,&temp);

/*if(*temp!='\n')return ERROR;*/

return  OK;

}

status_t leer_opcion_menu_principal(opc_menu_t* popc_selecc){

if(popc_selecc==NULL) return ERROR;

scanf("%d",&(*popc_selecc));



return OK;
}

status_t leer_opcion_menu_frecuencia(opc_calc_frec_t* popc_selecc){

if(popc_selecc==NULL) return ERROR;

scanf("%d",&(*popc_selecc));


return OK;
}
status_t leer_opcion_menu_calidad(opc_calc_calidad_t* popc_selecc){

if(popc_selecc==NULL) return ERROR;

scanf("%d",&(*popc_selecc));

return OK;

}

