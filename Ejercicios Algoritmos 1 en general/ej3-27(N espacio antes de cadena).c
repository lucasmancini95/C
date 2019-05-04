#include <stdio.h>
#include <string.h>
#define LARGO 20
#define ENTRADA_CADENA stdin
int main(void){
char cadena[LARGO];
size_t i,a,b,N;

printf("ingrese una cadena\n");
fgets(cadena,LARGO,ENTRADA_CADENA);

printf("ingrese la cantidad de espacios que desea correr hacia la derecha(max 20) \n");
scanf("%d",&N);

for(i=0; i<N; i++){
	a=strlen(cadena);
	b=a+1;
	while(b!=0){
		cadena[b]=cadena[a];
		a--;
		b--;
		}
	cadena[i]=' ';
}

printf("%s",cadena);
return 0;
}
