#include "mmbt.h"
#include <math.h>
#include <iostream>
using namespace std;

// ======== Utility Functions for Min Max ==============

//to compare two state values
int maxof(int A, int B)
{ if (A>B) return A;
  else return B;
}

// to compare two state values
int minof(int A, int B)
{ if (A<B) return A;
  else return B;
}

// We need to know even level or not to determine whether
// it is for MAX or MIN where MAX is even
bool iseven(int L)
{ if ( (L%2) == 0)
     return true; else return false; } 


// indents L amount to show level changes in display (L is level#)
void indent(int L)
{ for (int i = 1; i <= L; i++)
    cout << " ";
}

//===== Public Functions ===============

// constructor  initializes Root and Bottom
MMBT::MMBT()
{
   Root = NULL;   // This is an empty tree
   cout << "Bottom Level is? " ; cin >> Bottom;
}

// destructor must completely destroy the tree
MMBT::~MMBT()
{
   dtraverse(Root); // traverse to delete all vertices in post order
   Root = NULL;
}

// traverse the MM tree in depth first for 3 different reasons
void MMBT::Traverse(int mode)
{
  string P = "-"; // opeator path begins with -

  // pass -1 as the level built/processed so far
  if (mode == 1)  // to build the tree and assign scores to leaves 
    { Root = new Vertex; 
      DFSbuild(Root, 0, P); }
  if (mode == 2)  // to display the tree
      DFSdisplay(Root, 0); 
  if (mode == 3)  // to do MIMMAX
    {
      DFSminmax(Root, 0); 
      cout << "Root Value is: "<< Root->Value << endl;     
      cout << "You can make a move now to ";
      if (Root->Left->Value == Root->Value) 
           cout << "the left" << endl;
      else cout << "the right" << endl; }
}//end
// 2 - 9 2 -1 3
// traverse depth first to build the tree and assign values to leaves
// Vertex V is to be added, L is the level#, Path is the path to V
void MMBT::DFSbuild(Vertex *V, int L, string Path)
{ 
  // V is at level L
  //int inputScore;
  //* // store the operator Path so far in V->Elem
  string Elem = Path;
  V->Elem = Elem;

  indent(L);

  // **  // display the Path to show what node we are at
  cout << "Visited: " << Elem << endl;

    // when reaching the bottom, we need to get scores from the user
  if (L == Bottom)
	  { // at bottom level 
            int inputScore;
            // ** // display the level
            indent(L);
            cout << " Bottom Level: " << Bottom << " for ";
            // ** // display whether it is for MIN or MAX
            if(iseven(L)){
              cout << "MAX\n";
            }else{
              cout << "MIN\n";
            }
            // ** // ask the user to enter the score/value
            indent(L);
            cout << " Score for this leaf: " ; cin >> inputScore;
            V->Value = inputScore;
            return;}
	else // not a leaf so need to go down
	  {
            //Vertex *leftNode = new Vertex;
            //Vertex *rightNode = new Vertex;
            //**  // V->Left node should be created
            V->Left = new Vertex;
            //**  // V->Right node should be created
            V->Right = new Vertex;
	    // **  // recursively down to left with its level and path to it
            DFSbuild(V->Left, L + 1, Path + "L");
	    // **  // recursively down to right with its level and path to it
            DFSbuild(V->Right, L + 1, Path + "R");
                // do not do L++.  L+1 is the level for the children
          }   
}// end

// traverse depth first to show initial MM tree with paths and leaf values
void MMBT::DFSdisplay(Vertex *V, int L)
{   
  // V is at level L
  indent(L);
  // **  // display the level and operator path that is in the node 
  if (L == Bottom){
    cout << " Bottom Level: " << Bottom << " " << V->Elem;
  }  else{
    cout << " Level: " << L << " " << V->Elem << endl;
  }

  if (L == Bottom)
      cout << " with value " << V->Value << endl;
  else{ // go down to the next level
      // **  // recursively down to left with its level (L+1) to display
      DFSdisplay(V->Left, L + 1);
      // **  // recursively down to right with its level (L+1) to display
      DFSdisplay(V->Right, L + 1);
      }
}//end


// traverse depth first to do MM to assign values to internal nodes 
int MMBT::DFSminmax(Vertex *V, int L)
{
    // V is at level L
    int VL, VR; // child values

    if (L != Bottom) // for an internal node
    {
        // recursively get the left value and assign it to VL
        VL = DFSminmax(V->Left, L + 1);
        // recursively get the right value and assign it to VR
        VR = DFSminmax(V->Right, L + 1);

        // Figure out V's value based on VL and VR
            // but it depends on whether you are at MAX or MIN
         // Display the level, MAX or MIN, operator path and value
       // so that the user can see how MINMAX is working
        V->Value = (iseven(L)) ? maxof(VL, VR) : minof(VL, VR);

        // Display the level, MAX or MIN, operator path, and value
        cout << "Level: " << L << " for " << (iseven(L) ? "MAX" : "MIN") << ", " << V->Elem << " with " << V->Value << endl;

        return V->Value;
    }
    return V->Value; // leaf is reached
}

// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:  pointer to the vertex to be deleted
void MMBT::dtraverse(Vertex *V)  // post order traversal
{
  if (V != NULL)
    {
      dtraverse(V->Left);         // visit left sub tree of V
      dtraverse(V->Right);       // visit right sub tree of V
      delete V;                  // deletes V
    }
}//end