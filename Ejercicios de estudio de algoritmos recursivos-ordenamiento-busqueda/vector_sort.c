#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int v[],size_t);
void selection_sort(int v[],size_t);
void insertion_sort(int v[],size_t len);
void swap(int* x,int* y);

int main(void){

	int v[7]={1,8,7,7,3,9,47}; 
	size_t len,i;

	len=7;
	insertion_sort(v,len);

	for(i=0;i<len;i++){
		printf("%d\n",v[i]);
	}


	return 0;
}


void bubble_sort(int v[],size_t len){

	size_t i,j;

	for(i=0;i<(len-1);i++){
		for(j=0;j<len-1-i;j++){
			if(v[j]>v[j+1]){
				swap(&(v[j]),&(v[j+1]));
			}
		}
	}



}

void swap(int* x,int* y){
	 int temp;

	temp=*x;
	*x=*y;
	*y=temp;

}

void selection_sort(int v[],size_t len){
	
	size_t i,j,position;

	for (i=0;i<(len-1);i++){
		  position = i; 
		  for (j=i+1;j<len;j++){
		     if(v[position]>v[j]){
			   position = j;
			}      
		  }
		  if(position!=i){
		     swap(&(v[i]),&(v[position]));
		  }
	   }

}



void insertion_sort(int v[],size_t len){
	
	size_t i,s;

	for (i=0;i<=len-1;i++){
		 for(s=i;s>0 && v[s]<v[s-1];s--){
			swap(&(v[s]),&(v[s-1]));
		}
	  }

}
