/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
* File name: BSTree.h
*/

#ifndef MB_BSTree
#define MB_BSTree

#include "BTNode.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

template <class value_type>
class BSTree
{
    public:
    
    //Constructors
    BSTree();
    
    BSTree(const value_type& newData);
    
    //Destructor
    ~BSTree();
    
    /*
    * Purpose: This adds data to the BSTree
    * Precondition: Data is valid and exists
    * Postcondition: The data is added
    */
    void add(const value_type& data);
    
    /*
    * Purpose: This removes data from the BSTree
    * Precondition: Data is valid and exists
    * Postcondition: Searches and removes selected data from the BSTree
    */
    void remove(const value_type& data);
    
    /*
    * Purpose: Prints the inputted data
    * Precondition: Data is valid and exists
    * Postcondition: Data from the BSTree is printed as a string
    */
    const string printTree() const;
    
    private:
    BTNode<value_type>* root;   //This variable points to the root of the tree
    
    void addData(const value_type& newData, BTNode<value_type>* node);  //This is a recursive function to add data to the BSTree
    
    void removeData(BTNode<value_type>* node, const value_type& newData);   //This is a recursive function to search and remove data from the BSTree
    
    BTNode<value_type>* leftNode(BTNode<value_type>* node) const;   //This finds the left node in BSTree and returns the value. Done in order to add or remove the left node from the tree as asked in the demo
    
    void printTreeOut(BTNode<value_type>* node) const;  //This is a recursive function to help print inputted data from the BSTree
};

//Overloaded operator
template <class value_type>
std::ostream& operator << (std::ostream& out, BSTree<value_type>& passed);

#include "BSTree.hpp"
#endif
