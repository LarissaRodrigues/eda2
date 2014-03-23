#include<stdio.h>
#include<stdlib.h>
#define size_vector 100
 
 
int main(){
	
   int vector[size_vector],count;
   int inf = 1;
   int sup = 10;
   int meio, aux, x, op;
   
   do{
 
   for(count=0; count<size_vector; count++){
   	 vector[count]= count;
   	 printf("\n %d", vector[count]);
   }

    printf("\n Informe qual o valor deseja encontrar no vetor.");
    scanf("%d", &x);
    
   	meio = inf +((sup - inf)* (x- vector[inf])/(vector[sup]-vector[inf]));
   	
    for(aux=0; aux<size_vector; aux++){
      if(meio == vector[aux]){
      	printf("O valor foi achado em %d", aux+1);
      }
      if(meio > x){
      	sup=meio-1;
      	 meio = inf +((sup - inf)* (x- vector[inf])/(vector[sup]-vector[inf]));
      }
      if(meio < x){
        inf= meio+1;
        meio = inf +(sup - inf)* (x- vector[inf])/(vector[sup]-vector[inf]);
      } 
    }
     
 printf(" \n Se deseja realizar outra busca digite 1. ");
 scanf ("%d", &op);
    } while(op == 1);

    
    

	return 0;
}
