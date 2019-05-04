#include <string.h>
#include <stdio.h>
#define LARGO_MAXIMO 50

int main(){

char str[LARGO_MAXIMO];
size_t longitud;


printf("Porfavor ingrese una cadena de caracteres\n");
fgets(str,LARGO_MAXIMO,stdin);

	longitud = strlen(str);
	if((longitud==0)){
	puts("la cadena esta vacia\n");
	}
	else{
	printf("la cadena: %s contine %d caracteres (incluyendo el caracter nulo)\n",str,longitud);
}
return 0;
}
