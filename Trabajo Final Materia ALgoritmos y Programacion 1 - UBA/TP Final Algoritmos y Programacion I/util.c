#include "util.h"

/* Funcion que se fija si una cadena esta vacia o no */
bool_t is_empty_string(const char str []){
	if(str[0]==NUL){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

/* Funcion que separa una cadena */
status_t split(char *** fields, char * s, char delimiter, size_t *l){
	status_t st;
	char * q;
	size_t i, n;
	char * p;
	char str[2];
	str[0]=delimiter;
	str[1]=NUL;

	if(fields==NULL || s==NULL || l==NULL){
		return ERROR_NULL_POINTER;
	}
	for(i=0, n=0; s[i]; i++){
		if(s[i]==delimiter){
			n++;
		}
	}
	n++;
	*l=0;
	if(((*fields)=(char **)malloc(n*sizeof(char*)))==NULL){
		*l=0;
		return ERROR_NO_MEMORY;
	}
	for(i=0, q=s; (p=strtok(q, str))!=NULL; i++, q=NULL){
		if((st=strdupl(p, &((*fields)[i])))!=OK){
			destroy_string_array(fields, i);
			*l=0;
			return st;
		}
	}
	*l+=i;
	return OK;
}

/* Funcion que destruye cadenas */
status_t destroy_string_array( char *** fields, size_t len){
	size_t i;

	if(fields==NULL){
		return ERROR_NULL_POINTER;
	}
	for(i=0; i<len; i++){
		free((*fields)[i]);
		(*fields)[i]=NULL;
	}
	free(*fields);
	*fields=NULL;
	return OK;
}

/* Funcion que duplica una cadena */
status_t strdupl (const char s[], char ** cs){
	if(s==NULL || cs==NULL){
		return ERROR_NULL_POINTER;
	}
	if((*cs=(char *)malloc(sizeof(char)*(strlen(s)+1)))==NULL){
		return ERROR_NULL_POINTER;
	}
	strcpy(*cs, s);
	return OK;
}

/* Funcion que lee una linea */
status_t read_file_line (FILE * f, char ** s, bool_t * eof){
	size_t alloc_size, used_size;
	int c;
	char * aux;

	if(f==NULL || s==NULL || eof==NULL){
		return ERROR_NULL_POINTER;
	}

	if((*s=malloc(sizeof(char)*INIT_CHOP))==NULL){
		return ERROR_NO_MEMORY;
	}
	alloc_size=INIT_CHOP;
	used_size=0;
	*eof=FALSE;
	while((c=fgetc(f))!=EOF && c!=LF){
		if(used_size==alloc_size-1){
			if((aux=realloc(*s, sizeof(char)*alloc_size+CHOP_SIZE))==NULL){
				free(*s);
				*s=NULL;
				return ERROR_NO_MEMORY;
			}
			alloc_size+=CHOP_SIZE;
			*s=aux;
		}
		(*s)[used_size]=c;
		used_size++;
	}
	if(c==EOF){
		*eof=TRUE;
	}
	(*s)[used_size]=NUL;
	*s=realloc(*s, used_size+1);
	return OK;
}

status_t destroy_string(char ** str){
	if(str==NULL)
		return ERROR_NULL_POINTER;
	free(*str);
	*str=NULL;
	return OK;
}
