#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 100
#define CHOP 2
#define INIT_CHOP 3
typedef enum{OK,ERROR}status_t;


status_t my_scan(char**,double*);

int main(void){
char* str;
double numero;
my_scan(&str, &numero);

printf("%f\n", numero);

return 0;
}

status_t my_scan(char** pstr,double * numero_double)
{
	size_t alloc_size, l;
	char** aux;
	char* temp;
	

	if(pstr == NULL) return ERROR;

	if((*pstr=(char*)malloc(sizeof(char)*INIT_CHOP))==NULL) return ERROR;
	alloc_size=INIT_CHOP;
	l=0;
	
	while((fgets(*pstr,MAX_STR,stdin))!=NULL)
	{
	
		if(l==alloc_size)
		{
			if((*aux=(char*)malloc(sizeof(char)*(alloc_size+CHOP))==NULL))
			{
				free(*pstr);
				return ERROR;
			}
			*pstr=*aux;
			alloc_size+=CHOP;
		}
	l++;		
	}
	
	(* numero_double) = strtod(*pstr,&temp);
	free(*pstr);
	return  OK;
	
}
