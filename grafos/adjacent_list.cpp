#include <iostream>
#include <vector>

using namespace std;


vector<vector<int> > insert_vertex(vector<vector<int> > graph,int position,int vertex){

  graph[position].push_back(vertex);
  return graph;
}

int main(){


  unsigned int num_v;
  unsigned int num_e;

  cin >> num_v;
  cin >> num_e;

  unsigned int vertex_1,vertex_2;
  vector<vector<int> > graph;

  while(cin >> vertex_1 >> vertex_2){
    insert_vertex(graph,vertex_1,vertex_2);
  }
}

