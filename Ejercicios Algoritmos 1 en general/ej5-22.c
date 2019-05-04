#include <stdio.h>
#include <string.h>
#define LARGO 20
#define ENTRADA_CADENA stdin
char* left_trim(char*);

int main(void){
char cadena[LARGO];

fgets(cadena,LARGO,ENTRADA_CADENA);

printf("la cadena sin espcacios:\n%s\n", left_trim(cadena));

return 0;
}

char* left_trim(char* cadena){
size_t i;
while(cadena[0] == ' '){
	i=0;
	while(cadena[i]!='\0'){
		cadena[i]=cadena[i+1];
		i++;
		}	
	}
return cadena;
}
