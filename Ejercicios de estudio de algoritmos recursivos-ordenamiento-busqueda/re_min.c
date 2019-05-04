#include <stdio.h>
#include <stdlib.h>

float min_l(float* v,size_t len);
float _min_l(float* v,size_t len);

float min_DQ(const float* v,size_t len);

int main(void){
float v[5]={8,1222,4,3,5};
size_t len=5;
size_t i;

printf("%f\n\n\n",min_DQ(v,len));

for(i=0;i<len;i++){
printf("%f\n",v[i]);
}
/*
printf("%f\n",min_tr(v,len));

printf("%f\n",min_DQ(v,len));
*/
return 0;
}

float min_l(float* v,size_t len){
	float aux[5];
	size_t i;

	for(i=0;i<5;i++){
		aux[i]=v[i];
	}	
	
	return _min_l(aux,len);
}

float _min_l(float* v,size_t len){
	if(len==0){
		return 0;
	}
	if(len==1){
		return v[0];
	}
	
	if(v[0]<v[1]){
		v[1]=v[0];
	}
	return min_l(&(v[1]),len-1);
}



float min_DQ(const float* v,size_t len){
	float min_r, min_l;

	if(len==1){
		return v[0];
	}
	
	min_l=min_DQ(v,len/2);
	min_r=min_DQ(&(v[len/2]),len-len/2);

	return min_l<min_r?min_l:min_r;
}



/*
float sumatoria_DQ(const float* v,size_t len){

	if(len==0){
		return 0;
	}
	if(len==1){
		return v[0];
	}
	
	return sumatoria_DQ(v,len/2)+sumatoria_DQ(&(v[len/2]),len-len/2);
}*/
