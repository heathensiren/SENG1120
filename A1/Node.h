/*
 * Name: Mirak Bumnanpol
 * Course: SENG1120
 * Student number: c3320409
 */
#ifndef MB_Node
#define MB_Node
#include <cstdlib>
#include <iostream>
using namespace std;

    class Node
    {
        public:
            //Typedef statements. Defining type string as value_type
            typedef string value_type;
            //Constructor 
            Node(const value_type& initialData = value_type(), Node* initialNext = NULL, Node* initialPrevious = NULL);

            //Destructor
            ~Node();

            /*
            * Mutator for Set data
            * Precondition:    Valid input is given
            * Postcondition:   Data has a value
            */
            void setData(const value_type& newData);

            /*
            * Mutator for Set next
            * Precondition:    Valid input is given
            * Postcondition:   Next pointer is given a value
            */
            void setNext(Node* newNext);

            /*
            * Mutator for Set previous
            * Precondition:    Valid input is given
            * Postcondition:   Previous pointer is given a value
            */
            void setPrevious(Node* newPrevious);

            /*
            * Accessor for Get data
            * Precondition:    Valid valid within variable data
            * Postcondition:   Value of variable data is returned
            */
            value_type getData() const;

            /*
            * Mutator for Get next
            * Precondition:    Next node is holding a valid pointer
            * Postcondition:   Next pointer is returned
            */
            Node* getNext() const;

            /*
            * Mutator for Get previous
            * Precondition:    Previous node is holding a valid pointer
            * Postcondition:   Previous pointer is retruned
            */
            Node* getPrevious() const;
        
        private:
            value_type data; //Variable to store card information
            Node* next;      //Variable to store next Node address
            Node* previous;  //Variable to store previous Node address

    };

#endif
