#include <stdio.h>

int main(void){
	int dos_vector [3] [4] = {{1,2,3,4} , {5,6,7,8} , {9,10,11,12}};
	int *dos_ptr, i;
	int (*ptr2vector)[4]; /* un arreglo de punteros */

ptr2vector=dos_vector;

dos_ptr=*ptr2vector;

for(i=0;i<12;i++){
 printf("%d\n",*(dos_ptr+i));
}

return 0;
}
