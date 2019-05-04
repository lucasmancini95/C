#include <stdio.h>
#include <stdlib.h>


float sumatoria_l(const float* v,size_t len);

float sumatoria_tr(const float* v,size_t len);
float _sumatoria_tr(const float* v,size_t len,float acc);

float sumatoria_DQ(const float* v,size_t len);

int main(void){
float v[5]={1,1222,4,8,5};
size_t len=5;

printf("%f\n",sumatoria_l(v,len));

printf("%f\n",sumatoria_tr(v,len));

printf("%f\n",sumatoria_DQ(v,len));

return EXIT_SUCCESS;
}


/*recursividad lineal*/
float sumatoria_l(const float* v,size_t len){

	if(len==0){
		return 0;
	}

	return v[0]+sumatoria_l(&(v[1]),len-1);
}




/*recursividad de cola*/  
float sumatoria_tr(const float* v,size_t len){
	return _sumatoria_tr(v,len+1,0);
}
float _sumatoria_tr(const float* v,size_t len,float acc){
	if(len==0){
		return acc +v[0];
	}
	return _sumatoria_tr(&(v[1]),len-1,acc+v[0]);
}




/*recursividad "Divide & Conquer"*/  
float sumatoria_DQ(const float* v,size_t len){

	if(len==0){
		return 0;
	}
	if(len==1){
		return v[0];
	}
	
	return sumatoria_DQ(v,len/2)+sumatoria_DQ(&(v[len/2]),len-len/2);
}


