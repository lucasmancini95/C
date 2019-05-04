#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Macros*/
#define MAX_STR 50
#define INIT_CHOP 20
#define GROWTH_FACTOR 2
#define DELIMITTER '|'
#define POS_REAL 0
#define POS_IMAG 1

/*Tipos enumerativos*/
typedef enum{OK, ERROR_NULL_POINTER, ERROR_NO_MEMORY, ERROR_INVALID_DATA} status_t;
typedef struct{double real; double imag;} complex_t;

/*Prototipos*/
status_t load_values(complex_t **, size_t *, const char);

status_t strtocomplex (const char *, complex_t *, const char);

status_t destroy_complex_t_array(complex_t **, size_t *);

void print_complex_t_array(const complex_t *, size_t);

/*Programa principal*/
int main(void){
    complex_t * pcomplex;
    size_t len;
    char delimitter = DELIMITTER;
    
    if(load_values(&pcomplex, &len, delimitter)!=OK){
     /*AcÃ¡ habÃ­a un destroy_complex_t pero lo saquÃ© porque estarÃ­a liberando dos veces la memoria*/
	fprintf(stderr,"ERROR1");	        
		return EXIT_FAILURE;
    }
	/*printf("%f\n",pcomplex->real);
	printf("%f\n",pcomplex[1].real); estos dan 0.00000 siempre
	printf("%f\n",pcomplex[1].imag); estos dan 0.00000 siempre*/
    print_complex_t_array(pcomplex, len);
    if(destroy_complex_t_array(&pcomplex, &len)!=OK) return EXIT_FAILURE;
    return EXIT_SUCCESS;

}

status_t load_values(complex_t** parr, size_t * used_size, char delimitter){
    size_t alloc_size;
    char string[MAX_STR];
    complex_t * aux;

    if(parr==NULL || used_size==NULL) return ERROR_NULL_POINTER;

    if((*parr=(complex_t *)malloc(sizeof(complex_t)*INIT_CHOP))==NULL) return ERROR_NO_MEMORY;

    alloc_size=INIT_CHOP;
    *used_size=0;
    while(fgets(string, MAX_STR, stdin)!=NULL){
        if(*used_size==alloc_size){
            if((aux=(complex_t *)realloc(*parr, sizeof(complex_t)*(alloc_size+GROWTH_FACTOR)))==NULL){
                destroy_complex_t_array(parr, used_size); 
                return ERROR_NO_MEMORY;
            }
            *parr=aux;
            alloc_size+=GROWTH_FACTOR;
        }
        if(strtocomplex(string,&((*parr)[*used_size]), delimitter)!=OK){
		    destroy_complex_t_array(parr, used_size);
            return ERROR_INVALID_DATA;
        }
    }
    return OK;
}

/*Funcion que convierte una cadena en un complex_t
ñññññññññññññññññññññññññññññññ
    Ya me pasan la estructura pedida, esta fx NO pide memoria */
status_t strtocomplex (const char * string, complex_t * pcomp, char delimitter){

    char * end;
    char ret[MAX_STR];
	size_t i=0;
   
    if(string==NULL || pcomp==NULL)
        return ERROR_NULL_POINTER;


while(string[i]!=delimitter){i++;}

strcpy(ret, &(string[i+1]));

     pcomp->real = strtod(string,&end); /*o bien arr->real, pero el tema es que NO es un ARReglo ññññññññññ, nombre*/
    /*if(*end && *end!='\n')
        return ERROR_INVALID_DATA;*/
	pcomp->imag = strtod(ret,&end);
   /* if(*end!=0 && *end!='\n')
        return ERROR_INVALID_DATA;*/
        
    return OK;
}


/*Funcion que destruye el arreglo de complejos*/
status_t destroy_complex_t_array(complex_t ** ppcomp, size_t * len){
    if(ppcomp==NULL)
        return ERROR_NULL_POINTER;
    free(*ppcomp);
    *ppcomp=NULL;
    *len=0;
    return OK;
}

/*Funcion que imprime el arreglo*/
void print_complex_t_array(const complex_t * pcomp, size_t len){
      size_t i;
        if(pcomp==NULL)
    for(i=0; i<len; i++){
        printf("%f\b%f\n", (pcomp[i]).real, (pcomp[i]).imag);
    }
}


