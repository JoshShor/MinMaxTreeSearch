#include <iostream>
using namespace std;
#include "mmbt.h"

// Yoshii - MIN MAX client for a binary game tree with MAX at the root.
// DO NOT CHANGE!!

// I assume that the borrom level is flat
// Operator Path is the state description e.g. LLR
int main()
{
  cout << " ---------------------- " << endl;
  cout << " MINMAX client for a binary game tree with MAX at the root. " << endl;
  cout << " I assume that the borrom level is flat. " << endl;
  cout << " The Operator Path is the state description e.g. LLR " << endl;

  MMBT MyTree;  // my tree with Bottom being specified
  char a;  // user input to continue

  cout << endl;
  cout << "As a triangular tree is created using DFS," << endl;
  cout << " enter scores of leaves as prompted" << endl;
  MyTree.Traverse(1);


  cout << "Type any key to continue"; cin >> a;    

  cout << "Here is the initial tree shown in DFS..." << endl; 
  MyTree.Traverse(2);

  cout << "Type any key to continue"; cin >> a;    

  cout << "MinMax  being done..." << endl;
  MyTree.Traverse(3);

  cout << " ----------------------" << endl;
}
