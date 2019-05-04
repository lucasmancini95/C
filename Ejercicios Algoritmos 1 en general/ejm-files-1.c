#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CMD_ARG_INPUT_FILE 1
#define CMD_ARG_OUTPUT_FILE 2
#define ERROR_ABRIENDO_ARCHIVO_R "ERROR abriendo el archivo de lectura\n"
#define ERROR_ABRIENDO_ARCHIVO_W "ERROR abriendo el archivo de escritura\n"
#define ERROR_CERRANDO_ARCHIVO_R "ERROR cerrando el archivo de lectura\n"
#define ERROR_CERRANDO_ARCHIVO_W "ERROR cerrando el archivo de escritura\n"
#define MAX_ARGS 3

typedef enum{ERROR,OK} status_t;

status_t validate_arg(int,char **);

int main(int argc,char** argv){
	struct FILE* f1;
	struct FILE* f2;
	char c;

	if(validate_arg(argc,argv) != OK){
		return EXIT_FAILURE;
	}
	
	if((f1=fopen(argv[CMD_ARG_INPUT_FILE],"rt"))==NULL){
		fprintf(stderr,"%s",ERROR_ABRIENDO_ARCHIVO_R);
		return EXIT_FAILURE;
	}
	
	if((f2=fopen(argv[CMD_ARG_OUTPUT_FILE],"wt"))==NULL){
		fprintf(stderr,"%s",ERROR_ABRIENDO_ARCHIVO_W);
		fclose(f1);
		return EXIT_FAILURE;
	}

	while((c=fgetc(f1)) != EOF){
		fputc(toupper(c),f2);
	}
	if(fclose(f1)==EOF){
		fprintf(stderr,"%s",ERROR_CERRANDO_ARCHIVO_R);
		if(fclose(f2)==EOF){
			fprintf(stderr,"%s",ERROR_CERRANDO_ARCHIVO_W);
			return EXIT_FAILURE;
		}
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}	

status_t validate_arg(int argc ,char ** argv)
	{

	if((argc) != (MAX_ARGS))
	{
	/*showusage();*/
		return ERROR;
	}
	return OK;
}
