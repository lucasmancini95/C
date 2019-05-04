#include <stdio.h>
#define LARGO 5

double calculo_promedio(double*,int);

int main(void){

double arreglo[LARGO]={1.2,2,3,4,5.5};
size_t largo;
double promedio;

largo=LARGO;

promedio=calculo_promedio(arreglo,largo);

printf("%f\n",promedio);

return 0;
}

double calculo_promedio(double arreglo[],int largo){ /* es equivalente a double calculo_promedio(double* arreglo,int largo)*/

size_t i;
double promedio;

for(i=0;i<largo;i++){
	promedio+= arreglo[i];
}

promedio= promedio/ largo;

return promedio;
}


