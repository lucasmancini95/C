#include <stdio.h>
#include <stdlib.h>

void itoa(int n);

int main(void){
int n;
scanf("%d",&n);

itoa(n);

return 0;
}

void itoa(int n){
	size_t i=2, j=1, arr_size;
	int* arr;
	
	for(arr_size=0; i>1 ;arr_size++)
	{
		i=n/j;
		j*= 10;
	}

	arr=(int*)malloc(arr_size*sizeof(int));
	j=10;
	for(i=0;i<arr_size;i++){
	arr[i]=n%j;
	n-=arr[i];
	j=j*10;
	}
	for(i=0;i<arr_size;i++){
		printf("%d\n", arr[i]);
	}

	free(arr);
}

