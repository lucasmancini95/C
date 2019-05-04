#include <stdio.h>

int main(void){
	int dos_vector [3] [4] = {{1,2,3,4} , {5,6,7,8} , {9,10,11,12}};
	int *dos_ptr, i;
	int (*ptr2vector)[4]; /* un puntero a un arreglo de 4 enteros*/

ptr2vector=dos_vector; /*le paso la direccion de la primera fila de la matriz*/

dos_ptr=*ptr2vector; /*hago que el dos_ptr apunte al primer vector de la matriz*/

for(i=0;i<12;i++){ /
 printf("%d\n",*(dos_ptr+i)); /*dos_ptr esta apuntando a el primer vector y a medida que el i aumente va a ir apuntando al vector que sigue */
}

return 0;
}
