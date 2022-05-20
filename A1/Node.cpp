/*
 * Name: Mirak Bumnanpol
 * Course: SENG1120
 * Student number: c3320409
 */
#include <cstdlib>
#include <iostream>
#include "Node.h"
using namespace std;

    Node::Node(const value_type& initialData, Node* initialNext, Node*initialPrevious)
    {
        data = initialData;           //Set default data
        next = initialNext;           //Set default next
        previous = initialPrevious;   //Set default previous
    }

    Node::~Node()
    {
        data = "";
        next = NULL;                 //Sets next pointer to NULL
        previous = NULL;             //Sets previous pointer to NULL
    }

    void Node::setData(const value_type& newData)
    {
        data = newData;                 //Assigns new data value
    }

    void Node::setNext(Node* newNext)
    {
        next = newNext;                 //Assigns value to the new next node
    }

    void Node::setPrevious(Node* newPrevious)
    {
        previous = newPrevious;         //Assigns value to the new previous node
    }

    Node::value_type Node::getData() const
    {
        return data;                    //Returns data variable
    }

    Node* Node::getNext() const
    {
        return next;                    //Returns next pointer constant
    }

    Node* Node::getPrevious() const
    {
        return previous;                //Returns previous pointer constant
    }
