#include <iostream>
#include <stdlib.h>
#include <stdio.h>

const int size_vetor = 18;
const int relative_size_vetor = 17;
#define find 1
#define dont_find -1
#define keep_looking 0

using namespace std;

int adjustment_inferior_position(int middle){
  if(middle  + 1 > relative_size_vetor)
    return 0;
  else
    return middle + 1;
}

int adjustment_superior_position(int middle){
  if(middle - 1 < 0)
    return relative_size_vetor;
  else
    return middle -  1;
}

int calc_middle(int inferior_position,int superior_position){

  if(inferior_position < superior_position)
    return (superior_position + inferior_position)/2;
  else{
    //Dessa forma para uma lista circular, nunca cairemos em uma espaco vazio. 
    int temp_pos = (superior_position + (inferior_position + size_vetor))/2;
    if(temp_pos < size_vetor)
      return temp_pos;
    else
      return temp_pos % size_vetor;
  }
}

int search_value_in_vetor(int inferior_position,int superior_position,int middle,int *vetor,int value){
  if(vetor[inferior_position] == value) {
    cout<<"Valor encontrado na posicao "<<inferior_position<<" do vetor"<<endl;
    return find;
  }
  if(vetor[superior_position] == value){  
    cout<<"valor encontrado na posicao"<<superior_position<<endl;
    return find;
  }
  if(vetor[middle] == value){
    cout<<"valor encontrado na posicao"<<middle<<endl;
    return find;
  }
  if((inferior_position + 1 == middle && superior_position - 1 == middle) || inferior_position == superior_position ||  inferior_position + 1 == superior_position){
    cout<<"valor nao encontrou"<<endl;
    return dont_find;
  }
  else
    return keep_looking;
}


int main(){
  //a pos -1 indica um espaco vazio no vetor; 
  int vetor[] = {200,235,300,-1,-1 ,-1 ,-1 ,40,44,47,50,59,70,73,101,121,134,195};
  int inferior_position = 7;
  int superior_position = 2;

  int value;
  cout << "informe o valor a ser buscado" << endl;
  cin >> value;

  int middle_position;  
  middle_position = calc_middle(inferior_position,superior_position);

  if(search_value_in_vetor(inferior_position,superior_position,middle_position,vetor,value) == keep_looking){
    while(true){

      if(value <  vetor[middle_position]){
        superior_position = adjustment_superior_position(middle_position);
        cout<<"sup : "<<superior_position<<" inf : "<<inferior_position;
        middle_position = calc_middle(inferior_position,superior_position);
        cout<<" middle: "<<vetor[middle_position]<<endl;
        if(search_value_in_vetor(inferior_position,superior_position,middle_position,vetor,value) == find){
          break;
        }
        if(search_value_in_vetor(inferior_position,superior_position,middle_position,vetor,value) == dont_find){
          break;
        }
      }

      else{
        inferior_position = adjustment_inferior_position(middle_position);
        cout<<"sup : "<<superior_position<<" inf : "<<inferior_position;
        middle_position = calc_middle(inferior_position,superior_position);
        cout<<" middle: "<<vetor[middle_position]<<endl;
        if(search_value_in_vetor(inferior_position,superior_position,middle_position,vetor,value) == find){
          break;
        }
        if(search_value_in_vetor(inferior_position,superior_position,middle_position,vetor,value) == dont_find){
          break;
        }
      } 
    }
  }
  system("pause");
  return 0;
}
