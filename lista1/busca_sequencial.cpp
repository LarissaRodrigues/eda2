#include <iostream>
const int size_index = 10;
const int size_table = 100;
const int empty = -1;
using namespace std;

typedef struct Range{
  int superior_index;
  int inferior_index;
}range;

Range return_search_range(int value,int vector_indexed[]){
  range aux_range;  
  for(int i = 0; i < size_index; i++){
    if(vector_indexed[i] == value){
      cout <<"Valor encontrado"<<endl;
      break;
    }
    if (vector_indexed[i + 1] > value){
      aux_range.superior_index = vector_indexed[i + 1];
      aux_range.inferior_index = vector_indexed[i];
      break;
    }
  }
    return aux_range;
  }


/*Preenche o vetor que terá todos os valores*/
int *fill_vector(int vector[]){

  for (int i = 0; i<size_table; i++){
    vector[i] = i*2;
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

int search_value_in_ordered_vector(int id,int superior_index, int inferior_index,int ordered_vector[]){
  int aux_value;
  for(int j = inferior_index; j<=superior_index; j++){
    if(ordered_vector[j] == id){
      return ordered_vector[j]; 
    }
  }
  return -1;
}

void search_vector_indexed(int value,int vector_indexed[],int ordered_vector[]){
  bool find = false;
  for(int i = 0; i < size_index; i++){
    if(vector_indexed[i] == value){
      cout <<"Valor encontrado"<<endl;
      break;
    }
    if (vector_indexed[i + 1] > value){
      int superior_index = vector_indexed[i + 1];
      int inferior_index = vector_indexed[i];
      if (search_value_in_ordered_vector(value,superior_index,inferior_index,ordered_vector) == -1){
        cout <<"Valor "<<search_value_in_ordered_vector(value,superior_index,inferior_index,ordered_vector)<<" encontrado"<<endl;
        cout <<"O valor estava entre o index "<<inferior_index<<" e o index "<<superior_index<<endl;
        find = true; 
        break;
      }
    }
  }
  if(find == false)
    cout << "Valor informado não consta no range da tabela indexada"<<endl;
}

void insert_value_in_ordered_vector(int value,int vector_indexed[],int ordered_vector_of_values[]){
  range aux_range = return_search_range(value,vector_indexed);
  int inferior_counter = aux_range.inferior_index;
  int empty_position_1;
  int empty_position;
  int insert_position; 
  bool primeiro = false;
  bool segundo = false;
  while(true){
    bool find = false;
    if(ordered_vector_of_values[inferior_counter + 1] > value && ordered_vector_of_values[inferior_counter] < value){
      insert_position = inferior_counter;
      primeiro = true;
    }
    if(ordered_vector_of_values[inferior_counter] == -1){
      empty_position_1 = inferior_counter;
      segundo = true;
    }

    cout <<"ordered"<<ordered_vector_of_values[inferior_counter]<<endl;
    if(ordered_vector_of_values[inferior_counter] == -1 && insert_position <= inferior_counter && primeiro == true){
      cout<<"inferior"<<inferior_counter<<endl;
      empty_position = inferior_counter;
      while(value < ordered_vector_of_values[empty_position - 1]){
        cout<<"achou espaco em branco"<<endl;
        ordered_vector_of_values[empty_position] = ordered_vector_of_values[empty_position - 1];
        empty_position--;
      }
      cout<<"empty_position"<<empty_position<<endl;
      ordered_vector_of_values[empty_position] = value;
      find = true;
    } 
    if(ordered_vector_of_values[inferior_counter] == -1 && find == false){
      empty_position_1 = inferior_counter;
    }
    if(ordered_vector_of_values[inferior_counter + 1] < value  && empty_position_1 <= inferior_counter && segundo == true){
      while(ordered_vector_of_values[empty_position_1 + 1] < value){
        cout<<"achou espaco em branco antes"<<endl;
        ordered_vector_of_values[empty_position_1] = ordered_vector_of_values[empty_position_1+1];
        empty_position_1++;
      }
      ordered_vector_of_values[empty_position_1] = value;
      cout<<"empty_position_1"<<empty_position_1<<endl;
      ordered_vector_of_values[empty_position_1] = value;
      find = true;
    } 
    if(find == true)
      break;
    inferior_counter++;
    if(inferior_counter == aux_range.superior_index){
      inferior_counter = vector_indexed[aux_range.superior_index + 1];
      aux_range.superior_index = vector_indexed[aux_range.superior_index + 2];
    }
    if(inferior_counter == size_table - 1){
      break;
    }
  }
}

int remove_value_ordered_vector(int value,int vector_indexed[],int ordered_vector_of_values[]){

  Range aux_range = return_search_range(value,vector_indexed);
    
  for(int i = aux_range.inferior_index; i<=aux_range.superior_index; i++){
    if(ordered_vector_of_values[i] == value)
      ordered_vector_of_values[i] = empty;
  }
}
int main(){


  int empty_vector_index[size_index];
  int empty_vector_values[size_table];

  int *ordered_vector_of_values;
  int *vector_indexed;

  ordered_vector_of_values = fill_vector(empty_vector_values);
  vector_indexed = fill_index(empty_vector_index);
  ordered_vector_of_values[80] = -1;
  int choose;
  cout<<"------Selecione a operacao desejada-------"<<endl;
  cout<<"buscar valor => 1"<<endl;
  cout<<"inserir valor => 2"<<endl;
  cout<<"remover valor => 3"<<endl;
  cin >> choose;

  int value;
  switch(choose){

    case 1:
      cout << "Informe um valor desejado"<<endl;
      cin >> value;
      search_vector_indexed(value,vector_indexed,ordered_vector_of_values);
      break;
    case 2:
      cout<<"Informe o valor a ser inserido"<<endl;
      cin >> value;
      insert_value_in_ordered_vector(value,vector_indexed,ordered_vector_of_values);
      for(int i = 0; i<size_table; i++)
        cout<<ordered_vector_of_values[i]<<endl;
      break;
    
    case 3:
      cout<<"informe  a posicao ser removido"<<endl;     
      cin >> value;
      remove_value_ordered_vector(value,vector_indexed,ordered_vector_of_values);
      for(int i = 0; i<size_table; i++)
        cout<<ordered_vector_of_values[i]<<endl;
      break;
    
    default:
      cout<<"opcao invalida,execute novamente"<<endl;
  }

}
