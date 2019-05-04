#include <stdio.h>
#include <string.h>
#define LARGO 20
#define ENTRADA_CADENA stdin
int main(void){
char cadena[LARGO];
size_t i;

fgets(cadena,LARGO,ENTRADA_CADENA);

while(cadena[0] == ' '){
	i=0;
	while(cadena[i]!='\0'){
		cadena[i]=cadena[i+1];
		i++;
		}	
	}
printf("la cadena sin espcacios:\n%s\n", cadena);
return 0;
}
