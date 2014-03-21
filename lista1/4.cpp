#include <iostream>
const int size_index = 10;
const int size_table = 1000;
using namespace std;
/*Preenche o vetor que terá todos os valores*/
int *fill_vector(int vector[]){

  for (int i = 0; i<size_table; i++){
    vector[i] = i;
  }
  return vector;
}

/*Preenche o vetor que terá os index */
int *fill_index(int vector[]){
  int count = 0;
  for (int i = 0; i<size_index; i++ ){
    vector[i] = count;
    count = count + 100;
  }
  return vector;
}

/*Baseado no valor retornado pelo index busca na tabela com todos os valores*/
int search_table(int id,int superior_index, int inferior_index,int fill_vector_table[]){
  for(int j = inferior_index; j<=superior_index; j++){
    if(fill_vector_table[j] == id){
      return fill_vector_table[j];
    }
  }
  return -1;
}


/*procura no index*/
void search_index(int id,int fill_vector_index[],int fill_vector_table[]){
  bool find = false;
  for(int i = 0; i < size_index; i++){
    if(fill_vector_index[i] == id){
      cout <<"Valor encontrado"<<endl;
      break;
    }
    if (fill_vector_index[i + 1] > id){
      int superior_index = fill_vector_index[i + 1];
      int inferior_index = fill_vector_index[i];
      int result = search_table(id,superior_index,inferior_index,fill_vector_table);
      if (result != -1){
        cout <<"Valor "<<result<<" encontrado"<<endl;
        cout <<"O valor estava entre o index "<<inferior_index<<" e o index "<<superior_index<<endl;
        find = true; 
        break;
      }
    }
  }
  if(find == false)
    cout << "Valor informado não consta no range da tabela indexada"<<endl;
}

int main(){


  int vector_index[size_index];
  int vector_table[size_table];

  int *fill_vector_table;
  int *fill_vector_index;

  fill_vector_table  = fill_vector(vector_table);
  fill_vector_index = fill_index(vector_index);

  int id;
  cout << "Informe um id desejado"<<endl;
  cin >> id;
  search_index(id,fill_vector_index,fill_vector_table);

}
