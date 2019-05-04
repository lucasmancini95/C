# include <stdio.h>
#include <math.h>
# define DIFERENCIA_SUCESIVA_MAXIMA 0.000000001
float e_previo;
float e=1;
float fact=1;
float i=0; 
int b=0;
main(void){

while(e-e_previo>=DIFERENCIA_SUCESIVA_MAXIMA){
	b++;
	fact=fact*b;
	i=i+(1/fact);
	e_previo=e;
	e=1+i;
}
printf("e=%f\n",e);
}
