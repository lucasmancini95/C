#include "product.h"

status_t ADT_Product_new(ADT_Product_t ** p){
	if(p==NULL){
		return ERROR_NULL_POINTER;
	}
	if((*p=(ADT_Product_t *)malloc(sizeof(ADT_Product_t)))==NULL){				/* no pido mas memoria porque las variables dentro de la 													estructura son estaticas */
		return ERROR_NO_MEMORY;
	}
	return OK;
}

status_t ADT_Product_clone (const void * s, void ** p){
	ADT_Product_t * p1=(ADT_Product_t *)s;
	ADT_Product_t ** p2=(ADT_Product_t **) p;
	if(s==NULL ){
		return ERROR_NULL_POINTER;
	}
	if((*p2= (ADT_Product_t*) malloc(sizeof(ADT_Product_t)*(sizeof(*p1))))==NULL){
		return ERROR_NO_MEMORY;
	}
	*p2=p1;
	return OK;
}

/*Funcion que destruye un producto */
status_t ADT_Product_destroy (void ** s){
	ADT_Product_t ** p=(ADT_Product_t **)s;

	if(s==NULL){
		return ERROR_NULL_POINTER;
	}
	free (*p);
	(*p)=NULL;
	return OK;
}

/* Funcion que inserta un id en un producto */
status_t ADT_Product_set_id (ADT_Product_t * p, char i[]){
	if(p==NULL || i==NULL){
		return ERROR_NULL_POINTER;
	}
	strcpy(p->id, i);
	return OK;
}

/* Funcion que inserta una descripcion en un producto */
status_t ADT_Product_set_description (ADT_Product_t * p, char d[]){
	if(p==NULL || d==NULL){
		return ERROR_NULL_POINTER;
	}
	strcpy(p->description, d);
	return OK;
}

/* Funcion que inserta un precio en un producto */
status_t ADT_Product_set_price (ADT_Product_t * p, double pr){
	if(p==NULL){
		return ERROR_NULL_POINTER;
	}
	p->price=pr;
	return OK;
}

/* Funcion que obtiene el id de un producto */
char * ADT_Product_get_id (ADT_Product_t * p){
	if(p==NULL)
		return NULL;
	return p->id;
}

/* Funcion que obtiene la descripcion de un producto */
char * ADT_Product_get_description (ADT_Product_t * p){
	if(p==NULL)
		return NULL;
	return p->description;
}

/* Funcion que obtiene el precio de un producto */
double ADT_Product_get_price (ADT_Product_t p){
	return p.price;
}

/* Funcion que compara dos productos segun el id */
int ADT_Product_compare_by_id (const void * s1, const void * s2){
	ADT_Product_t * p1=(ADT_Product_t *)s1;
	ADT_Product_t *p2=(ADT_Product_t *)s2;
	
	return strcmp(p1->id, p2->id);
}

/* Funcion que compara dos productos segun la descripcion */
int ADT_Product_compare_by_description (const void * s1, const void * s2){
	ADT_Product_t * p1=(ADT_Product_t *)s1;
	ADT_Product_t *p2=(ADT_Product_t *)s2;
	
	if(s1==NULL || s2==NULL){
		return CMP_NUL;
	}
	return strcmp(p1->description, p2->description);
}

/* Funcion que compara dos productos segun el precio */
int ADT_Product_compare_by_price (const void * s1, const void * s2){
	ADT_Product_t * p1=(ADT_Product_t *)s1;
	ADT_Product_t *p2=(ADT_Product_t *)s2;
	int c;
	
	if(s1==NULL || s2==NULL){
		return CMP_NUL;
	}
	if(p1->price>p2->price){
		c=1;
	}
	if(p1->price==p2->price){
		c=0;
	}
	if(p1->price<p2->price){
		c=-1;
	}
	return c;
}



