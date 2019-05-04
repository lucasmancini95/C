#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "macros.h"

typedef enum{ESTADO_IDLE, ESTADO_MENU_FRECUENCIA=1, ESTADO_MENU_FACTOR_CALIDAD=2, ESTADO_MENU_SALIR=0, ESTADO_MENU_FRECUENCIA_CALCULAR_FRECUENCIA=1, ESTADO_MENU_FRECUENCIA_CALCULAR_R1=2, ESTADO_MENU_FRECUENCIA_CALCULAR_R2=3, ESTADO_MENU_FRECUENCIA_CALCULAR_R3=4, ESTADO_MENU_FRECUENCIA_CALCULAR_CAPACITANCIA=5, ESTADO_MENU_VOLVER=0, ESTADO_MENU_FACTOR_CALIDAD_CALCULAR_FCALIDAD=1} menu_t;

typedef enum{ERROR, OK} status_t;

void imprimir_mensaje(const char * );
void imprimir_mensaje_error(const char * );
void imprimir_variable(double );
status_t ingresar_opcion(int * );
status_t ingresar_variable(double * );
status_t validar_resistencia(double );
status_t validar_c(double );
double calcular_frecuencia(double , double , double , double );
double calcular_resistencia_uno(double , double , double , double );
double calcular_resistencia_dos(double , double , double , double );
double calcular_resistencia_tres(double , double , double , double );
double calcular_capacitancia(double , double , double , double );
double calcular_factor_calidad(double , double , double );

int main (void){
	menu_t estado;
	estado=ESTADO_IDLE;
	double frecuencia;
	double resistencia_1;
	double resistencia_2;
	double resistencia_3;
	double capacitancia;
	double factor_calidad;

	while (estado!=MENU_SALIR){
		switch(estado){
			case ESTADO_IDLE:
				imprimir_mensaje(MENU_PRINCIPAL_MSJ);
				if(ingresar_opcion(&estado)!=OK)
					return EXIT_FAILURE;
				break;
			case ESTADO_MENU_FRECUENCIA:
				imprimir_mensaje(MENU_FUNCIONES_MSJ);	
				if(ingresar_opcion(&estado)!=OK)
					return EXIT_FAILURE;
				switch (estado){
					case ESTADO_MENU_FRECUENCIA_CALCULAR_FRECUENCIA:
						imprimir_mensaje(ENTRADA_RESISTENCIA_UNO_MSJ);
						if(ingresar_variable(&resistencia_uno)==ERROR)
							return ERROR_PUNTERO_NULO;
						imprimir_mensaje(ENTRADA_RESISTENCIA_DOS_MSJ);
						if(ingresar_variable(&resistencia_dos)==ERROR)
							return ERROR_PUNTERO_NULO;
						imprimir_mensaje(ENTRADA_RESISTENCIA_TRES_MSJ);
						if(ingresar_variable(&resistencia_tres)==ERROR)
							return ERROR_PUNTERO_NULO;
						imprimir_mensaje(ENTRADA_C_MSJ);
						if(ingresar_variable(&c)==ERROR)
							return ERROR_PUNTERO_NULO;
						if(validar_resistencia(resistencia_uno)==ERROR ||\
						validar_resistencia(resistencia_dos)==ERROR ||\
						validar_resistencia(resistencia_tres)==ERROR ||\
						validar_c(c)==ERROR){
							imprimir_mensaje_error(ERROR_VALIDACION_MSJ);
							estado=MENU_FUNCIONES;
							break;
						}
						frecuencia=calcular_frecuencia(resistencia_uno, resistencia_dos, resistencia_tres, c);
						imprimir_mensaje(SALIDA_CALC_FRECUENCIA_MSJ);
						imprimir_variable(frecuencia);
						estado=ESTADO_MENU_FRECUENCIA;		
						break;
					case ESTADO_MENU_FRECUENCIA_CALCULAR_R1:
                                		imprimir_mensaje(ENTRADA_FRECUENCIA_MSJ);
                                		if(ingresar_variable(&frecuencia)==ERROR)
							return ERROR_PUNTERO_NULO;
						imprimir_mensaje(ENTRADA_RESISTENCIA_DOS_MSJ);
                                		if(ingresar_variable(&resistencia_dos)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_TRES_MSJ);
                                		if(ingresar_variable(&resistencia_tres)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_C_MSJ);
                                		if(ingresar_variable(&c)==ERROR)
							return ERROR_PUNTERO_NULO;
						if(validar_resistencia(resistencia_dos)==ERROR ||\
						validar_resistencia(resistencia_tres)==ERROR ||\
						validar_c(c)==ERROR){
                                		        imprimir_mensaje_error(ERROR_VALIDACION_MSJ);
                                		       	estado=ESTADO_MENU_FRECUENCIA_CALCULAR_R1;
                                		        break;
						}                                		
						resistencia_uno=calcular_resistencia_uno(frecuencia, resistencia_dos, resistencia_tres, c);
                                		imprimir_mensaje(SALIDA_RESISTENCIA_UNO_MSJ);
						imprimir_variable(resistencia_uno);
                                		estado=ESTADO_MENU_FRECUENCIA;
						break;
					case MENU_CALC_RESISTENCIA_DOS:
                                		imprimir_mensaje(ENTRADA_FRECUENCIA_MSJ);
                                		if(ingresar_variable(&frecuencia)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_UNO_MSJ);
                                		if(ingresar_variable(&resistencia_uno)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_TRES_MSJ);
                                		if(ingresar_variable(&resistencia_tres)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_C_MSJ);
                                		if(ingresar_variable(&c)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		if(validar_resistencia(resistencia_uno)==ERROR ||\
						validar_resistencia(resistencia_tres)==ERROR ||\
						validar_c(c)==ERROR){
                                        		imprimir_mensaje_error(ERROR_VALIDACION_MSJ);
                                        		estado=MENU_CALC_RESISTENCIA_DOS;
                                        		break;
						}                                		
						resistencia_dos=calcular_resistencia_dos(frecuencia, resistencia_uno, resistencia_tres, c);
                                		imprimir_mensaje(SALIDA_RESISTENCIA_DOS_MSJ);
						imprimir_variable(resistencia_dos);
                                		estado=MENU_FUNCIONES;
                                		break;
					case MENU_CALC_RESISTENCIA_TRES:
                                		imprimir_mensaje(ENTRADA_FRECUENCIA_MSJ);
                                		if(ingresar_variable(&frecuencia)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_UNO_MSJ);
                                		if(ingresar_variable(&resistencia_uno)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_DOS_MSJ);
                                		if(ingresar_variable(&resistencia_dos)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_C_MSJ);
                                		if(ingresar_variable(&c)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		if(validar_resistencia(resistencia_uno)==ERROR ||\
						validar_resistencia(resistencia_dos)==ERROR ||\
						validar_c(c)==ERROR){
                                		        imprimir_mensaje_error(ERROR_VALIDACION_MSJ);
                                        		estado=MENU_CALC_RESISTENCIA_TRES;
                                        		break;
						}
                                		resistencia_tres=calcular_resistencia_tres(frecuencia, resistencia_uno, resistencia_dos, c);
                                		imprimir_mensaje(SALIDA_RESISTENCIA_TRES_MSJ);
						imprimir_variable(resistencia_tres);
                                		estado=MENU_FUNCIONES;
                                		break;
					case MENU_CALC_C:
                                		imprimir_mensaje(ENTRADA_FRECUENCIA_MSJ);
                                		if(ingresar_variable(&frecuencia)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_UNO_MSJ);
                                		if(ingresar_variable(&resistencia_uno)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_DOS_MSJ);
                                		if(ingresar_variable(&resistencia_dos)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_TRES_MSJ);
                                		if(ingresar_variable(&resistencia_tres)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		if(validar_resistencia(resistencia_uno)==ERROR ||\
						validar_resistencia(resistencia_dos)==ERROR ||\
						validar_resistencia(resistencia_tres)==ERROR){
                                		        imprimir_mensaje_error(ERROR_VALIDACION_MSJ);
                                        		estado=MENU_CALC_C;
                                        		break;
						}                                
						c=calcular_variable_c(frecuencia, resistencia_uno, resistencia_dos, resistencia_tres);
                                		imprimir_mensaje(SALIDA_VARIABLE_C_MSJ);
						imprimir_variable(c);
                                		estado=MENU_FUNCIONES;
                                		break;
					case MENU_VOLVER: 				
						estado=IDLE;
						break;
					default:
						imprimir_mensaje(ERROR_ESTADO_NO_VALIDO);
						estado=MENU_FUNCIONES;
				}
				break;
			case MENU_FACTOR_CALIDAD: 
				imprimir_mensaje(MENU_FACTOR_CALIDAD_MSJ);
                                if(ingresar_estado(&estado)==ERROR)
					return ERROR_PUNTERO_NULO;
                                break;
				switch(estado){
					case MENU_CALC_FACT_CALIDAD:
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_UNO_MSJ);
                                		if(ingresar_variable(&resistencia_uno)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_DOS_MSJ);
                                		if(ingresar_variable(&resistencia_dos)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		imprimir_mensaje(ENTRADA_RESISTENCIA_TRES_MSJ);
                                		if(ingresar_variable(&resistencia_tres)==ERROR)
							return ERROR_PUNTERO_NULO;
                                		if(validar_resistencia(resistencia_uno)==ERROR ||\
						validar_resistencia(resistencia_dos)==ERROR ||\
						validar_resistencia(resistencia_tres)==ERROR){
                               			        imprimir_mensaje(ERROR_VALIDACION_MSJ);
                                        		estado=MENU_CALC_FACT_CALIDAD;
                                        		break;
						}                                
						factor_calidad=calcular_factor_calidad(resistencia_uno, resistencia_dos, resistencia_tres);
                                		imprimir_mensaje(SALIDA_FACTOR_CALIDAD_MSJ);
						imprimir_variable(factor_calidad);
                                		estado=MENU_FACTOR_CALIDAD;
                                		break;
					case MENU_VOLVER: 				
						estado=IDLE;
						break;				
					default:
						imprimir_mensaje(ERROR_ESTADO_NO_VALIDO);
						estado=MENU_FACTOR_CALIDAD;
			}
			break;			
			case MENU_SALIR:
				return EXIT_FAILURE;
			default:
				imprimir_mensaje(ERROR_ESTADO_NO_VALIDO);
				estado=IDLE;
		}
	}
	return EXIT_SUCCESS;

}

void imprimir_mensaje(const char * mensaje){
	printf("%s\n", mensaje);
}

void imprimir_mensaje_error(const char * mensaje){
	printf("%s\n", mensaje);
}

void imprimir_variable(double  variable){
	printf("%lf\n", variable);
}


status_t ingresar_estado(int * variable){
	if(variable==NULL)
		return ERROR;	
	*variable=getchar();
	return OK;
}


status_t ingresar_variable(double * variable){
	char **end;
	char *aux;
	if(variable==NULL)
		return ERROR;
	fgets(aux, MAX_CARACTERES, stdin);
	*variable=strtod(aux, end);
	return OK;
}

status_t validar_resistencia(double res){
	if(res<MIN_RESISTENCIA || res>MAX_RESISTENCIA)
		return ERROR;
	return OK;
}

status_t validar_c(double c){
	if(c<MIN_C || c>MAX_C)
		return ERROR;
	return OK;
}

double calcular_frecuencia(double res_1, double res_2, double res_3, double c){
	double frec;
	frec=sqrt(VALOR_SUMA+(res_1/res_3))/(VALOR_MULTIPLICACION*M_PI*c*sqrt(res_1*res_2));
	return frec;
}

double calcular_resistencia_uno(double frec, double res_2, double res_3, double c){
        double res_1;
        res_1=res_2/((frec*frec*VALOR_MULTIPLICACION*VALOR_MULTIPLICACION*M_PI*M_PI*c*c)-(res_2/res_3));
        return res_1;
}

double calcular_resistencia_dos(double frec, double res_1, double res_3, double c){
        double res_2;
        res_2=(VALOR_SUMA+(res_1/res_3))/(frec*frec*VALOR_MULTIPLICACION*VALOR_MULTIPLICACION*M_PI*M_PI*c*c*res_1);
        return res_2;
}

double calcular_resistencia_tres(double frec, double res_1, double res_2, double c){
        double res_3;
        res_3=res_1/((frec*frec*VALOR_MULTIPLICACION*VALOR_MULTIPLICACION*M_PI*M_PI*c*c*res_1/res_2)-VALOR_SUMA);
        return res_3;
}

double calcular_variable_c(double frec, double res_1, double res_2, double res_3){
        double c;
        c=sqrt(VALOR_SUMA+(res_1/res_3))/(VALOR_MULTIPLICACION*M_PI*frec*sqrt(res_1*res_2));
        return c;
}

double calcular_factor_calidad(double res_1, double res_2, double res_3){
        double factor;
        factor=(sqrt((res_2*(VALOR_SUMA + (res_1/res_3)))/res_1))/VALOR_MULTIPLICACION;
        return factor;
}
