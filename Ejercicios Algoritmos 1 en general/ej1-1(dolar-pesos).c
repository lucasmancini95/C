# include <stdio.h>

int opcion;
float monto, valor, montof;
#define CAMBIO 15 /*BLUE*/
main(void)
{
 printf ("Elegir entre las dos opciones\n 1-pesos-dolares \n 2-dolares-pesos\n");
 scanf ("%d", &opcion);
 if (opcion==1){
	printf ("ingresar monto en pesos\n");
	scanf("%f",&monto);
	montof = monto / CAMBIO;
}
if (opcion==2){
	printf ("ingresar monto en dolares\n");
	scanf ("%f",&monto);
	montof = monto * CAMBIO;
}
if (opcion != 1 && opcion != 2){
	fprintf(stderr,"Error de opcion seleccionada\n");
	return 1;
}
printf ("El equivalente es %f\n", montof);
return 0;
}

