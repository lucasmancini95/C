#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_LENGTH 50

double evaluate_poli(double*,size_t,double);

int main(void){

double x,result;
double coefficient[MAX_LENGTH];
size_t i, grade;

printf("Ingrese el grado del polinomio que va a ingresar\n");
scanf("%u",&grade);

printf("Ingrese los coeficientes a continuacion\nNota: Ingresarlos de menor a mayor grado\n");

for(i=0;i<grade;i++){
	scanf("%lf",&coefficient[i]);
}

printf("ingrese el punto donde desea evaluar el polinomio\n");
scanf("%lf",&x);

result=evaluate_poli(coefficient,grade,x);

printf("Resultado = %lf\n", result);

return 0;
}

double evaluate_poli(double* coefficient,size_t grade,double x){

size_t i;
double poli;

for(i=0;i<(grade);i++){
	poli+=coefficient[i]*(pow(x,i+1));
}

return poli;
}
 

