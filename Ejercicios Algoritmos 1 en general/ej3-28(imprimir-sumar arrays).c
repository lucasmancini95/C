#include <stdio.h>
#include <stdlib.h>
#define LARGO 10

int main(void){
int vector[LARGO];
int suma_total=0;
size_t i;
int impresion;

for(i=0;i<LARGO;i++){	/*ingresar caracteres a un array*/
	printf("ingrese el valor del vector en la posicion %d\n",i+1);
	scanf("%d",&vector[i]);
}
for(i=0;i<LARGO;i++){
	printf("el vector es: %d\n",vector[i]);
}
printf("Desea hacer la suma de los componentes del vector?\nPresionar 1 para si o cualquier otra letra para no\n");
scanf("%d",&impresion);
if(impresion==1){
	for(i=0;i<LARGO;i++){
		suma_total=suma_total+ vector[i];
		}
	printf("suma total: %d\n", suma_total);
	}
return 0;
}
