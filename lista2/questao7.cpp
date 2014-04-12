#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>

const int vector_size = 9;
using namespace std;

void regix_sort(int vector[]){

  string string_vetor[vector_size]; 
  int counting_sort_vector[vector_size];
  int *replace_counting;
  string number;


  for(int i = 1; i<vector_size; i++){
    stringstream ss;
    ss << vector[i];
    number = ss.str();
    string_vetor[i] = number;
  }
  cout<<"antes do radix"<<endl;
  for(int i = 1; i<vector_size; i++){

    cout<< string_vetor[i]<<endl;  

  }

  cout<<endl;

  for(int i = vector_size - 2; i >= 0; i--){
    for(int j = 1; j<=vector_size; j++){
      stringstream ss_1;
      ss_1 << string_vetor[j][i];
      int value;
      ss_1 >> value;
      counting_sort_vector[j] = value;
    }

    int aux_vector[vector_size];
    int ordered_vector[vector_size];
    memset(aux_vector,0,vector_size*sizeof(int));

    /*------------counting sort ----------------*/
    for(int p = 1; p < vector_size; p++){
      aux_vector[counting_sort_vector[p]] = aux_vector[counting_sort_vector[p]] + 1;
    }
    for(int p = 2; p < vector_size; p++){
      aux_vector[p] = aux_vector[p] + aux_vector[p-1];
    }
    for(int t = vector_size - 1; t >=  1; t--){
      ordered_vector[aux_vector[counting_sort_vector[t]]] = counting_sort_vector[t];
      aux_vector[counting_sort_vector[t]] = aux_vector[counting_sort_vector[t]] - 1;
    }

    /*------------counting sort ----------------*/

    for(int k = 1; k < vector_size; k++){
      stringstream ss_2;
      ss_2 << ordered_vector[k];
      ss_2 >> string_vetor[k][i];
    }
  }
  cout<<"apos o radix sort"<<endl;
  for(int i = 1; i<vector_size; i++)
    cout<<string_vetor[i]<<endl;
}

int main(){

  int vector[] = {-1,73231113,57222227,65733333,53644444,43612351,72156423,35532456,57212145};
  regix_sort(vector);
}
