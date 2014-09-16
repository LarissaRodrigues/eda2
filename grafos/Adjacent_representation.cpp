#include <iostream>
#include "VectorArray.cpp"
//Testando comentarios 
using namespace std;

int main(){

  int size,posit,node_2;
  cin >> size;
  VectorArray vector_array(size);
  while(cin >> posit  >> node_2){
    vector_array.setVectorArray(posit,node_2);
  }
  return 0;
}
