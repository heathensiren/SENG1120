/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
*/

#include <cstdlib>
#include "Node.h"

template <class value_type>
    Node<value_type>::Node(const value_type& initialData)
    {
        data = initialData;           //Set default data
        next = NULL;                  //Set to NULL
        previous = NULL;              //Set to NULL
    }

    template <class value_type>
    Node<value_type>::~Node()
    {
        data = "";
        next = NULL;                 //Sets next pointer to NULL
        previous = NULL;             //Sets previous pointer to NULL
    }
    
    template <class value_type>
    void Node<value_type>::setData(const value_type& newData)
    {
        data = newData;                 //Assigns new data value
    }

    template <class value_type>
    void Node<value_type>::setNext(Node* newNext)
    {
        next = newNext;                 //Assigns value to the new next node
    }

    template <class value_type>
    void Node<value_type>::setPrevious(Node* newPrevious)
    {
        previous = newPrevious;         //Assigns value to the new previous node
    }

    template <class value_type>
    const value_type Node<value_type>::getData() const
    {
        return data;                    //Returns data variable
    }
    
    template <class value_type>
    Node<value_type>* Node<value_type>::getNext() const
    {
        return next;                    //Returns next pointer constant
    }

    template <class value_type>
    Node<value_type>* Node<value_type>::getPrevious() const
    {
        return previous;                //Returns previous pointer constant
    }
