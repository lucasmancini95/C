#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include "type.h"

typedef status_t (*clonator_t)(const void * s, void **);

typedef status_t (*destructor_t)(void ** s);

typedef struct{
		void ** elems;
		size_t size;
		clonator_t clonator;
		destructor_t destructor;
	      } ADT_vector_t;


/*Prototipos*/
status_t ADT_vector_clone (const ADT_vector_t *, ADT_vector_t **);
status_t ADT_vector_new(ADT_vector_t ** );
status_t ADT_vector_delete (ADT_vector_t **);
status_t ADT_vector_attach(ADT_vector_t *, void *);
int ADT_vector_lineal_search(ADT_vector_t *, size_t, const void *, comparator_t);
void * ADT_vector_binary_search(ADT_vector_t *, size_t, void *, comparator_t);
status_t ADT_vector_bubble_sort (ADT_vector_t *, comparator_t);
/*set*/
status_t ADT_vector_set_destructor(ADT_vector_t * , destructor_t );
status_t ADT_vector_set_clonator(ADT_vector_t * , clonator_t );
/*get*/
status_t ADT_vector_get_elem(ADT_vector_t, void **, size_t);
status_t ADT_vector_get_size(ADT_vector_t, size_t *);




#endif
