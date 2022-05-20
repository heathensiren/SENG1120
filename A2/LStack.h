/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
*/

#ifndef MB_LStack
#define MB_LStack

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include "LinkedList.h"

template <class value_type>
class LStack
{
    public:
    //Constructors
    LStack();                           //Accepts no arguments
    
    //Destructor 
    ~LStack();
    
    /*
     * Member function:
     * Precondition:
     * Postcondition:
     */
    void push(const value_type& data);
    
    /*
     * Member function:
     * Precondition:
     * Postcondition:
     */
    const value_type pop();
    
    /*
     * Member function:
     * Precondition:
     * Postcondition:
     */
    const value_type top() const;
    
    /*
     * Member function:
     * Precondition:
     * Postcondition:
     */
    const int size() const;
    
    /*
     * Member function:
     * Precondition:
     * Postcondition:
     */
    const bool isStackEmpty() const;
    
    private:
    LinkedList<value_type> stack;
};

//Operator overloading
template <class value_type>
ostream& operator << (ostream& out, LStack<value_type>& stack);

#include "LStack.hpp"
#endif 
