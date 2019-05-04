#include <stdio.h>
#include <stdlib.h>
#define LARGO 10

int main(void){
float vector[LARGO];
float suma_total=0;
float promedio;
size_t cantidad, i;


printf("ingrese la cantidad de numeros que va a querer promediar\n");
scanf("%d",&cantidad);

for(i=0;i<cantidad;i++){	/*ingresar caracteres a un array*/
	printf("ingrese el valor del vector en la posicion %d\n",i+1);
	scanf("%f",&vector[i]);
}
for(i=0;i<cantidad;i++){
	suma_total=suma_total+ vector[i];
}
promedio=(suma_total)/cantidad;
printf("Promedio: %f\n",promedio);
return 0;
}
