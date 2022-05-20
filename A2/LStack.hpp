/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
*/
#include <iostream>
#include <cstdlib>
#include "LStack.h"
#include "Node.h"
#include "LinkedList.h"

using namespace std;

//Constructor
template <class value_type>
LStack<value_type>::LStack()
{

}

//Destructor
template <class value_type>
LStack<value_type>::~LStack()
{

}

template <class value_type>
void LStack<value_type>::push(const value_type& data)
{
    stack.addToHead(data);       //This adds a new node onto the stack
    stack.moveToHead();
}

template <class value_type>
const value_type LStack<value_type>::pop() 
{
    value_type data = stack.getData();
    stack.removeFromHead();
    return data;
}

template <class value_type>
const value_type LStack<value_type>::top() const
{
    return stack.getData();
}

template <class value_type>
const int LStack<value_type>::size() const
{
    return stack.getSize();
}

template <class value_type>
const bool LStack<value_type>::isStackEmpty() const
{
    return stack.getSize() == 0;
}

template <class value_type>
ostream& operator << (ostream& out, LStack<value_type>& stack)
{
    out <<stack.print();
    return out;
}//Look at this again
