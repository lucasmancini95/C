#include <stdio.h>
#include <stdlib.h>
#define ERROR_VALIDATE "ERROR\nSe ocasiono un error con los datos ingresados, lea el manual para mas informacion sobre como usar el programa\n"

typedef enum{OK,ERROR}status_t;

status_t validate_arg(int,char**);

int main(int argc, char * argv[]){
size_t i,j;
char* aux;
	
if( (validate_arg(argc,argv)) != OK)
	{
		fprintf(stderr,"%s", ERROR_VALIDATE);
		return EXIT_FAILURE;
	}

for(i=1;i<argc;i++){
	
	for(j=1;(j+i)<argc;j++){
		if( ((argv[i])[0]) > ((argv[j+i])[0]) ){
		aux= (argv[i]);
		(argv[i])=(argv[j+i]);
		(argv[j+i])= aux;
		}
	}
}

for(i=1; i<argc; i++){
	
printf("%s\n", argv[i]);
printf("%d\n",argc);	
}

return EXIT_SUCCESS;
}

status_t validate_arg(int argc,char* argv[]){

if(argv == NULL)return ERROR;
 
if(argc == 1)return ERROR;	

return OK;

}		 
