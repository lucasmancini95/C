#include <stdio.h>
#include <math.h>
#define LARGO 5

double calculo_desvio(double*,int);
double calculo_promedio(double*,int);

int main(void){

double arreglo[LARGO]={1.2,2,3,4,5.5};
size_t largo;
double desvio;

largo=LARGO;

desvio=calculo_desvio(arreglo,largo);

printf("%f\n",desvio);

return 0;
}

double calculo_desvio(double arreglo[],int largo){ /* es equivalente a double calculo_promedio(double* arreglo,int largo)*/

size_t i;
double desvio;
double promedio;

promedio=calculo_promedio(arreglo,largo);

for(i=0;i<largo;i++){
	desvio+= ((arreglo[i]-promedio)*(arreglo[i]-promedio));
}

desvio = sqrt(desvio/largo);

return desvio;
}

double calculo_promedio(double arreglo[],int largo){

size_t i;
double promedio;

for(i=0;i<largo;i++){
	promedio+= arreglo[i];
}

promedio= promedio/ largo;

return promedio;
}

