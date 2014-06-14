#include <vector>
#include "Node.cpp"

using namespace std;

class VectorArray{

  vector<vector<Node> > vector_array;

  public:
    VectorArray(int);
    vector<vector<Node> > getVectorArray()const{
      return this->vector_array;
    };

    void setVectorArray(int,int);
};

VectorArray::VectorArray(int size){
  this->vector_array = vector<vector<Node> > (size+1);
  }
void VectorArray::setVectorArray(int posit,int value){
      Node node(value);
      vector_array[posit].push_back(node);
}
