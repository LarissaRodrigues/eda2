	#include <stdlib.h>
	#include <stdio.h>
	int const  size_vector = 8;

	
		void heapsort (int vetor[size_vector], int maior) {	
				
	     int filhoDireita ;
	     int pai;
		 int filhoEsquerda;
		 int aux=0, aux2=0;
	     int i;
	     int cont;
		 int meio= size_vector/2;       	
	         
			   pai = i/2;
			   	   
			   for(i = 1; i <meio+1; i++){
	            
				 filhoDireita = 2*i;
			     if ( filhoDireita <=  size_vector){
			    
				  if (vetor[i-1] < vetor [filhoDireita -1  ] ){
				  	
			    	aux = vetor [i-1];
			    	vetor [i-1] = vetor[filhoDireita-1];
			    	vetor[filhoDireita-1] = aux;
			      	
			     	 heapsort(vetor, size_vector);
			    	 if(vetor[0] == maior){
		               break;
		            } 
			     }
			     
			     filhoEsquerda = (2*i) +1;
			     if( filhoEsquerda <= size_vector ){
			     
	     		   if(vetor [i-1] < vetor [filhoEsquerda-1 ] ){
					
				    	aux2 = vetor [i-1];
			        	vetor [i-1] = vetor[filhoEsquerda-1];
			    	    vetor[filhoEsquerda-1] = aux2;
			 	         heapsort(vetor, size_vector);
			    	     if(vetor[0] == maior){
		                break;
		              } 
			       }  
		     	}	 
	          }
	       
		         int j;
			     printf("Vetor ordenado em HEAP");
			     printf("\n");
		         for(j =1; j < size_vector+1; j++){
	                 printf("%d ", vetor[j-1]);	
	             }
	
	             if(vetor[0] == maior){   	   
		            break;
	   	        }  
	   	       
	     }
	   }	
		
	
   void inserirHeap(int vetorInserir[size_vector], int i){   
	     int value;
	     int cont;
         int maior=0;
         int aux;
         
	     printf("\n Informe o valor que deseja inserir no HEAP na posicao ");
	     scanf("%d", &value);
	     vetorInserir[i]=value;

           for(aux = 0; aux < size_vector; aux ++ ){
	     	if(vetorInserir[aux]>maior){
	     		maior=vetorInserir[aux];
	     	}
	      } 

	     heapsort(vetorInserir, maior);
	     
	     
	     int op=0;
	     printf("\n Deseja inserir outro elemento? Se sim ddigite 1 se não precione qualquer outra tecla.");
	     scanf("%d", &op);
	     if(op == 1){
	     	i++;
	     	inserirHeap(vetorInserir, i);
	     }
	     int op2;
	     printf("\n Deseja remover um elemento? Se sim digite 2 se não precione qualquer outra tecla.");
	     scanf("%d", &op2);
	     if(op2 == 2){
	     	int valor;
   	        int cont;
   	        printf("\n Informe o valor que desja remover do HEAP");
   	        scanf("%d", &valor);
   	
   	      for(cont = 0; cont<size_vector; cont++){
   	 	   if(vetorInserir [cont] ==  valor){
   	 	    	vetorInserir[cont] = 0;
   	 	    } 	
   	 	   heapsort(vetorInserir, maior);
   	      }
	    }
  }
		

	
int main(){

 int loop = 1;	

    while(loop == 1){
    
        printf("\n----------MENU------------------\n");
        printf("\n(1) Ordenar um vetor em forma de heap\n");
        printf("\n(2) Inserir e retirar elemento de um heap\n");
      
        int op;
        scanf("%d", &op);
        int valor;
        int i=0;
        int cont;
       
        int vetor1[size_vector];
        int vetorInserir[size_vector];
        
		switch(op){
        
         case 1:
            int cont;
           	printf("Vetor original:  \n ");
			
		    for(cont=1 ; cont<size_vector +1 ; cont ++ ){
		         vetor1[cont-1]=cont;	    
		    	printf(" %d ", vetor1[cont-1]);
	     	} 
		
		    heapsort (vetor1, size_vector);          
            break;
            
        case 2:
         
	       for(cont =0 ; cont<size_vector; cont++){
	            vetorInserir[cont] = 0;
	       }
           inserirHeap(vetorInserir, i);            
           break;

       } 
    
   
}
	
	
				    
		system("pause");
		return 0;	
		
	}

