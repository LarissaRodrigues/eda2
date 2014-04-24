#include <iostream>
using namespace std;

int *merge(int *vetor,int bottom, int middle,int up){

  int sentinel = 4096;
  int inferior_array_size = middle - bottom + 1;
  int superior_array_size = up - middle; 

  int inferior_array[inferior_array_size + 1];
  int superior_array[superior_array_size + 1];

  for(int i = 0; i < inferior_array_size; i++){
    inferior_array[i] = vetor[bottom + i -1];
    //cout<<"inf"<<inferior_array[i]<<endl;
  }

  for(int j = 0; j < superior_array_size; j++){
    superior_array[j] = vetor[middle + j];
    //cout<<"superior"<<vetor[middle + j]<<endl;
  }

  inferior_array[inferior_array_size] = sentinel;
  superior_array[superior_array_size] = sentinel;

  int i = 0;
  int j = 0;
  for(int k = bottom-1; k < up; k++){
    //cout<<"sup"<<superior_array[j]<<endl; 
    if(inferior_array[i] <= superior_array[j]){
      vetor[k] = inferior_array[i];
      i++;
    }
    else{
      vetor[k] = superior_array[j];
      j++;
    }
  }
  for(int k = 0; k < up; k++){
    //cout<<"vector"<<vetor[k]<<endl;  
  }
}
int merge_sort(int vetor[],int bottom,int up){
  if(bottom < up){
    int middle = (bottom + up)/2;
    merge_sort(vetor,bottom,middle);
    merge_sort(vetor,middle+1,up);
    // cout<<"bottom"<<bottom<<endl;
    // cout<<"middle"<<middle<<endl;
    // cout<<"up"<<up<<endl;
    merge(vetor,bottom,middle,up);
  }    
}

int main(){

  int vetor[] = {6,3,4,12,6,76,12,43,2,11,90};
  cout<<"vetor antes do merge sort"<<endl;
  for(int i = 0; i<11; i++)
    cout<<vetor[i]<<endl;

  int bottom = 1,up = 11;
  merge_sort(vetor,bottom,up);
  cout<<"vetor apos o merge sort"<<endl;
  for(int i = 0; i<11; i++)
    cout<<vetor[i]<<endl;
}
