#include <iostream>
#include <stdlib.h>
const int size_index = 11;
const int size_table = 1000;
const int empty = -1;
int full_vector = 1000;
int valid_insert = 0;

using namespace std;

typedef struct Range{
  int superior_index;
  int inferior_index;
}range;


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
  for (int i = 0; i<=size_index - 1; i++ ){
    vector[i] = count;
    count = count + 100;
  }
  return vector;
}

Range return_search_range(int value,int vector_indexed[]){
  range aux_range;  
  for(int i = 0; i <= size_index - 1; i++){
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

int search_value_in_ordered_vector(int id,range aux_range,int ordered_vector_of_values[]){
  int aux_value = -1;
  for(int j = aux_range.inferior_index; j<=aux_range.superior_index; j++){
    if(ordered_vector_of_values[j] == id){
      aux_value = ordered_vector_of_values[j]; 
      break;
    }
  }
  return aux_value;
}

void search_vector_indexed(int value,int vector_indexed[],int ordered_vector_of_values[]){
  bool find;
  for(int i = 0; i <= size_index; i++){
    if(vector_indexed[i] == value){
      cout <<"Valor encontrado"<<endl;
      break;
    }
    if (vector_indexed[i + 1] > value){
      range aux_range;
      aux_range.superior_index = vector_indexed[i + 1];
      aux_range.inferior_index = vector_indexed[i];
      int aux_value = search_value_in_ordered_vector(value,aux_range,ordered_vector_of_values);
      if (aux_value  != -1){
        cout <<"Valor "<<aux_value<<" encontrado"<<endl;
        cout <<"O valor estava entre o index "<<aux_range.inferior_index<<" e o index "<<aux_range.superior_index<<endl;
        find = true; 
        break;
      }
    }
  }
  if(find == false)
    cout << "Valor informado não consta no range da tabela indexada"<<endl;
}

void insert_value_before_empty_space(int value,int inferior_counter,int insert_position,int ordered_vector_of_values[]){
    if(ordered_vector_of_values[inferior_counter] == -1){
      while(value <= ordered_vector_of_values[insert_position- 1]){
        ordered_vector_of_values[insert_position] = ordered_vector_of_values[insert_position - 1];
        insert_position--;
      }
      ordered_vector_of_values[insert_position] = value;
      cout<<"valor inserido com sucesso"<<endl;
      full_vector++;
      valid_insert = 1;
    } 
}

void insert_value_after_empty_space(int value,int inferior_counter,int empty_position,int ordered_vector_of_values[]){
    if(ordered_vector_of_values[inferior_counter + 1] <= value  && empty_position <= inferior_counter){
      empty_position = inferior_counter;
      while(ordered_vector_of_values[empty_position + 1] <= value){
        ordered_vector_of_values[empty_position] = ordered_vector_of_values[empty_position+1];
        empty_position++;
      }
      ordered_vector_of_values[empty_position] = value;
      cout<<"valor inserido com sucesso"<<endl;
      full_vector++;
      valid_insert = 1;
    } 
}

void insert_value_in_ordered_vector(int value,int vector_indexed[],int ordered_vector_of_values[]){
  cout<<endl;
  range aux_range = return_search_range(value,vector_indexed);
  int inferior_counter = aux_range.inferior_index;
  int empty_position;
  int insert_position; 
  if(full_vector < 1000){
  while(true){
    if(ordered_vector_of_values[inferior_counter + 1] >= value && ordered_vector_of_values[inferior_counter] <= value){
      insert_position = inferior_counter;
       insert_value_before_empty_space(value,inferior_counter,insert_position,ordered_vector_of_values);
    }
    if(ordered_vector_of_values[inferior_counter] == -1){
      empty_position = inferior_counter;
      insert_value_after_empty_space(value,inferior_counter,empty_position,ordered_vector_of_values);
    }

    inferior_counter++;
    if(inferior_counter == aux_range.superior_index && inferior_counter + 1){
      inferior_counter = vector_indexed[aux_range.superior_index + 1];
      aux_range.superior_index = vector_indexed[aux_range.superior_index + 2];
    }
    if(inferior_counter == size_table - 1 || valid_insert == 1){
      break;
    }
  }
  }
  else
    cout<<"Infelizmente nao ha espaco disponivel, remova um elemento primeiro"<<endl;
}


void remove_value_ordered_vector(int value,int vector_indexed[],int ordered_vector_of_values[]){

  Range aux_range = return_search_range(value,vector_indexed);
    
  for(int i = aux_range.inferior_index; i<=aux_range.superior_index; i++){
    if(ordered_vector_of_values[i] == value){
      ordered_vector_of_values[i] = empty;
      cout<<"valor removido com sucesso"<<endl;
      full_vector--;
      break;
    }
  }
}

int main(){


  int empty_vector_index[size_index];
  int empty_vector_values[size_table];

  int *ordered_vector_of_values;
  int *vector_indexed;

  ordered_vector_of_values = fill_vector(empty_vector_values);
  vector_indexed = fill_index(empty_vector_index);
  char option;
  do{
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
      cout<<"Vetor com valores atualizados"<<endl;
      for(int i = 0; i<size_table; i++)
        cout<<" "<<ordered_vector_of_values[i];
      break;

    case 2:
      cout<<"Informe o valor a ser inserido"<<endl;
      cin >> value;
      insert_value_in_ordered_vector(value,vector_indexed,ordered_vector_of_values);
      cout<<"Vetor com valores atualizados"<<endl;
      valid_insert = 0;
      for(int i = 0; i<size_table; i++)
        cout<<" "<<ordered_vector_of_values[i];
      break;
    
    case 3:
      cout<<"informe  a posicao ser removida"<<endl;     
      cin >> value;
      remove_value_ordered_vector(value,vector_indexed,ordered_vector_of_values);
      cout<<"Vetor com valores atualizados"<<endl;
      for(int i = 0; i<size_table - 1; i++)
        cout<<" "<<ordered_vector_of_values[i];
      break;

    default:
      cout<<"opcao invalida,execute novamente"<<endl;
  }
  cout<<endl;
  cout<<"deseja continuar? s/n"<<endl;
  cin >> option;
}while(option != 'n');
}
