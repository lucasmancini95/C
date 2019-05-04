#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 5

void random_array(float*,size_t);

int main(void){

float array[LENGTH];
size_t length;

length=LENGTH;

random_array(array,length);

return 0;

}

void random_array(float* array,size_t length){

size_t i;
srand(time(NULL));
for(i=0;i<length;i++){
	
	array[i]=(rand() % 101)/100;
	 
	printf("el elemento numero %d es:%f\n",i+1,array[i]);
}

}

