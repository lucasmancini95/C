#include <stdio.h>
#include <string.h>
#define LENGTH 5

size_t my_strlen(const char*);
int my_strcmp(const char*,const char*);
char* my_strcat(char*,const char*);
char* my_strcopy(char*,const char*);

int main(void){
char string1[]="hola";
char string2[]="chau";

printf("my_strlen: %d\n", my_strlen(string1));

printf("my_strcmp: %d\n", my_strcmp(string1,string2));

printf("my_strcat: %s\n", my_strcat(string1,string2));

printf("my_strcopy: %s\n", my_strcopy(string1,string2));


return 0;
}

size_t my_strlen(const char* string1){

size_t i;
for(i=0;string1[i] != NULL;i++);

return i;
}

int my_strcmp(const char* string1,const char* string2){

size_t i;
for(i=0;string1[i]==string2[i];i++);
if(string1[i]==NULL){
	return 0;
}
else{
	return 1;
}
}

char* my_strcat(char* string1,const char* string2){

size_t i;
size_t j;
for(i=0; string1[i] != NULL; i++){
	for(j=0;string2[j] != NULL;j++){
		string1[i]=string2[i];
	}
}
return string1;
}

char* my_strcopy(char* string1,const char* string2){

size_t i;
for(i=0; string1[i] != NULL; i++){
	string1[i]=string2[i];
}
return string1;
}
