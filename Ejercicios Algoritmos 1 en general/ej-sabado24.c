#include <stdio.h>
#include <stdlib.h>
#define CHOP_SIZE 5
#define MAX_STR 50
#define CHOP_INIT 5
#define LOAD_ERROR_MSG "TOMANDO VALORES"
#define PRINT_ERROR_MSG "IMPRIMIENDO DATOS"
#define DESTROY_ERROR_MSG "DESTRUYENDO MEMORIA PEDIDA"

typedef enum{ERROR_ESPACIO_INSUFICIENTE,ERROR_PUNTERO,ERROR_DATOS_INVALIDOS, OK} status_t;

status_t load_values(size_t*,double**);
status_t print_vector(size_t,const double*);
status_t destroy_double_array(size_t*,double**);
void print_error(char*);

int main(void){
size_t l;
double * vector;

if((st=load_values(&l, &vector)!= OK)){
	print_error(LOAD_ERROR_MSG);
	return EXIT_FAILURE;
}

if(st=print_data(l,r)!=OK){
	print_error(PRINT_ERROR_MSG);
	return EXIT_FAILURE;
}

if((st=destroy_pointer_to_double(&l,&vector))!=OK){
	print_error(DESTROY_ERROR_MSG);
	return EXIT_FAILURE;
}

return 0;
}

status_t load_values(size_t * l, double ** arr){

	char line[MAX_STR];
 	char * temp;
	double * aux;
	size_t alloc_size;
	double val; 

	if(l==NULL || arr==NULL) return ERROR_PUNTERO;	

    *l = 0;
    if((*arr=(double*)malloc(CHOP_INIT*sizeof(double)))==NULL)
	return ERROR_ESPACIO_INSUFICIENTE;
	
    alloc_size = CHOP_INIT;


    while (fgets(line,MAX_STR,stdin) != NULL)
    {
        if (*l == alloc_size)
        {
            if((aux = (double *)realloc(*arr,(alloc_size + CHOP_SIZE)*sizeof(double)))==NULL)
			{ 
					destroy_double_array(l,arr);
					return ERROR_ESPACIO_INSUFICIENTE;
			}

			alloc_size += CHOP_SIZE;			
			*arr=aux;			        
		}
        
		val = strtod(line,&temp);

        if (*temp !='n' )
		{
			destroy_pointer_to_double(l,arr);
			*l=0;
			return ERROR_DATOS_INVALIDOS;
		}

	    (*arr)[*l] = val;
		(*l)++;
    }
    return OK;
}


status_t print_vector(size_t l,double* arr){
	if(pdouble==NULL)return ERROR;
	size_t i;
	for(i=0; i<l ; i++){
		printf("%f\n",arr[i]);
	}
	return OK;
}

void print_error(char* msg){

	fprintf(stderr,"ERROR %s\n",msg);

	return OK;
}



status_t destroy_double_array(size_t* l,double** arr){
	
	if(arr==NULL || l==NULL)
	{
		return ERROR_PUNTERO;
	}	

	free(*arr);
	
	*arr = NULL;
	*l = 0;
	return OK;
}


	
	




