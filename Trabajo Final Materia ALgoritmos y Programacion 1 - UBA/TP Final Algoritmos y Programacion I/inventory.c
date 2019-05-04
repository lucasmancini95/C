#include "inventory.h"

extern setting_t setting;

extern char invalid_data[MAX_DATA];

str_2_ADT_Product_t str_2_ADT_Product_array[]= {
						str_2_ADT_Product_id,
						str_2_ADT_Product_description,
						str_2_ADT_Product_price
					   };
header_printer_t header_printer_array[]={
					print_header_open,
					print_products_open
					};

product_printer_t product_printer_array[]={
					print_html_object_info,
					print_xml_object_info
					};

closer_printer_t closer_printer_array[]={
					print_header_close,
					print_products_close
					};



status_t process_inventory(FILE * items, FILE * catalog, FILE * file_out){
	status_t st;	
	ADT_vector_t * v;
	ADT_Product_t p;

	if(items==NULL || catalog==NULL || file_out==NULL){
		return ERROR_NULL_POINTER;
	}
	if((st=header_printer_array[setting.fmt](file_out))!=OK){
		return st;
	}
	if((st=process_catalog(catalog, &p, &v))!=OK){
		
		return st;
	}
	if((st=process_item(items, file_out, v))!=OK){
		
		return st;
	}
	if((st=closer_printer_array[setting.fmt](file_out))!=OK){
		
		return st;
	}
	return OK;
}

/* Funcion que carga los valores del catalgo en un vector */
status_t process_catalog(FILE * catalog, ADT_Product_t * p, ADT_vector_t ** v){
	size_t i;
	char * str;
	status_t st;
	bool_t eof;
	

	if(catalog==NULL || p==NULL || v==NULL){
		return ERROR_NULL_POINTER;
	}
	if((st=ADT_vector_new(v))!=OK)
		return st;
	if((st=ADT_vector_set_clonator(*v, ADT_Product_clone))!=OK){
		return st;
	}
	if((st=ADT_vector_set_destructor(*v, ADT_Product_destroy))!=OK){
		return st;
	}
	if((st=read_file_line(catalog, &str, &eof))!=OK){
		ADT_vector_delete(v);
		return st;
	}
	eof=FALSE;
	i=0;
	while((st=read_file_line(catalog, &str, &eof))==OK && eof!=TRUE){
		
		if((st=create_ADT_Product(*v))!=OK){
		
			ADT_vector_delete(v);
			destroy_string(&str);
			return st;
		}
		if((st=line_2_ADT_Product(str, *v , i))!=OK){
		
			destroy_string(&str);
			ADT_vector_delete(v);
			return st;
		}
		i++;
	}
	if((st=ADT_vector_bubble_sort(*v, ADT_Product_compare_by_id))!=OK){
		
		destroy_string(&str);
		ADT_vector_delete(v);
		return st;
	}
		
	if((st=destroy_string(&str))!=OK){
		return st;
	}
	return OK;
}

/* Funcion que procesa el item */
status_t process_item(FILE * items, FILE * file_out, ADT_vector_t * v){
	size_t i; 
	size_t v_size;
	int position;
	ADT_Product_t * p;
	status_t st;
	bool_t eof;
	char * aux_str;

	if(items==NULL || file_out==NULL || v==NULL){
		ADT_vector_delete(&v);
		return ERROR_NULL_POINTER;
	}
	i=0;
	eof=FALSE;
	
	while((st=read_file_line(items, &aux_str, &eof))==OK && eof!=TRUE){
		if((st=ADT_Product_new(&p))!=OK){
			
			ADT_vector_delete(&v);
			destroy_string(&aux_str);
			return st;
		}				
		if((st=ADT_Product_set_id(p, aux_str))!=OK){
			
			ADT_Product_destroy((void **)&p);
			ADT_vector_delete(&v);
			destroy_string(&aux_str);
			return st;
		}				
		if((st=ADT_vector_get_size(*v, &v_size))!=OK){
			
			ADT_Product_destroy((void **)&p);
			ADT_vector_delete(&v);
			destroy_string(&aux_str);
			return st;
		}	
					
		if((position=ADT_vector_lineal_search(v, v_size, (void *)p, ADT_Product_compare_by_id))<0){	
			ADT_Product_destroy((void **)&p);
			ADT_vector_delete(&v);
			destroy_string(&aux_str);
			return ERROR_PRODUCT_NOT_FOUND;
		}				
		if((st=product_printer_array[setting.fmt](file_out, v->elems[position], i))!=OK){
			
			ADT_Product_destroy((void **)&p);
			ADT_vector_delete(&v);
			destroy_string(&aux_str);
			return st;
		}
		if((st=ADT_Product_destroy((void **)&p))!=OK){
			
			ADT_vector_delete(&v);
			destroy_string(&aux_str);
			return st;
		}
		if((st=destroy_string(&aux_str))!=OK){
			
			return st;
		}
		i++;
	}
	if((st=ADT_vector_delete(&v))!=OK){
		
		return st;
	}
	
	return OK;
}

/* Funcion que crea un producto y lo asocia a una posicion del vector */
status_t create_ADT_Product(ADT_vector_t *v){
	status_t st;
	ADT_Product_t * p;

	if(v==NULL){
		return ERROR_NULL_POINTER;
	}
	if((st=ADT_Product_new(&p))!=OK){
		return st;
	}
	if((st=ADT_vector_attach(v, p))!=OK){
		ADT_Product_destroy((void **)&p);
		return st;
	}
	return OK;
}

/* Funcion que convierte una linea del archivo catalogo a un producto */
status_t line_2_ADT_Product(char str [], ADT_vector_t * v, size_t position){
	status_t st;
	char ** aux_array;
	size_t len;
	size_t i;
	ADT_Product_t * p;

	if(str==NULL || v==NULL){
		return ERROR_NULL_POINTER;
	}
	len=0;
	if((st=split(&aux_array, str, CATALOG_DELIMITER, &len))!=OK){	
		
		return st;
	}
	if((st=ADT_vector_get_elem(*v, (void **)&p, position))!=OK){
		destroy_string_array(&aux_array, len);
		return st;
	}
	for(i=0; i<len; i++){
		if((st=str_2_ADT_Product_array[i](aux_array[i], p))!=OK){
			destroy_string_array(&aux_array, len);
			strcpy(invalid_data, str);
			return st;
		}
	}

	if((st=destroy_string_array(&aux_array, len))!=OK){
		return st;
	}
	return OK;
}

/* Funcion que convierte una cadena en un id */
status_t str_2_ADT_Product_id(char str [], ADT_Product_t *p){
	status_t st;

	if(str==NULL || p==NULL){
		return ERROR_NULL_POINTER;
	}
	if((st=ADT_Product_set_id(p, str))!=OK){
		return st;
	}
	return OK;
}

/* Funcion que convierte una cadena en una descripcion */
status_t str_2_ADT_Product_description(char str [], ADT_Product_t *p){
	status_t st;

	if(str==NULL || p==NULL){
		return ERROR_NULL_POINTER;
	}
	if((st=ADT_Product_set_description(p, str))!=OK){
		return st;
	}
	return OK;
}

/* Funcion que convierte una cadena en un precio */
status_t str_2_ADT_Product_price(char str [], ADT_Product_t *p){
	char * temp;
	double price_aux;
	status_t st;

	if(str==NULL || p==NULL){
		return ERROR_NULL_POINTER;
	}
	price_aux=strtod(str, &temp);
	if(*temp && *temp!=LF && *temp!=NUL){
		strcpy(invalid_data, str);
		return ERROR_INVALID_PRICE;
	}
	if((st=ADT_Product_set_price(p, price_aux))!=OK){
		return st;
	}
	return OK;
}
