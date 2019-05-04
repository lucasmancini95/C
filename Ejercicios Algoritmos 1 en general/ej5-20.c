#include <stdio.h>
#include <string.h>
#define LENGTH 4
typedef enum{ERROR_PUNTERO_NULL, OK} status_t;
status_t string_reverse(char*);

int main(void){

char string1[LENGTH]="hola";
string_reverse(string1);
return 0;
}


status_t string_reverse(char* string1){
size_t i,j;
char string2;

if(string1 == NULL){
	fprintf(stderr, "ERROR PUNTERO NULL\n");
	return ERROR_PUNTERO_NULL;
}

j = strlen(string1)-1;
for(i=0;i<j;i++){
	  string2 = string1[i];
      string1[i] = string1[j];
      string1[j] = string2;
	j--;
}

printf("%s\n",string1);

return OK;
}

