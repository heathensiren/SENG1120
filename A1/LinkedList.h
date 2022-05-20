/*
 * Name: Mirak Bumnanpol
 * Course: SENG1120
 * Student number: c3320409
 */

#ifndef MB_Linkedlist
#define MB_Linkedlist

#include <cstdlib>
#include "Node.h"
using namespace std;

class LinkedList
{
    public:
    typedef Node::value_type value_type;          //Typedef statements. Defining type string as value_type

        //Constructors
        LinkedList();                             //Accepts no arguments

        //Destructors
        ~LinkedList();

        /*
        * Member function: Adds a new node with input data at head of the list
        * Precondition:    A valid input was put in and list is now initiated
        * Postcondition:   A new node at the start which is at the head
        */
        void addToHead ();

        /*
         * Member function: Adds a new node with input data at tail of the list
         * Precondition:    A valid input was put in and list is now initiated
         * Postcondition:   A new node at the end which is at the tail
         */
        void addToTail(const value_type& data);
    
        /*
        * Member function: Moves the node to the start of the list
        * Precondition:    A valid input is given
        * Postcondition:   The node is moved to the start of the list
        */
        void moveToHead();

        /*
        * Member function: Sets the current node
        * Precondition:    Value is valid
        * Postcondition:   The given node is set as the current node
        */
        void setCurrent(Node* newCurrent);

        /*
        * Member function: Returns the head node
        * Precondition:    Value is set as valid
        * Postcondition:   Return head
        */
        Node* getHead() const;

        /*
        * Member function: Returns the tail node
        * Precondition:    Value is valid
        * Postcondition:   Return tail
        */
        Node* getTail() const;

        /*
        * Member function: Retrieves the current node
        * Precondition:    Valid pointer
        * Postcondition:   Returns current node
        */
        Node* getCurrent() const;

        /*
        * Member function:  Moves current node forward
        * Precondition:     Has a valid pointer to current node
        * Postcondition:    Moves current node forward one
        */
        void forward();
        
        /*
        * Member function:  This adds all nodes to the linked list
        * Precondition:     Has a valid pointer
        * Postcondition:    Adds all nodes to the linked list
        */
        void add(const value_type& sentence);

        /*
        * Member function:  This removes specific nodes from the linked list
        * Precondition:     Has a valid pointer
        * Postcondition:    Removes the specific node from the linked list
        */
        void remove(const value_type& sentence);
    
        /*
        * Member function:  This counts the number of a specific node
        * Precondition:     None
        * Postcondition:    The number of nodes matches with the number in the linked list
        */
        int count(const string word);

        /*
        * Member function:  This adds nodes from the RHS onto the LHS
        * Precondition:     Value is valid
        * Postcondition:    Nodes from the RHS is added onto the LHS
        */
        void operator += (LinkedList& list);

    private:
        Node* head;                             //Pointer variable for head
        Node* tail;                             //Pointer variable for tail
        Node* current;                          //Pointer variable for current
        int length;                             //Variable to store length of linkedlist
};
    //Operator overloading
    ostream& operator << (ostream& out, LinkedList& list);

#endif
