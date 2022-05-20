/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
* File name: HTable.hpp
*/

template <class value_type>
HTable<value_type>::HTable()
{
    for(int i=0; i<size; i++)
    {
        hash[i] = value_type(); //This creates an instance of HTable and assigns it a value_type
    }
}

template <class value_type>
HTable<value_type>::HTable(const value_type& newData)
{
    for(int i=0; i<size; i++)
    {
        hash[i] = value_type(); //This creates an instance of HTable and assigns it to a value_type
    }
    add(newData);               //Then it adds the data to the hash table
}

template <class value_type>
HTable<value_type>::~HTable()
{
    for(int i=0; i<size; i++)
    {
        hash[i] = " ";          //This searches for an empty space within the hash table and then removes the data
    }
}

template <class value_type>
void HTable<value_type>::add(const value_type& addData)
{
    int array = hashfun(addData);       //This correctly places the data in the hashtable
    if(hash[array] == value_type())
    {
        hash[array] = addData;          //Adds the inputted data into the hash table
    }
    else
    {
        cout << "There is already an item there" << endl;   //If there already is an object there, display this error message
    }
}

template <class value_type>
void HTable<value_type>::remove(const value_type& removeData)
{
    int array = hashfun(removeData);    //Correctly stores the data in the hash table
    if(hash[array] == value_type())     //Searches for the selected data to remove
    {
        return;                         //Returns the value
    }
    else
    {
        hash[array] = value_type();     //Replace the removed data with an empty value type
    }
}

template <class value_type>
const string HTable<value_type>::printHash() const
{
    stringstream data;                          //Initialising a stringstream as variable data. Makes output more efficient
    for(int i=0; i<size; i++)
    {
        if(hash[i] != value_type())
        {
            data << " " << hash[i] << " ";      //After checking to make sure that data is in the correct position, then adds the data to be printed
        }
    }
    return data.str();                          //Returning the data
}

template <class value_type>
const int HTable<value_type>::hashfun(const value_type& newData) const
{
    int result = newData.length();      //Initialises the new inputted data length
    int total = 0;                      //Stores the ASCII
    for(int i=0; i<result; i++)
    {
        total += (int)newData.at(i);    //ASCII is added to the hash table
    }
    return(total%size);                 //Returns the total divided by the size 
}

//Overloaded operator
template <class value_type>
ostream& operator << (ostream& out, HTable<value_type> table)
{
    out << table.printHash();
    return out;
}
