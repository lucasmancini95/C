#include <stdio.h>
#define LARGO_CADENA 50

int main(void){
char cadena[LARGO_CADENA];

printf("ingrese una cadena\n");
scanf("%s",&cadena); /*Deja un \n al terminar*/
printf("%s\n",cadena);

printf("ingrese una cadena\n");
gets(cadena); /*Tengo que poner dos porque scanf deja un \n en el buffer que es tomado por el primer gets y eso lo finaliza*/
gets(cadena); /*Es peligrosa (gcc da warning)*/
printf("%s\n",cadena);

printf("ingrese una cadena\n");
fgets(cadena,LARGO_CADENA,stdin); 
printf("%s\n",cadena);

return 0;
}




