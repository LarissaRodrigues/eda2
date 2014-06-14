#include <vector>
using namespace std;

class Node{

  int node;
  public:
    Node(int); 
    int getValue()const{
      return this->node;
    }
};
Node::Node(int node){
  this->node = node;
}
