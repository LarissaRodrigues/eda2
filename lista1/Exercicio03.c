#include<stdio.h>
#include<stdlib.h>
int main(){
	
   int vetor[10],cont;
   int inf = 1;
   int sup = 10;
   int meio, aux, x;
	
   for(cont=0; cont<10; cont++){
   	 vetor[cont]= cont;
   	 printf("\n %d", vetor[cont]);
   }

    printf("\n Informe qual o valor deseja encontrar no vetor.");
    scanf("%d", &x);
    
   	meio = inf +((sup - inf)* (x- vetor[inf])/(vetor[sup]-vetor[inf]));
   	
    for(aux=0; aux<10; aux++){
      if(meio == vetor[aux]){
      	printf("O valor foi achado em %d", aux+1);
      }
      if(meio > x){
      	sup=meio-1;
      	 meio = inf +((sup - inf)* (x- vetor[inf])/(vetor[sup]-vetor[inf]));
      }
      if(meio < x){
        inf= meio+1;
        meio = inf +(sup - inf)* (x- vetor[inf])/(vetor[sup]-vetor[inf]);
      }

    }
	return 0;
}
