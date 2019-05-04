#include <stdio.h>
#define LARGO_MAXIMO 15

int maximo (float, int);
int minimo (float, int);
typedef enum{S=0,N=1} opc_t;

int main(void){

opc_t opcion_elegida=S;
float arreglo[LARGO_MAXIMO];
int i, largo_ingresado;
float resultado;

for(i=0;opcion_elegida==1;i++){

	printf("Desea ingresar un numero?\nsi-->S\nno-->N\n");
	scanf("%d",&opcion_elegida);
	printf("ingrese el numero porfavor:\n");
	scanf("%f",&arreglo[i]);
}
largo_ingresado=i+1;
printf("Seleccione una opcion\nmaximo-->S\nminimo-->N");
scanf("%d",&opcion_elegida);

switch(opcion_elegida){
	case 0 :
		resultado= maximo(&(arreglo[0]),largo_ingresado);
		break;
	case 1 :
		resultado=minimo(&(arreglo[0]),largo_ingresado);
		break;
	default:
		printf("ERROR DESCONOCIDO\n");
		return 1;
}

printf("el numero numero pedido es: %f\n",resultado);

return 0;
}

int maximo(float &(arreglo[0]), int largo_ingresado){

	int i;
	float maximo;

	maximo=arreglo[0];

	for(i=0;i<largo_ingresado;i++)
		if(maximo<arreglo[i]){
			maximo=arreglo[i];
	}

	return maximo;
}

int minimo(float &(arreglo[0]), int largo_ingresado){

	int i;
	float minimo;
	minimo=arreglo[0];
	for(i=0;i<largo_ingresado;i++)
        if(minimo>arreglo[i]){
                minimo=arreglo[i];
        }

return minimo;
}


