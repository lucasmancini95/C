#include "main.h"

char invalid_data[MAX_DATA];
setting_t setting;
status_t status;

char * specifiers_array []= {FORMAT_SPECIFIER, 
	     		     ITEMS_SPECIFIER, 
	          	     LIST_SPECIFIER, 
	     		     OUT_SPECIFIER,
		            };
char * format_array[]={ 
			FORMAT_STRING_HTML,
			FORMAT_STRING_XML
			};

int main (int argc, char * argv []){
	FILE * items;
	FILE * catalog;
	FILE * file_out;
	
										
	if((status=validate_arguments(argc, argv))!=OK){
		print_log();
		return EXIT_FAILURE;
	}
										
	if((status=open_files(&items, &catalog, &file_out))!=OK){
		print_log();
		return EXIT_FAILURE;
	}

											
	if((status=process_inventory(items, catalog, file_out))!=OK){
		
		fclose(file_out);
		fclose (items);
		fclose (catalog);
		remove(setting.out_path);
		print_log();
		return EXIT_FAILURE;
	}
										
	if ((status=close_files (&items, &catalog, &file_out))!=OK){
		
		remove(setting.out_path);
		print_log();
		return EXIT_FAILURE;
	}
										
	status=OK;
	print_log();
	return EXIT_SUCCESS;
}
		
/* Funcion que cierra los archivos */
status_t close_files (FILE ** items, FILE ** catalog, FILE ** file_out){
	if(items==NULL || catalog==NULL || file_out==NULL){
		return ERROR_NULL_POINTER;
	}
	if ((fclose(*file_out))==EOF){
		fclose (*items);
		fclose (*catalog);
		strcpy(invalid_data, setting.out_path);
		return ERROR_CLOSE_FILE;
	}
	fclose (*items);
	fclose (*catalog);
	return OK;
}

/* Funcion general que valida */
status_t validate_arguments(int argc, char ** argv){
	status_t st;

	if(argv==NULL){
		return ERROR_NULL_POINTER;
	}
	if(validate_arg_amount(argc)!=OK){
		return ERROR_ARGS_AMOUNT;
	}
	if(validate_specifiers(&(argv[POS_FORMAT_SPECIFIER]))!=OK){
		return ERROR_INVALID_SPECIFIERS;
	}
	if(validate_format(argv[POS_FORMAT_SPECIFIER+1])!=OK){
		return ERROR_INVALID_FORMAT;
	}
	if((st=str2setting(argv))!=OK){
		return st;
	}
	return OK;
}

/*Funcion que valida la cantidad de argumentos*/
status_t validate_arg_amount(int argc){
	if (argc!= MAX_ARGS){										
		return ERROR_ARGS_AMOUNT;
	}
	return OK;
}

/*Funcion que valida los especificadores*/
status_t validate_specifiers(char ** specifier){
	size_t i;
	size_t j;

	if(specifier==NULL){
		return ERROR_NULL_POINTER;
	}
	for (i=0, j=0; i<sizeof (specifiers_array)/sizeof (*specifiers_array); i++, j=j+2){		
		if (strcmp (specifier[j],specifiers_array[i])){
			strcpy(invalid_data, specifier[j]);
			return ERROR_INVALID_SPECIFIERS;
		}
	}
	return OK;
}

/* Funcion que valida el formato ingresado como dato */
status_t validate_format(char fmt []){
	if (fmt==NULL){
		return ERROR_NULL_POINTER;
	}
	if( strcmp(fmt, format_array[POS_FORMAT_HTML]) && strcmp(fmt, format_array[POS_FORMAT_XML])){
		strcpy(invalid_data, fmt);
		return ERROR_INVALID_FORMAT;
	}
	return OK;
}

/* Funcion que abre los archivos  */
status_t open_files (FILE ** items, FILE ** catalog, FILE ** file_out){
	if(items==NULL || catalog==NULL || file_out==NULL){
		return ERROR_NULL_POINTER;
	}
	if((*items=fopen (setting.items_path, "rt"))==NULL){
		strcpy(invalid_data, setting.items_path);
		return ERROR_OPEN_FILE;
	}
	if((*catalog=fopen (setting.catalog_path, "rt"))==NULL){
		fclose (*items);
		strcpy(invalid_data, setting.catalog_path);
		return ERROR_OPEN_FILE;
	}
	if((*file_out=fopen (setting.out_path, "wt"))==NULL){
		fclose (*items);
		fclose (*catalog);
		strcpy(invalid_data, setting.out_path);
		return ERROR_OPEN_FILE;
	}
	return OK;
} 
