#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "product.h"
#include "vector.h"
#include "type.h"
#include "setting.h"
#include "util.h"
#include "html.h"
#include "xml.h"

#define MAX_LINE 200
#define MAX_DATA 200
#define LF '\n'
#define NUL '\0'
#define CATALOG_DELIMITER '|'
#define ITEM_DELIMITER ','

/* Prototipos */
status_t process_inventory(FILE *, FILE *, FILE *);
status_t process_catalog(FILE *, ADT_Product_t *, ADT_vector_t **);
status_t process_item(FILE *, FILE *, ADT_vector_t *);

status_t line_2_ADT_Product(char [], ADT_vector_t *, size_t);
status_t str_2_ADT_Product_id(char[], ADT_Product_t *);
status_t str_2_ADT_Product_description(char[], ADT_Product_t *);
status_t str_2_ADT_Product_price(char[], ADT_Product_t *);
status_t create_ADT_Product(ADT_vector_t *);

#endif
