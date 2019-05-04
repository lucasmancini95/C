#include <stdio.h>
typedef float dato_t;
typedef enum{CELSIUS, FAHRENHEIT} escala_t;
#define LARGO 20

int main(void){
char unidad_original[LARGO];
int unidad_letra;
dato_t temperatura_original;
dato_t temperatura_final;
escala_t unidad_final;

	printf("ingrese la unidad(CELSIUS O FAHRENHEIT)\n");
        fgets(unidad_original,LARGO,stdin);
	unidad_letra=unidad_original[0];	

	printf("ingrese la temperatura a convertir\n");
        scanf("%f",&temperatura_original);

	
	switch(unidad_letra){
		case 'c':
			temperatura_final = (temperatura_original * (9/5)) + 32;
			unidad_final=FAHRENHEIT;
			break;
		case 'f':
			temperatura_final = (temperatura_original- 32) * 5/9;
			unidad_final=CELSIUS;
			break;
		default:
			fprintf(stderr,"ERROR DE LA UNIDAD\n");
			return 1;
			break;
}
	printf("%f %i\n",temperatura_final,unidad_final);
	return 0;
}

