#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) 
{
		size_t j,i,number;
        
        srand(time(NULL));
		
		number=getchar();
        
        for (i=0;i<number;i++){
			printf("%f\n",((j)*rand())/(RAND_MAX+1.0));
         } 
        return 0;
}

