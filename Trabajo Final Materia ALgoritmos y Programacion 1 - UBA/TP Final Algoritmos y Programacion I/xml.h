#ifndef XML_H
#define XML_H

#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "type.h"

#define PRODUCTS_OPEN "<products>\n"
#define PRODUCTS_CLOSE "</products>\n"
#define PRODUCT_OPEN "\t<product>\n"
#define PRODUCT_CLOSE "\t</product>\n"
#define ID_XML_OPEN "\t\t<id>"
#define ID_XML_CLOSE "</id>\n"
#define DESC_XML_OPEN "\t\t<description>"
#define DESC_XML_CLOSE "</description>\n"
#define PRICE_XML_OPEN "\t\t<price>"
#define PRICE_XML_CLOSE "</price>\n"

#define MAX_DESCRIP 100

status_t print_products_open (FILE *);
status_t print_xml_object_info (FILE *, void *, size_t);
status_t print_products_close (FILE *);



#endif
