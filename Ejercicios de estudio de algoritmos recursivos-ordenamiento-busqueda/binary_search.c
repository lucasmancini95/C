#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(int  vector[], int n, int dato);
int busqueda_binaria_recursiva(int* v, int len, int target);

int main(void){

int v[8]={-154,-1,2,344,985,1000,8744,8754};
size_t len=8;
size_t posicion;

posicion=busqueda_binaria_recursiva(v,len,985);

printf("el numero %d esta en la posicion %d del vector\n",v[posicion],posicion);


return 0;
}




int busqueda_binaria(int  vector[], int n, int dato) {
   int centro,inf,sup;
	
	inf=0;	
	sup=n-1;

   while(inf<=sup){
      centro=((sup-inf)/2)+inf;
      if(vector[centro]==dato){
	      return centro;
 	  }    
	  else if(dato < vector[centro]){
			 sup=centro-1;
	  }
      else{
		inf=centro+1;
	  }
   }

   return -1;
}

int busqueda_binaria_recursiva(int v[], int len, int target) {

	if(len==0){
			return -1;
	}

	if(target<v[len/2]){
		return busqueda_binaria_recursiva(v,target,len/2-1);
	}
	
	if(target>v[len/2]){
		return busqueda_binaria_recursiva(&(v[(len/2)+1]),target,len-(len/2)-1);
	}

	return len/2;
}





