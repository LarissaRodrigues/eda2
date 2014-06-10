#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Node{

  Node *neighbor;
  int value;
}node;


node *allocate_node(int value){
  node *new_node = (node *) malloc(1*sizeof(node));
  new_node->value = value;
  return new_node;
}



int main(){

  node *index_node[8];
  index_node[1] = allocate_node(2);
  index_node[1]->neighbor = allocate_node(3);
  index_node[1]->neighbor->neighbor = allocate_node(3);

  index_node[2] = allocate_node(1);
  index_node[2]->neighbor = allocate_node(3);
  index_node[2]->neighbor->neighbor = allocate_node(4);
  index_node[2]->neighbor->neighbor->neighbor  = allocate_node(5);
  
  index_node[3] = allocate_node(1);
  index_node[3]->neighbor = allocate_node(2);
  index_node[3]->neighbor->neighbor = allocate_node(5);
  index_node[3]->neighbor->neighbor->neighbor  = allocate_node(7);
  index_node[3]->neighbor->neighbor->neighbor->neighbor  = allocate_node(8);

  index_node[4] = allocate_node(2);
  index_node[4]->neighbor = allocate_node(5);

  index_node[5] = allocate_node(2);
  index_node[5]->neighbor = allocate_node(3);
  index_node[5]->neighbor->neighbor = allocate_node(4);
  index_node[5]->neighbor->neighbor->neighbor  = allocate_node(6);

  index_node[6]->neighbor = allocate_node(5);

  
  index_node[7]->neighbor = allocate_node(3);
  index_node[7]->neighbor->neighbor = allocate_node(8);


  index_node[8]->neighbor = allocate_node(3);
  index_node[8]->neighbor->neighbor = allocate_node(7);
}

