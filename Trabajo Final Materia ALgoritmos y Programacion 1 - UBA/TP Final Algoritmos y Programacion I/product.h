#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "setting.h"

#define CMP_NUL 2
#define MAX_DATA 200
#define MAX_ID 200
#define MAX_DESCRIPTION 200

typedef struct{
		char id [MAX_ID];
		char description [MAX_DESCRIPTION];
		double price;
      	      } ADT_Product_t;

/* Prototipos */
status_t ADT_Product_new(ADT_Product_t **);
status_t ADT_Product_clone (const void *, void **);
status_t ADT_Product_destroy (void **);

/*compare*/
int ADT_Product_compare_by_id (const void *,const void *);
int ADT_Product_compare_by_description (const void *,const void *);
int ADT_Product_compare_by_price (const void *,const void *);

/*insert*/
status_t ADT_Product_set_id(ADT_Product_t *, char []);
status_t ADT_Product_set_description (ADT_Product_t *, char []);
status_t ADT_Product_set_price (ADT_Product_t *, double);
/*get*/
char * ADT_Product_get_id (ADT_Product_t *);
char * ADT_Product_get_description (ADT_Product_t *); 
double ADT_Product_get_price (ADT_Product_t);

typedef status_t (*str_2_ADT_Product_t)(char [], ADT_Product_t *);


#endif
