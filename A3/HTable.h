/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
* File name: HTable.h
*/

#ifndef MB_HTable
#define MB_HTable

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

//Setting template
template <class value_type>

class HTable
{
    public:
    
    //Constructors
    HTable();
    
    HTable(const value_type& data);
    
    //Destuctors
    ~HTable();
    
    /*
    * Purpose: This allows data to be added to the Hash Table
    * Precondition: Data is valid and exists
    * Postcondition: Data is added onto the hash table
    */
    void add(const value_type& addData);
    
    /*
    * Purpose: This allows data to be removed from the Hash Table
    * Precondition: Data is valid and exists
    * Postcondition: Searches and removes the selected data from the Hash Table
    */
    void remove(const value_type& removeData);
    
    /*
    * Purpose: Prints the inputted data from the Hash Table
    * Precondition: Data is valid and exists
    * Postcondition: Data is printed as a string
    */
    const string printHash() const;
    
    private:
    static const int size = 150;    //Size of the ASCII
    value_type hash[size];          //Stores the ASCII
    
    /* Helper function
    * Purpose: This allows for data to be placed correctly on the Hash Table
    * Precondition: Data is valid and exists
    * Postcondition: Data is placed and printed correctly 
    */
    const int hashfun(const value_type& newData) const;
};

    //Overloaded operator
    template <class value_type>
    ostream& operator << (ostream& out, HTable<value_type> table);

#include "HTable.hpp"
#endif
