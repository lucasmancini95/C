#include <stdio.h>

int calculo_factorial(unsigned int);

int main(void){

int numero_ingresado;
int resultado;

printf("ingrese el numero al que le quiere calcular su factorial (si un numero con decimales es ingresado estos no seran tomados en cuenta)\n");

scanf("%d",&numero_ingresado);

if(numero_ingresado < 0){
	fprintf(stderr,"ERROR, NUMERO NEGATIVO INGRESADO\n");
	return 1;
}

resultado = calculo_factorial(numero_ingresado);

if(resultado==0){
	fprintf(stderr,"ERROR,el factorial de %d no puede ser calculado debido a su tamaño\n",numero_ingresado);
	return 1;
}

printf("el factorial del numero es: %d\n", resultado);

return 0;

}

int calculo_factorial(unsigned int numero_ingresado){

int i, y=1;
if(numero_ingresado!=0){
for(i=0;i<(numero_ingresado - 1); i++){
	y=y*(numero_ingresado - i);
	}
}
else{
	y=1;
}

return y;
}
