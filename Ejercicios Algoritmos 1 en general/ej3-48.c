#include <stdio.h>
#include <stdlib.h>

#define LARGO_FIL1 2
#define LARGO_COL1_FIL2 3
#define LARGO_COL2 4

int main(void){
int matriz_1[LARGO_FIL1][LARGO_COL1_FIL2];
int matriz_2[LARGO_COL1_FIL2][LARGO_COL2];
int matriz_producto[LARGO_FIL1][LARGO_COL2];
size_t i,j,k;

for(i=0;i<LARGO_FIL1;i++){
	for(j=0;j<LARGO_COL1_FIL2;j++){
		printf("ingrese el valor del vector en la posicion %d %d de la primer matriz\n",i+1,j+1);
		scanf("%d",&matriz_1[i][j]);
	}
}

for(i=0;i<LARGO_COL1_FIL2;i++){
	for(j=0;j<LARGO_COL2;j++){
		printf("ingrese el valor del vector en la posicion %d %d de la segunda matriz\n",i+1,j+1);
		scanf("%d",&matriz_2[i][j]);
	}
}


for(i=0;i<LARGO_FIL1;i++){
      for(j=0;j<LARGO_COL2;j++){
          matriz_producto[i][j]=0;
          for(k=0;k<LARGO_COL1_FIL2;k++){
              matriz_producto[i][j]+=matriz_1[i][k]*matriz_2[k][j];
          }
      }
  }



printf("la matriz en una sola fila es:");
for(i=0;i<LARGO_FIL1;i++){
	for(j=0;j<LARGO_COL2;j++){
		printf(" %d",matriz_producto[i][j]);
	}
}
printf("\n");
return 0;
}

