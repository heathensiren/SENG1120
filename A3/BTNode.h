/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
* File Name: BTNode.h
*/

#ifndef MB_BTNode
#define MB_BTNode

#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

//Setting template
template <class value_type>

class BTNode
{
    public:
    
    //Constructors
    BTNode();
    
    BTNode(const value_type& newData);
    
    //Destructor
    ~BTNode();
    
                                                        //SETTERS
    
    /*
    * Mutator for Set data in BTNode
    * Precondition: Valid input is given
    * Postcondition: Data has a value
    */
    void setData(const value_type& newData);
    
    /*
    * Mutator for setting parent pointer in BTNode
    * Precondition: Valid input is given
    * Postcondition: Parent pointer is set to the parent node
    */
    void setParent(BTNode<value_type>* parentNode);
    
    /*
    * Mutator for setting left pointer in BTNode
    * Precondition: Valid input is given
    * Postcondition: Set left pointer to left child
    */
    void setLeftChild(BTNode<value_type>* newLeftChild);
    
    /*
    * Mutator for setting right pointer in BTNode
    * Precondition: Valid input is given
    * Postcondition: Set right pointer to right child
    */
    void setRightChild(BTNode<value_type>* newRightChild);
    
    
                                                        //GETTERS
    
    /* Returns a reference to the data in BTNode
    * Precondition: Node has been constructed
    * Postcondition: A reference to the data in BTNode is returned
    */
    value_type& getData();
    
    /* Const version of getData
    * Precondition: Node has been constructed
    * Postcondition: A reference to the const data in BTNode is returned
    */
    const value_type getData() const;
    
    /* Returns the parent node
    * Precondition: Node has been constructed
    * Postcondition: Parent node is returned to BTNode
    */
    BTNode<value_type>* getParent();
    
    /* Const version of getParent
    * Precondition: Node has been constructed
    * Postcondition: Parent node is returned as a const
    */
    const BTNode<value_type>* getParent() const;
    
    /* Return the left child node
    * Precondition: Node has been constructed
    * Postcondition: Left child node is returned to BTNode
    */
    BTNode<value_type>* getLeftChild();
    
    /* Const version of getLeftChild
    * Precondition: Node has been constructed
    * Postcondition: Left child node is returned as a const
    */
    const BTNode<value_type>* getLeftChild() const;
    
    /* Return the right child node
    * Precondition: Node has been constructed
    * Postcondition: Right child node is returned to BTNode
    */
    BTNode<value_type>* getRightChild();
    
    /* Const version of getRightChild
    * Precondition: Node has been constructed
    * Postcondition: Right child node is returned as a const
    */
    const BTNode<value_type>* getRightChild() const;
    
    
                                                        //CHECKING
    
    /* Checking to see if BTNode is a leaf
    * Precondition: BTNode has been constructed
    * Postcondition: True or false answer
    */
    const bool isALeaf() const;
    
    /* Checking to see if BTNode has one child
    * Precondition: BTNode has been constructed
    * Postcondition: True or false answer
    */
    const bool oneChild() const;
        
    private:
    
    BTNode<value_type>* parent;         //This variable points to the parent of BTNode
    BTNode<value_type>* leftChild;      //This variable points to the left child of BTNode
    BTNode<value_type>* rightChild;     //This variable points to the right child of BTNode
    value_type data;                    //This variable holds the data of BTNode
};

//Overloaded operator 
template <class value_type>
std::ostream& operator<< (std::ostream& out, BTNode<value_type>& passed);

#include "BTNode.hpp"

#endif 
