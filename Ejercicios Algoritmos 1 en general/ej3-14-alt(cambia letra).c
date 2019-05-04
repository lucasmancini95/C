#include <stdio.h>
#define LARGO 20
#define INGRESO_CADENA stdin
int main(void){
size_t i;
char cadena_original[LARGO];
char viejo=' ';
char nuevo;
	
	printf("ingrese la cadena de caracteres con un espacio en los lugares donde quiera el nuevo caracter\n");
		fgets(cadena_original,LARGO,INGRESO_CADENA);

	/*printf("ingrese el viejo\n");
		viejo=getchar();*/

	printf("ingrese el nuevo caracter\n");
		nuevo=getchar();


	for(i=0;i<LARGO;i++){
 		if(cadena_original[i]==viejo){
			cadena_original[i]=nuevo;
	}	
}
 	
	printf("la nueva cadena es: %s\n", cadena_original);
return 0;
}
