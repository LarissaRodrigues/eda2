#include <iostream>
const int size_index = 10;
const int size_table = 1000;
using namespace std;

int *fill_vector(int vector[]){

  for (int i = 0; i<size_table; i++){
    vector[i] = i;
  }
  return vector;
}

int *fill_index(int vector[]){
  int count = 0;
  for (int i = 0; i<size_index; i++ ){
    vector[i] = count;
    count = count + 100;
  }
  return vector;
}


int main(){

  int vector_index[size_index];
  int vector_table[size_table];

  int *fill_vector_table;
  int *fill_vector_index;
  
  fill_vector_table  = fill_vector(vector_table);
  fill_vector_index = fill_index(vector_index);

  for(int i = 0; i<size_table; i++){
    cout << fill_vector_table[i]<<endl;
  }
 
  for(int i = 0; i<size_index; i++){
    cout << fill_vector_index[i]<<endl;
  }



}
