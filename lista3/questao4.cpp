#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include<ctime>


const int vector_size = 9;
using namespace std;

int *counting_sort (int unordered_vector[],int size_unordered_vector,int return_ordered_vector[]){

    int aux_vector[size_unordered_vector];

    memset(aux_vector,0,size_unordered_vector*sizeof(int));

    for(int p = 1; p < size_unordered_vector; p++){
      aux_vector[unordered_vector[p]] = aux_vector[unordered_vector[p]] + 1;
    }
    for(int p = 2; p < size_unordered_vector; p++){
      aux_vector[p] = aux_vector[p] + aux_vector[p-1];
    }
    for(int t = size_unordered_vector - 1; t >=  1; t--){
      return_ordered_vector[aux_vector[unordered_vector[t]]] = unordered_vector[t];
      aux_vector[unordered_vector[t]] = aux_vector[unordered_vector[t]] - 1;
    }
    return return_ordered_vector;
}

int *bucket_sort(int counting_sort_vector[],int ordered_vector[]){

  int num_buckets = 2;

  int bucket_1[num_buckets];
  int bucket_2[num_buckets];

  memset(bucket_1,0,vector_size*sizeof(int));
  memset(bucket_2,0,vector_size*sizeof(int));

  int size_bucket[num_buckets]; 
  int size_bucket_1 = 0 ;
  int size_bucket_2 = 0 ;

  int aux_size = 0;
  int i = 0;
  int j = 0;

  while(aux_size < vector_size){
    
    if(counting_sort_vector[aux_size] < 5){
        bucket_1[i] = counting_sort_vector[aux_size];
        size_bucket_1++;
        i++;
    }
    else{
      bucket_2[j] = counting_sort_vector[aux_size]; 
      j++;
      size_bucket_2++;
    }
      aux_size++;
  }

 aux_size = 0;
 while(aux_size < num_buckets){
   int ordered_vector[size_bucket[aux_size]]; 
   counting_sort(bucket_1,size_bucket_1,ordered_vector);
   counting_sort(bucket_2,size_bucket_2,ordered_vector);
   aux_size++;
 }
 int  aux_size_2 = 0;
   while(aux_size_2 < size_bucket_1){
     cout << bucket_1[aux_size]<<endl;
     aux_size_2++;
   }
 }
  
void regix_sort(int vector[]){
  string string_vetor[vector_size]; 
  int counting_sort_vector[vector_size];
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

    int ordered_vector[vector_size];
    int * _ordered_vector;
    _ordered_vector = bucket_sort(counting_sort_vector,ordered_vector);

    for(int k = 1; k < vector_size; k++){
      stringstream ss_2;
      ss_2 << _ordered_vector[k];
      ss_2 >> string_vetor[k][i];
    }
  }
  cout<<"apos o radix sort"<<endl;
  for(int i = 1; i<vector_size; i++){ 
    cout<< string_vetor[i]<<endl;  
  }
}
int main(){
  int vector[] = {-1,73231113,57222227,65733333,53644444,43612351,72156423,35532456,57212145};
  regix_sort(vector);
}
