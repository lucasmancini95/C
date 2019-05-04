#include <stdio.h>
#include <string.h>
#define LARGO 20
#define INGRESO_CADENA stdin
char string2[20];

int main(void){
char string[LARGO];
char viejo = ' ';
char recortado[LARGO]="";
char nuevo[LARGO];
int n, n2, largo_original=1, largo_temporal;
char *p;

printf("ingrese la cadena de caracteres con un espacio en el lugar que desea el nuevo caracter\n");	
fgets(string,LARGO,INGRESO_CADENA);

printf("ingrese el nuevo\n");
fgets(nuevo, LARGO, INGRESO_CADENA);

	
	largo_original=strlen(string);
	
	p=strchr(string, viejo);

	strcpy(string2, p);

	largo_temporal=strlen(string2);

	n= largo_original - largo_temporal;

	strncat(recortado, string,n);
	
	strcat(recortado,nuevo);

	n2 = n+1;

	strncpy(string,recortado,n2);

printf("%s\n",string);

return 0;
}




/*printf("Porfavor ingrese una cadena de caracteres\n");
fgets(string,40,stdin);
tamanooriginal=strlen(string);

printf("Porfavor ingrese un caracter que quiera remplazar\n");
viejo = getchar();

printf("Porfavor ingrese el caracter nuevo\n");
fgets(nuevoc,2,stdin);*/

