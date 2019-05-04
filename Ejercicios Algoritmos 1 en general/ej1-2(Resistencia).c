# include <stdio.h>

int opcion, cantidad;
float resistencia_total=0;
float valor;
main(void){
printf("Ingrese opcion\n 1-> ingresar valor 2-> resitencia total\n");
scanf("%d",&opcion);
while(opcion==1){
	printf("Selecciono la opcion 1\n Porfavor ingrese el valor de la resistencia en ohmios deseada seguida por la cantidad de unidades\n");
	scanf("%f",&valor);
	scanf("%d",&cantidad);
	resistencia_total= resistencia_total +  valor * cantidad;
	printf("Ingrese opcion\n 1-> ingresar otro valor 2-> resitencia total\n");
	scanf("%d",&opcion);
}
if(opcion==2){
	printf("Valor Resistencia Total %f\n",resistencia_total);
}
}
