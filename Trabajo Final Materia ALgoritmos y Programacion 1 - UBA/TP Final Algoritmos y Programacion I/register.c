#include "register.h"

extern char invalid_data [];
extern status_t status;

char * msg_log_array []= {
				MSG_OK,
				MSG_ERROR_ARGS_AMOUNT,
				MSG_ERROR_INVALID_SPECIFIERS,
				MSG_ERROR_INVALID_FORMAT,
				MSG_ERROR_OPEN_FILE,
				MSG_ERROR_PRODUCT_NOT_FOUND,
				MSG_ERROR_NULL_POINTER,
				MSG_ERROR_INVALID_ID,
				MSG_ERROR_INVALID_DESCRIPTION,
				MSG_ERROR_INVALID_PRICE,
				MSG_ERROR_NO_MEMORY,
				MSG_ERROR_SORT,
				MSG_ERROR_CLOSE_FILE
				};



status_t print_date (FILE * fo){
	time_t auxtime;
	struct tm * auxstruct;

	if (fo==NULL){
		return ERROR_NULL_POINTER;
	}
	time (&auxtime);
	auxstruct= localtime (&auxtime);

	fprintf (fo, "%d", auxstruct->tm_mday);
	fputc (DASH_DELIMITER, fo);
	fprintf (fo,"%d", (auxstruct->tm_mon)+1);
	fputc (DASH_DELIMITER, fo);
	fprintf (fo, "%d", (auxstruct->tm_year)+1900);
	fputc (SPACE_DELIMITER, fo);
	fprintf (fo, "%d", auxstruct->tm_hour);
	fputc (COLON_DELIMITER, fo);
	fprintf (fo,"%d", auxstruct->tm_min);
	fputc (COLON_DELIMITER, fo);
	fprintf (fo, "%d", auxstruct->tm_sec);
	fputc (PIPE_DELIMITER, fo);
	return OK;
}

/* Funcion que guarda las ejecuciones del programa en un log */
void print_log (void){
	FILE * log;
	status_t st_aux;

	if ((log= fopen (LOG_FILE_PATH, "at"))==NULL){
		return ;
	}
	if ((st_aux=print_date(log))!=OK){
		status=st_aux;
	}
	if(status!=OK){
		fprintf(log, "%s", MSG_ERROR_PREFIX);
	}
	fprintf(log, "%s", msg_log_array[status]);
	if(is_empty_string(invalid_data) || status==OK){	
		fputc(LF, log);
	}
	else{
		fprintf(log, " (%s)\n", invalid_data);
	}
	if ((fclose (log))==EOF){
		strcpy(invalid_data, LOG_FILE_PATH);
		status=ERROR_CLOSE_FILE;
	}

}



