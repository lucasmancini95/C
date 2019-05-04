#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 20
#define CHOP_SIZE 2
#define INIT_CHOP 3
typedef enum{OK,ERROR}status_t;

status_t load_values(FILE*,double ***,size_t *);
status_t destroy_parrpd(double ***,size_t *);

int main(void){
FILE* fi;
double** parrpd;
size_t l, i;

if((fi=fopen("hola.txt","rt"))==NULL) return EXIT_FAILURE;

if(load_values(fi,&parrpd,&l)!= OK){
	fprintf(stderr,"ERROR");
	return EXIT_FAILURE;
}

for(i=0;i<l;i++){

printf("%f\n",*((parrpd)[i]));

}
destroy_parrpd(&parrpd,&l);

if(fclose(fi)==EOF) return EXIT_FAILURE;

return EXIT_SUCCESS;
}



status_t load_values(FILE* fi,double *** pparrpd,size_t* pl){
char str[MAX_STR];
size_t i, j, alloc_size;
char* temp;
double** aux;
double* aux2;

if(fi==NULL || pparrpd==NULL || pl==NULL) return ERROR;

if( (*pparrpd=(double**)malloc(sizeof(double**)*INIT_CHOP))==NULL) return ERROR;

alloc_size=INIT_CHOP;
*pl=0;

for(i=0;i<alloc_size;i++){ /*creo el espacio para los double y dejo sus direcciones en los punteros del arreglo*/
	if((aux2=(double*)malloc(sizeof(double)))==NULL){
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

		if( (aux=(double**)realloc(*pparrpd,sizeof(double**)*(alloc_size+CHOP_SIZE))) ==NULL){ 
				for(j=0;j<alloc_size;j++){free((*pparrpd)[i]);}
 				free(*pparrpd); *pl=0; return ERROR;
				}

		*pparrpd=aux;

		for(i=alloc_size;i<(alloc_size+CHOP_SIZE);i++){ /*creo el espacio para los double y dejo sus direcciones en los punteros del arreglo*/
			if( (aux2=(double*) realloc((*pparrpd)[i] , sizeof(double))) ==NULL){
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

 	*((*pparrpd)[*pl])=strtod(str,&temp);
	(*pl)++;
}

return OK;
}

status_t destroy_parrpd(double ***pparrpd,size_t *pl){
size_t i;
for(i=0;i<*pl;i++){
 	free((*pparrpd)[i]);/*si da error libero hasta donde se habia llegado*/
}

free(*pparrpd);
*pl=0;
return OK;
}



