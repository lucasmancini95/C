#include <stdio.h>
#include <stdlib.h>
#define N 10
int main(void){

int *arr[N]={7,8,9,5,6,75,1,88,99,10};
size_t i;
int suma_total=0;
int *puntero;

/*for(i=0;i<4;i++)
	printf("introdusca un numero\n");
	scanf("%d",&(*arr[i]));
printf("%d",*(arr[1]));*/

for(i=0;i<N;i++){
	printf("%d\n",*(&arr[i])); /* va a imprimir los numeros 7,8,9,etc en ese orden. Ya que es el dato (*) al que apunta la direccion(&) que hay en arr[i]*/ 
}

for(i=0;i<N;i++){
		puntero = *(arr[0] + i); /* puntero va a ser igual a el puntero que esta en arr[0]*/ 
		suma_total = suma_total + *puntero;
	}

printf("%d\n",suma_total);

return 0;
}



