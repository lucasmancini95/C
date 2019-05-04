#include <stdio.h>
#include <stdlib.h>

size_t contar_digitos_l(int x);
size_t contar_digitos_tr(int x);
size_t _contar_digitos_tr(int x,size_t);

int main(void){

int x=110440;

printf("%d\n",contar_digitos_tr(x));
printf("%d\n",contar_digitos_l(x));


return EXIT_SUCCESS;
}


size_t contar_digitos_l(int x){

	if(x>0 && x<10){
		return 1;
	}
	
	if(x<0 && (x*(-1))<10 ){
		return 1;
	}

	return 1+contar_digitos_l(x/10);
}


size_t contar_digitos_tr(int x){
	return _contar_digitos_tr(x,0);
}

size_t _contar_digitos_tr(int x,size_t acc){

	if(x>0 && x<10){
		return acc+1;
	}
	
	if(x<0 && (x*(-1))<10 ){
		return acc+1;
	}

	return _contar_digitos_tr(x/10,acc+1);
}


