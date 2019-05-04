#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 20
#define CHOP_SIZE 2
#define INIT_CHOP 3
#define RUTA "hola2.txt"
#define DELIMITTER '|'

typedef enum{OK,ERROR}status_t;
typedef struct{double real; double img;}complex_t;

status_t load_values(FILE*,complex_t ***,size_t *);
status_t destroy_parrpd(complex_t ***,size_t *);
double strtocomplexreal(char*);
double strtocompleximg(char*);

int main(void){
FILE* fi;
complex_t** parrpd;
size_t l, i;

if((fi=fopen(RUTA,"rt"))==NULL) return EXIT_FAILURE;

if(load_values(fi,&parrpd,&l)!= OK){
	fprintf(stderr,"ERROR");
	return EXIT_FAILURE;
}

for(i=0;i<l;i++){

printf("%f+ix%f\n",(*((parrpd)[i])).real,(*((parrpd)[i])).img);

}
destroy_parrpd(&parrpd,&l);

if(fclose(fi)==EOF) return EXIT_FAILURE;

return EXIT_SUCCESS;
}



status_t load_values(FILE* fi,complex_t *** pparrpd,size_t* pl){
char str[MAX_STR];
size_t i, j, alloc_size;
complex_t** aux;
complex_t* aux2;

if(fi==NULL || pparrpd==NULL || pl==NULL) return ERROR;

if( (*pparrpd=(complex_t**)malloc(sizeof(complex_t**)*INIT_CHOP))==NULL) return ERROR;

alloc_size=INIT_CHOP;
*pl=0;

for(i=0;i<alloc_size;i++){ /*creo el espacio para los double y dejo sus direcciones en los punteros del arreglo*/
	if((aux2=(complex_t*)malloc(sizeof(complex_t)))==NULL){
		for(j=0;j<i;j++){
			 free((*pparrpd)[i]);
		}								/*si da error libero hasta donde se habia llegado*/
		free(*pparrpd);
		*pl=0; return ERROR;
		}
((*pparrpd)[i])=aux2;
}

while((fgets(str,MAX_STR,fi))!=NULL){

	if(alloc_size==(*pl)){

		if( (aux=(complex_t**)realloc(*pparrpd,sizeof(complex_t**)*(alloc_size+CHOP_SIZE))) ==NULL){ 
				for(j=0;j<alloc_size;j++){free((*pparrpd)[i]);}
 				free(*pparrpd); *pl=0; return ERROR;
				}

		*pparrpd=aux;

		for(i=alloc_size;i<(alloc_size+CHOP_SIZE);i++){ /*creo el espacio para los double y dejo sus direcciones en los punteros del arreglo*/
			if( (aux2=(complex_t*) realloc((*pparrpd)[i],sizeof(complex_t))) ==NULL){
				for(j=0;j<i;j++){
				 	free((*pparrpd)[i]);/*si da error libero hasta donde se habia llegado*/
				}
				free(*pparrpd);
				*pl=0;
				return ERROR;
				}
			(*pparrpd)[i]=aux2;
		}

		alloc_size+=CHOP_SIZE;

		}

 	(*((*pparrpd)[*pl])).real=strtocomplexreal(str);
	(*((*pparrpd)[*pl])).img=strtocompleximg(str);
	(*pl)++;
}

return OK;
}

status_t destroy_parrpd(complex_t ***pparrpd,size_t *pl){
size_t i;
for(i=0;i<*pl;i++){
 	free((*pparrpd)[i]);/*si da error libero hasta donde se habia llegado*/
}

free(*pparrpd);
*pl=0;
return OK;
}

double strtocomplexreal(char* str){
char* temp;
size_t i;
char ret[MAX_STR];

for(i=0;str[i]!=DELIMITTER;i++);

strcpy(ret, &(str[i+1]));

return strtod(str,&temp);
}

double strtocompleximg(char* str){
char* temp;
size_t i,j,k;
char ret[MAX_STR];

for(i=0;str[i]!=DELIMITTER;i++);

for(j=0;j<(i+1);j++){
	k=0;
	while(str[k]!='\0'){
		str[k]=str[k+1];
		k++;
	}
}	

return strtod(str,&temp);

}

