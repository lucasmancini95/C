#include "xml.h"

status_t print_products_open (FILE * fo){
	if (fo==NULL){
		return ERROR_NULL_POINTER;
	}
	fputs (PRODUCTS_OPEN, fo);
	return OK;
}

status_t print_products_close (FILE * fo){
	if (fo==NULL){
		return ERROR_NULL_POINTER;
	}
	fputs (PRODUCTS_CLOSE, fo);
	return OK;
}

status_t print_xml_object_info (FILE * fo, void * p, size_t c){
	ADT_Product_t * product=(ADT_Product_t *)p;
	if (fo==NULL || p==NULL){
		return ERROR_NULL_POINTER;
	}

	fputs (PRODUCT_OPEN, fo);
	
	fputs (ID_XML_OPEN, fo);
	fprintf (fo, "%s", ADT_Product_get_id(product));
	fputs (ID_XML_CLOSE, fo);

	if(ADT_Product_get_description(product)==NULL)
		return ERROR_NULL_POINTER;
	fputs (DESC_XML_OPEN, fo);
	fputs (ADT_Product_get_description(product), fo);
	fputs (DESC_XML_CLOSE, fo);

	fputs (PRICE_XML_OPEN, fo);
	fprintf (fo, "%f", ADT_Product_get_price(*product));
	fputs (PRICE_XML_CLOSE,fo);

	fputs (PRODUCT_CLOSE, fo);
	return OK;
}

	
