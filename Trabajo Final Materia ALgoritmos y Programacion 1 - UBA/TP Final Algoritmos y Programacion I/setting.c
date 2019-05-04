#include "setting.h"

extern setting_t setting;

extern char * format_array[];

status_t str2setting (char * argv[]){
	status_t st;

	if(argv==NULL){
		return ERROR_NULL_POINTER;
	}
	strcpy(setting.items_path, argv[POS_ITEMS_SPECIFIER+1]);
	strcpy(setting.catalog_path, argv[POS_LIST_SPECIFIER+1]);
	strcpy(setting.out_path, argv[POS_OUT_SPECIFIER+1]);
	if((st=str2format(argv[POS_FORMAT_SPECIFIER+1], &(setting.fmt)))!=OK){
		return st;
	}
	return OK;
}

status_t str2format(const char str[], format_t * fmt){
	if(str==NULL || fmt==NULL){
		return ERROR_NULL_POINTER;
	}
	if(!strcmp(str, format_array[POS_FORMAT_HTML])){
		*fmt=FORMAT_HTML;
	}
	else{
		*fmt=FORMAT_XML;
	}
	return OK;
}
