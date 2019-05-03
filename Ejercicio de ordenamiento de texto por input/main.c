
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#include <string.h>
#include <ctype.h>

/*Macros*/
#define MAX_ARGS 3
#define WORD_MAX_LENGTH 100
#define MSG_ERR_ARGS_AMOUNT "Error in the amount of arguments\n obs:\n 1st argument->root to input file to proccess \n 2nd argument --> name of the output file"
#define MSG_ERR_OPEN_FILE "Error in file accesing"
#define MSG_ERR_NULL_POINTER "Error in process -> there was a null pointer"
#define MSG_ERR_CLOSE_FILE "Error in file closing"


/*Lista Dinamica, con funcion de entrada ordenada*/

struct node { //Nodo estructural de la lista
char data[WORD_MAX_LENGTH];
struct node *next;
};



void String_Lower(char string[]) ;

/*Definicion de tipo de dato para comunicacion de errores*/
typedef enum{OK, 
	     ERROR_ARGS_AMOUNT,
	     ERROR_OPEN_FILE,
	     ERROR_NULL_POINTER,
	     ERROR_CLOSE_FILE
	    } status_t;
     

/*funciones correspondientes a la lista*/
status_t insert_sorting(char*); //introduce datos en la lista de forma ordenada alfabeticamente
status_t insert_at_begin(char*);
status_t insert_at_end(char*);
status_t traverse(FILE*); //recorre la lista y imprime los datos en el archivo de salida
status_t delete_from_begin();
status_t delete_from_end();

/*funciones de manejo de datos y archivos*/
status_t validate_arguments(int, char **);
status_t validate_arg_amount(int);
status_t open_files (FILE ** ,FILE ** ,char*, char*);
status_t close_files (FILE ** p_fp, FILE ** p_salida);
status_t data_from_file_to_sorting_list(FILE* fp);

/*variables globales*/
struct node *start = NULL;
status_t status;
int string_alphabetic_order_compare(char*,char*);
int count = 0;


//MAIN
int main(int argc, char* argv[]){
	FILE *fp;
	FILE *salida;

  char  *msg_err[] = { "ok",MSG_ERR_ARGS_AMOUNT,MSG_ERR_OPEN_FILE,MSG_ERR_NULL_POINTER,MSG_ERR_CLOSE_FILE};

	if((status=validate_arguments(argc, argv))!=OK){
		fprintf(stderr, "%s \n",msg_err[status]);
		return EXIT_FAILURE;
	}
		

	if((status=open_files(&fp, &salida,argv[1],argv[2]))!=OK){
		fprintf(stderr, "%s \n",msg_err[status]);
		return EXIT_FAILURE;
	}

	

	if((status=data_from_file_to_sorting_list(fp))!=OK){
		fprintf(stderr, "%s \n",msg_err[status]);
		return EXIT_FAILURE;
	}
	if((status=traverse(salida))!=OK){
		fprintf(stderr, "%s \n",msg_err[status]);
		return EXIT_FAILURE;
	}

	if ((status=close_files (&fp, &salida))!=OK){
		fprintf(stderr, "%s \n",msg_err[status]);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}



/*FUNCIONES LISTA DINAMICA */

status_t insert_sorting(char* x) {
       struct node *new_node, *temp, *temp_aux;
       
       new_node = (struct node*)malloc(sizeof(struct node));
       count++;
       
       if (start == NULL) { // si no hay node de partida se crea
          start = new_node;
	  strcpy(start->data, x);
          start->next = NULL;
          return OK;
       }
       
		temp_aux=NULL;
       		temp = start; //si hay el temp 1 es el primero

	if((string_alphabetic_order_compare(temp->data,x))==1){
		strcpy(new_node->data,start->data);
		new_node->next=start->next;
		start->next=new_node;
		strcpy(start->data,x);
		return OK;
	}
	temp_aux=start;
	temp=start->next;

       
       while (temp->next != NULL){ 
			if((string_alphabetic_order_compare(temp->data,x))==1){

				temp_aux->next=new_node; 
				strcpy(new_node->data, x);
				new_node->next=temp;
				return OK;
			}
			temp_aux=temp;		
			temp = temp->next;  
		}
	

			   temp->next = new_node;
			   strcpy(new_node->data, x);
			   new_node->next = NULL;
				return OK;
    }


/*Funcion para comparar alfabeticamente los strings, devuelve 1 si el nuevo tiene que ir ANTES que el que ya esta*/
int string_alphabetic_order_compare(char* old, char* new){
char old_low[WORD_MAX_LENGTH];
char new_low[WORD_MAX_LENGTH];

	strcpy(old_low,old);
	strcpy(new_low,new);
	String_Lower(old_low);
	String_Lower(new_low);

	if(strcmp(new_low, old_low)<0){
		return 1;
	}

	return 0;
}

/*Funcion que pone en minuscula un string para la comparacion alfabetica*/
void String_Lower(char string[]) 
{
	int i = 0; 
	while (string[i] != '\0') 
	{
    	if (string[i] >= 'A' && string[i] <= 'Z') {
        	string[i] = string[i] + 32;
    	}
      	i++;
	}
}

/*Funcion que recorre la lista y la imprime el archivo de salida*/
status_t traverse(FILE* salida) {
       struct node *t;
	if(salida==NULL){
		return ERROR_NULL_POINTER;	
	}
       
       t = start;
       
       if (t == NULL) {
          printf("File is empty.\n");
          return OK;
       }
       
       printf("There are %d elements in the file.\n", count);
       
       while (t->next != NULL) {
         printf("%s\n", t->data);
	 fprintf(salida,"%s \n",t->data);
          t = t->next;
       }
       	printf("%s\n", t->data);
	fprintf(salida,"%s \n",t->data);
	return OK;
    }

/*Funcion que inserta nodo en el principio de la lista*/

status_t insert_at_begin(char* x) {
       struct node *t;
       
       t = (struct node*)malloc(sizeof(struct node));
       count++;
         
       if (start == NULL) {
          start = t;
 	  strcpy(start->data, x);
          start->next = NULL;
          return OK;
       }

	strcpy(t->data, x);
       t->next = start;
       start = t;
	return OK;
    }
     

/*Funcion que inserta nodo en el principio de la lista*/
status_t insert_at_end(char* x) {
       struct node *t, *temp;
       
       t = (struct node*)malloc(sizeof(struct node));
       count++;
       
       if (start == NULL) {
          start = t;
 	  strcpy(start->data, x);
          start->next = NULL;
          return OK;
       }
       
       temp = start;
       
       while (temp->next != NULL)
          temp = temp->next;  
       
       temp->next = t;
	strcpy(t->data, x);
       t->next    = NULL;
	return OK;
    }
     
     
status_t delete_from_begin() {
       struct node *t;
       char n[WORD_MAX_LENGTH];	
       
       if (start == NULL) {
          printf("Linked list is already empty.\n");
          return OK;
       }
       
	strcpy(n,start->data);
       t = start->next;
       free(start);
       start = t;
       count--;
	return OK;
    }
     
status_t delete_from_end() {
       struct node *t, *u;
       char n[WORD_MAX_LENGTH];
         
       if (start == NULL) {
          printf("Linked list is already empty.\n");
          return OK;
       }
       
       count--;
       
       if (start->next == NULL) {
          //n = start->data;
	strcpy(n,start->data);

          free(start);
          start = NULL;
          printf("%s deleted from end successfully.\n", n);
          return OK;
       }
       
       t = start;
       
       while (t->next != NULL) {
          u = t;
          t = t->next;
       }
       
       //n = t->data;
	strcpy(n,t->data);
       u->next = NULL;
       free(t);
       
       printf("%s deleted from end successfully.\n", n);
	return OK;
    }



//FUNCIONES DE PROCESO Y MANEJO DE ARCHVIOS

/*Funcion que valida la cantidad de argumentos*/
status_t validate_arg_amount(int argc){
	if (argc!= MAX_ARGS){										
	return ERROR_ARGS_AMOUNT;
	}
	return OK;
}


/* Funcion general que valida */
status_t validate_arguments(int argc, char ** argv){

	if(argv==NULL){
		return ERROR_NULL_POINTER;
	}
	if(validate_arg_amount(argc)!=OK){
		return ERROR_ARGS_AMOUNT;
	}

	return OK;
}

/* Funcion que abre los archivos  */
status_t open_files (FILE ** p_fp,FILE ** p_salida,char* argv_1,char* argv_2){
	if(p_fp==NULL){
		return ERROR_NULL_POINTER;
	}
	if(p_salida==NULL){
		return ERROR_NULL_POINTER;
	}

	if((*p_fp=fopen (argv_1, "rt"))==NULL){
		return ERROR_OPEN_FILE;
	}

	if((*p_salida=fopen (argv_2, "w+"))==NULL){
		return ERROR_OPEN_FILE;
	}
	
	

	/**fp = fopen ( argv[1], "r" );  
	*salida= fopen ( argv[2], "w+" ); */


	return OK;
} 

status_t close_files (FILE ** p_fp, FILE ** p_salida){
	if(p_fp==NULL || p_salida==NULL){
		return ERROR_NULL_POINTER;
	}
	fclose (*p_fp);
	fclose (*p_salida);
	return OK;
}

status_t data_from_file_to_sorting_list(FILE* fp){
	char buffer[WORD_MAX_LENGTH];

	if ( fp == NULL) {
		return ERROR_NULL_POINTER;
	}

	while(fscanf(fp, "%99s", buffer) == 1){ 
		insert_sorting(buffer);	
	}

return OK;
}
