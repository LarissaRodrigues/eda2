#include <iostream>
#include <queue>
#include <map>
#include <climits>
#include <iterator>
#include <algorithm>
 
const int symbols = 1 << CHAR_BIT;
const char* nameOfSerie = "ONCE UPON A TIME";
typedef std::map<char, std::vector<bool> > HuffCodeMap;
 
class INodeTree{ public:
    int f;
    virtual ~INodeTree() {}
 
protected:
    INodeTree(int f) : f(f) {}
};
 
class InternalNodeTree : public INodeTree{  public:
    INodeTree *left;
    INodeTree *right;
 
    InternalNodeTree(INodeTree* c0, INodeTree* c1) : INodeTree(c0->f + c1->f), left(c0), right(c1) {}
    ~InternalNodeTree(){}
};
 
class LeafNode : public INodeTree{ public:
    const char c;
 
    LeafNode(int f, char c) : INodeTree(f), c(c) {}
};
 
struct NodeCmp{
    bool operator()(INodeTree* lhs, INodeTree* rhs){ 
	   return lhs->f > rhs->f;
   }
};
 
INodeTree* createsHuffman(int (&frequencies)[symbols]){
    std::priority_queue<INodeTree*, std::vector<INodeTree*>, NodeCmp> trees;
 
    for (int i = 0; i < symbols; ++i){
        if(frequencies[i] != 0)
            trees.push(new LeafNode(frequencies[i], (char)i));
    }
    while (trees.size() > 1){
        INodeTree* childR = trees.top();
        trees.pop();
 
        INodeTree* childL = trees.top();
        trees.pop();
 
        INodeTree* parent = new InternalNodeTree(childR, childL);
        trees.push(parent);
    }
    return trees.top();
}
 
void GenerateCodesHuffman(INodeTree* node, const std::vector<bool>& prefix, HuffCodeMap& outCodes){
    if (const LeafNode* lf = dynamic_cast<const LeafNode*>(node)){
        outCodes[lf->c] = prefix;
    }
    else if (const InternalNodeTree* in = dynamic_cast<const InternalNodeTree*>(node)){
        std::vector<bool> leftPrefix = prefix;  
        leftPrefix.push_back(false);        
        GenerateCodesHuffman(in->left, leftPrefix, outCodes); 
 
        std::vector<bool> rightPrefix = prefix; 
        rightPrefix.push_back(true);
        GenerateCodesHuffman(in->right, rightPrefix, outCodes);
    }
}
 
int main(){
   
    int frequenciesSymbols[symbols] = {0};
    const  char* stringDefined = nameOfSerie;
    while (*stringDefined != '\0'){   
                            
    	 ++frequenciesSymbols[*stringDefined++];
    }
	
    INodeTree* root = createsHuffman(frequenciesSymbols);
 
    HuffCodeMap codes;
    GenerateCodesHuffman(root,std::vector<bool>(), codes);
 
 
    for (HuffCodeMap::const_iterator it = codes.begin(); it != codes.end(); ++it){
    	
        std::cout << it->first << " ";
        std::copy(it->second.begin(), it->second.end(), std::ostream_iterator<bool>(std::cout));
        std::cout << std::endl;
    }
    return 0;
}
