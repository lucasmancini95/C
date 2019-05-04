#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 15
#define CHOP_SIZE 1
#define CHOP 1
#define INIT_CHOP 1
#define RUTA_ARCHIVO "file-ej-8-17.txt"

typedef enum{OK,ERROR}status_t;
char* read_line(FILE *);
status_t scan_dinamic_str(char** pstr);
status_t destroy_array(char** pstr);
int main(void){
FILE * f;
char* str;
char* str2;
size_t n;


if((f=fopen(RUTA_ARCHIVO,"r"))==NULL) fprintf(stderr,"ERROR ABRIENDO ARCHIVO\n");

str=read_line(f);

printf("%s\n",str);

if((fclose(f))==EOF) fprintf(stderr, "ERROR CERRANDO EL ARCHIVO\n");

if((f=fopen(RUTA_ARCHIVO,"w"))==NULL) fprintf(stderr,"ERROR ABRIENDO ARCHIVO\n");

if((destroy_array(&str))!=OK) fprintf(stderr,"ERROR PUNTERO DESTROY\n");

scan_dinamic_str(&str2);
printf("%s\n",str2);
n=strlen(str2);

if((fwrite(str2,sizeof(char),n,f))!=n) fprintf(stderr,"ERROR ESCRIIENDO\n");

if((fclose(f))==EOF) fprintf(stderr, "ERROR CERRANDO EL ARCHIVO\n");

if((destroy_array(&str2))!=OK) fprintf(stderr,"ERROR PUNTERO DESTROY\n");
return 0;
}


char* read_line(FILE * f)
{
	char* str;
	char* aux;
	size_t l, alloc_size;
	
	if(f==NULL)fprintf(stderr,"ERROR,PUNTERO NULL\n");
	
	str=(char*)malloc((sizeof(char))*INIT_CHOP);
	l=0;
	alloc_size=INIT_CHOP;
	
	while((fgets(str,MAX_STR,f))!=NULL)
	{

	if(l==alloc_size)
	{
		if((aux=(char*)realloc(str,(sizeof(char))*(alloc_size+CHOP_SIZE)))==NULL)
		{
			free(str);
			fprintf(stderr,"ERROR REALLOC\n");
		}
		
		str=aux;
		alloc_size = alloc_size + CHOP_SIZE;
	}

l++;
}

return str;
}
		
status_t scan_dinamic_str(char** pstr)
{
	size_t alloc_size, l;
	char** aux;
	

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
			alloc_size= alloc_size + CHOP;
		}
	l++;		
	}
	return  OK;
	
}

status_t destroy_array(char** pstr){

	if(pstr==NULL) return ERROR;

	free(*pstr);
	return OK;
}

	

