 /*
  * Name: Mirak Bumnanpol
  * Course: SENG1120
  * Student number: c3320409
  */

#ifndef MB_Linkedlist
#define MB_Linkedlist
 
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

template <class value_type>
class LinkedList
{
    public:
        //Constructors
        LinkedList();                             //Accepts no arguments

        //Destructors
        ~LinkedList();
    
        //Member functions list

        /*
         * Member function: Adds a new node with input data at head of the list
         * Precondition:    A valid input was put in and list is now initiated
         * Postcondition:   A new node at the start which is at the head
         */
         void addToHead (const value_type& data);

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
         * Member function: Returns the head node
         * Precondition:    Value is set as valid
         * Postcondition:   Return head
         */
         const value_type getData() const;

         /*
         * Member function:  Moves current node forward
         * Precondition:     Has a valid pointer to current node
         * Postcondition:    Moves current node forward one
         */
         void forward();
    
         /*
         * Member function:  Moves current node back
         * Precondition:     Has a valid pointer to current node
         * Postcondition:    Moves current node back one
         */
         void back();
         
         /*
         * Member function:  This removes the head node from the linked list
         * Precondition:     Has a valid pointer
         * Postcondition:    Removes the head node from the linked list
         */
         void removeFromHead();
    
         /*
         * Member function:  This removes the tail node from the linked list
         * Precondition:     Has a valid pointer
         * Postcondition:    Removes the tail node from the linked list
         */
         void removeFromTail();
        
         //Returns a string variable of the linked list
         const string print();
    
         //Shows the size of the linked list 
         const int getSize() const;

    private:
        Node<value_type>* head;                 //Pointer variable for head
        Node<value_type>* tail;                 //Pointer variable for tail
        Node<value_type>* current;              //Pointer variable for current
        int length;                             //Variable to store length of linkedlist
};
    //Operator overloading
    template <class value_type>
    ostream& operator << (ostream& out, LinkedList<value_type>& list);

#include "LinkedList.hpp"
#endif
