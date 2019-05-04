#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum{OK, 
	     ERROR_ARGS_AMOUNT,
	     ERROR_INVALID_SPECIFIERS,
	     ERROR_INVALID_FORMAT,
	     ERROR_OPEN_FILE,
	     ERROR_PRODUCT_NOT_FOUND,
	     ERROR_NULL_POINTER, 
	     ERROR_INVALID_ID,
	     ERROR_INVALID_DESCRIPTION,
	     ERROR_INVALID_PRICE, 
	     ERROR_NO_MEMORY,
	     ERROR_SORT,
	     ERROR_CLOSE_FILE
	    } status_t;

typedef enum{FORMAT_HTML,
	     FORMAT_XML
	    } format_t;

typedef enum{TRUE,
	     FALSE
	    } bool_t;

typedef int (*comparator_t)(const void *, const void *);

typedef status_t (*header_printer_t)(FILE * ); 

typedef status_t (*product_printer_t)(FILE * , void * s, size_t);

typedef status_t (*closer_printer_t)(FILE * );


#endif
