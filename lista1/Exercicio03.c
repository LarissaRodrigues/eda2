#include<stdio.h>
#include<stdlib.h>
#define size_vector 100
 
 
int main(){
	
   int vector[size_vector],count;
   int less = 1;
   int upper = 10;
   int middle, aux, value, option;
   
   do{
 
   for(count=0; count<size_vector; count++){
   	 vector[count]= count;
   	 printf("\n %d", vector[count]);
   }

    printf("\n Informe qual o valor deseja encontrar no vetor.");
    scanf("%d", &value);
    
   	middle = less +((upper - less)* (value- vector[less])/(vector[upper]-vector[less]));
   	
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
     
      printf(" \n Se deseja realizar outra busca digite 1. ");
      scanf ("%d", &option);
  } while(option == 1);

	return 0;
}
