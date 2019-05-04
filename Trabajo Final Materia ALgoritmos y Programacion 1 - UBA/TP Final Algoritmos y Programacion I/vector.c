#include "vector.h"

/*Funcion que crea un vector */
status_t ADT_vector_new(ADT_vector_t ** p){
	if(p==NULL){
		return ERROR_NULL_POINTER;
	}
	if((*p=(ADT_vector_t *)malloc(sizeof(ADT_vector_t)))==NULL){
		return ERROR_NO_MEMORY;
	}
	(*p)->elems=NULL;
	(*p)->size=0;
	return OK;
}

/* VECTOR DELETE */

/* Funcion que borra un vector */
status_t ADT_vector_delete (ADT_vector_t **p){
	status_t st;
	size_t i;

	if(p==NULL){
		return ERROR_NULL_POINTER;
	}
	for(i=0; i<(*p)->size; i++){
		if((st=(*p)->destructor(&((*p)->elems[i])))!=OK){
			return st;
		}
	}
	free ((*p)->elems);
	(*p)->elems=NULL;
	free(*p);
	(*p)=NULL;
	return OK;
}

/* Funcion que setea el destructor */
status_t ADT_vector_set_destructor(ADT_vector_t * p, destructor_t pf){
	if(p==NULL){
		return ERROR_NULL_POINTER;
	}
	p->destructor = pf;
	return OK;
}

/* VECTOR CLONE */

/* Funcion que clona un vector */
status_t ADT_vector_clone (const ADT_vector_t *s, ADT_vector_t ** p){
	status_t st;
	size_t i;	

	if (s==NULL || p==NULL){
		return ERROR_NULL_POINTER;
	}
												
	if ((st= ADT_vector_new (p))!= OK){
		return st;
	}
												
	if (((*p)->elems= (void**) malloc ((s->size)*sizeof (void*)))==NULL){
		free (*p);
		(*p)=NULL;
		return ERROR_NO_MEMORY;
	}
												
	(*p)->size=0;
												
	for (i=0; i<(s->size); i++){
		if ((st=s->clonator(s->elems[i], &((*p)-> elems[i])))!=OK){
			ADT_vector_delete(p);
			return st;
		}
		((*p)->size)++;									
	}											
												
	return OK;
}

/* Funcion que setea el clonador */
status_t ADT_vector_set_clonator(ADT_vector_t * p, clonator_t pf){
	if(p==NULL){
		return ERROR_NULL_POINTER;
	}
	p->clonator = pf;
	return OK;
}

/* GET */
status_t ADT_vector_get_elem(ADT_vector_t v, void ** p, size_t i){
	if(p==NULL)
		return ERROR_NULL_POINTER;
	*p=v.elems[i];
	return OK;
}

status_t ADT_vector_get_size(ADT_vector_t v, size_t * l){
	if(l==NULL)
		return ERROR_NULL_POINTER;
	*l=v.size;
	return OK;
}

/* VECTOR SORT */

/* Funcion que ordena un vector */
status_t ADT_vector_bubble_sort (ADT_vector_t * v, comparator_t comparator){
	size_t i, j;
	void * aux;

	if (v==NULL){
		return ERROR_NULL_POINTER;
	}
	for (i=0; i< v->size; i++){
		for (j=0; j<(v->size)-1-i; j++){
			if (comparator(v->elems[j], v->elems[j+1])>0){
				aux=v->elems[j];
				v->elems[j]=v->elems[j+1];
				v->elems[j+1]=aux;
			}
		}
	}
	return OK;
}

/*Funcion que anexa un puntero void con una posicion del arreglo elems */
status_t ADT_vector_attach(ADT_vector_t * v, void * p){
	void ** aux;
	aux=NULL;

	if(v==NULL || p==NULL){
		return ERROR_NULL_POINTER;
	}
	if((aux=(void **)realloc(v->elems, sizeof(void *)*(v->size+1)))==NULL){
		return ERROR_NO_MEMORY;
	}
	v->elems=aux;
	v->elems[v->size]=p;
	v->size++;
	return OK;
}
/* VECTOR SEARCH */

/* Funcion que busca de forma lineal */
int ADT_vector_lineal_search(ADT_vector_t *v, size_t n, const void * target, comparator_t comparator){
	size_t i;

	if (v==NULL || target==NULL){
		return -1;
	}
	for(i=0; i<n; i++){
		if(comparator(v->elems[i], target)==0){
			return i;
		}
	}
	return -1;
}	

/* Funcion que busca de forma binaria */
void * ADT_vector_binary_search(ADT_vector_t *v, size_t n, void * target, comparator_t comparator){
	void * p;

	if(v==NULL || target==NULL){
		return NULL;
	}
	if(n==1){
		if(comparator(v->elems[0], target)!=0){
			return NULL;
		}
		return v->elems;
	}
	if(!n){
		return NULL;
	}
	if((p=ADT_vector_binary_search(v, n/2, target, comparator))!=NULL){
		return p;
	}
	return ADT_vector_binary_search(v+(n/2), (n)-(n/2), target, comparator);
}

