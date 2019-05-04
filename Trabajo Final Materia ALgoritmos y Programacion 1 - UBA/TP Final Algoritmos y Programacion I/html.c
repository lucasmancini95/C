#include "html.h"

char * colores[]={ COLOR_BLUE,
		   COLOR_ORANGE
		 };

status_t print_header_open (FILE * fo){
	if (fo==NULL){
		return ERROR_NULL_POINTER;
	}
	fputs (HTML_HEADER_OPEN, fo);
	fputs (TABLE_OPEN, fo);
	return OK;
}

status_t print_header_close (FILE * fo){
	if (fo==NULL){
		return ERROR_NULL_POINTER;
	}
	fputs (TABLE_CLOSE, fo);
	fputs (HTML_HEADER_CLOSE, fo);
	return OK;
}

status_t print_html_object_info (FILE * fo, void * p, size_t c){
	ADT_Product_t * product=(ADT_Product_t *)p;
	char color[MAX_COLOR];
	strcpy(color, colores[c%(sizeof(colores)/sizeof(*colores))]);
	
	
	if (fo==NULL || p==NULL){
		return ERROR_NULL_POINTER;
	}
	fprintf(fo, "%s\"%s\"%s", OBJECT_OPEN, color, TR_CLOSE);

	if(ADT_Product_get_description(product)==NULL)
		return ERROR_NULL_POINTER;

	fputs (CELL_OPEN, fo);
	fputs (ADT_Product_get_description(product), fo);
	fputs (CELL_CLOSE, fo);

	fputs (CELL_OPEN, fo);
	fprintf (fo, "%f", ADT_Product_get_price(*product));
	fputs (CELL_CLOSE, fo);	

	if(ADT_Product_get_id(product)==NULL)
		return ERROR_NULL_POINTER;

	fputs (CELL_OPEN, fo);
	fprintf (fo, "%s", ADT_Product_get_id(product));
	fputs (CELL_CLOSE, fo);

	fputs (OBJECT_CLOSE, fo);
	return OK;
}

