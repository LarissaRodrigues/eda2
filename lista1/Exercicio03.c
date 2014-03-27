#include<stdio.h>
#include<stdlib.h>
#define size_vector 1000
#include <time.h> 
 
int main(){
	
   int vector[size_vector],count;
   int less = 1;
   int upper = 10;
   int middle, aux;
   int value, option;
   clock_t start, end;
   float result_time, result;
   
   do{
 
   for(count=0; count<size_vector; count++){
   	 vector[count]= count;
   	 printf("\n %d", vector[count]);
   }

    printf("\n Informe qual o valor deseja encontrar no vetor.");
    scanf("%d", &value);
    
   	middle = less +((upper - less)* (value- vector[less])/(vector[upper]-vector[less]));
   	
   	start = clock();
   	
    for(aux=0; aux<size_vector; aux++){
      if(middle == vector[aux]){
      	printf("O valor foi achado em %d", aux+1);
      }
      if(middle > value){
      	upper = middle-1;
      	middle = less +((upper - less)* (value- vector[less])/(vector[upper]-vector[less]));
      }
      if(middle < value){
        less= middle + 1;
        middle = less +((upper - less)* (value- vector[less])/(vector[upper]-vector[less]));
      } 
    }
 
    end = clock(); 
    
    result_time = end-start;
    result =  ((float)result_time)/CLOCKS_PER_SEC;
    
    printf("\n O tempo utilizado para realizar a busca e %f", result );
	 
      printf(" \n Se deseja realizar outra busca digite 1. ");
      scanf ("%d", &option);
  } while(option == 1);

	return 0;
}
