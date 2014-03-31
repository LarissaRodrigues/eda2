#include <time.h> 
#include <iostream>
const int size_vector = 10;
using namespace std;
 
int main(){
	
   int vector[size_vector],count;
   int less = 1;
   int upper = 10;
   int middle;
   int aux;
   int value; 
   int option;
   clock_t start, end;
   float result_time;
   float result;
   
   do{
 
     for(count=0; count<size_vector; count++){
     	 vector[count]= count;
   	     cout << " "<<vector[count] <<endl;
    }
    
    cout << "Informe um valor desejado"<<endl;
    cin >> value; 
     
   	middle = less +((upper - less)* (value- vector[less])/(vector[upper]-vector[less]));
   	cout << "O valor do meio e :"<<middle<<endl; 
   	
   	start = clock();
   	
    for(aux=0; aux<size_vector; aux++){
      if(middle == vector[aux]){
      	cout << "O valor desejado foi achado na posicao"<<aux+1<<endl;
      }
      if(middle > value){
      	upper = middle-1;
      	middle = less +((upper - less)* (value- vector[less])/(vector[upper]-vector[less]));
        cout << "O valor do meio e :"<<middle<<endl;
	  }
      
      if(middle < value){
        less= middle + 1;
        middle = less +((upper - less)* (value- vector[less])/(vector[upper]-vector[less]));
        cout << "O valor do meio e :"<<middle<<endl;
      } 
    }
 
    end = clock(); 
    
    result_time = end-start;
    result =  ((float)result_time)/CLOCKS_PER_SEC;
    

     cout << "O tempo utilizado para a busca foi"<<result<<endl;
  
     cout << "Se deseja continuar a execução digite 1"<<endl;
     cin >> option;	 
      
  } while(option == 1);

	return 0;
}
