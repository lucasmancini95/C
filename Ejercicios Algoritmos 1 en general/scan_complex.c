#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 100
#define CHOP 10
#define INIT_CHOP 5
#define DELIMITADOR_COMPLEJOS '-'
#define MSJ_INGRESO "ingrese el numero separando la parte real de la imaginaria con: la tecla\"enter\" o"
typedef enum{OK,ERROR}status_t;

typedef struct{double real; double img;}complex_t;
status_t scan_complex(char**,complex_t*);

int main(void){
char* str;
complex_t numero;

if((scan_complex(&str, &numero))!=OK) return EXIT_FAILURE;

printf("%f",numero.real);
printf("+ ix%f\n",numero.img);
return 0;
}

status_t scan_complex(char** pstr,complex_t* complex_number)
{
	size_t alloc_size, l;
	char** aux;
	char* temp;
	size_t i;

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
		
	(* complex_number).real = strtod(*pstr,&temp);
	for(i=0; i<l; i++)
	{
		(*pstr)[i]=0;
	}
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
	(* complex_number).img = strtod(*pstr,&temp);
	free(*pstr);
	return  OK;
	
}
