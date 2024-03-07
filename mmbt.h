// Yoshii - Minmax game tree - binary - header file
// DO NOT CHANGE!!!!

using namespace std;
#include <string>

// definition of what a Vertex (a state) is - also hidden from the client
struct Vertex
{
  Vertex *Left = NULL;;
  string  Elem; // operator path e.g. LLR
  int     Value;  // state score 
  Vertex *Right = NULL;

};


class MMBT
{

private:
  Vertex *Root;  // data member is Root which is a pointer to the root
  int Bottom;         // bottom level 0...B  0 is a MAX level

public:

   MMBT();
  ~MMBT();  // destructor calls dtraverse to destroy the dynamic tree
  void dtraverse(Vertex*);


  void Traverse(int); // calls DFS functions based on the int mode

  void DFSbuild(Vertex*, int, string); // to build the tree and assign scores to leaves
                         // int is the level and string is the operator path so far
  void DFSdisplay(Vertex*, int);  // to display the built tree. int is the level
  int  DFSminmax(Vertex*, int);  // to do MINMAX to decide the first move for MAX
                            // scores are being returned recursively
};


