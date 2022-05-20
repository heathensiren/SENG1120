/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
* File name: BTNode.hpp
*/

//Constructor
template <class value_type>
BTNode<value_type>::BTNode()
{
    data = value_type();    //Initialising value type
    leftChild = NULL;       //Setting leftChild pointer to NULL
    rightChild = NULL;      //Setting rightChild pointer to NULL
    parent = NULL;          //Setting parent pointer to null
}

//Constructor with data value
template <class value_type>
BTNode<value_type>::BTNode(const value_type& newData)
{
    data = newData;         //Initialising data to newData
    leftChild = NULL;       //Setting leftChild pointer to NULL
    rightChild = NULL;      //Setting rightChild pointer to NULL
    parent = NULL;          //Setting parent pointer to null
}

//Destructor
template <class value_type>
BTNode<value_type>::~BTNode()
{
    delete rightChild;      //Deleting the right child pointer
    delete leftChild;       //Deleting the left child pointer
    parent = NULL;          //Setting the parent pointer to null
}
                                                        //SETTERS

template <class value_type>
void BTNode<value_type>::setData(const value_type& newData)
{
    data = newData;             //Setting data as the parameter
}

template <class value_type>
void BTNode<value_type>::setParent(BTNode<value_type>* parentNode)
{
    parent = parentNode;        //Setting the parent pointer to the parameter
}

template <class value_type>
void BTNode<value_type>::setLeftChild(BTNode<value_type>* newLeftChild)
{
     leftChild = newLeftChild;  //Setting the left child pointer to the parameter
}

template <class value_type>
void BTNode<value_type>::setRightChild(BTNode<value_type>* newRightChild)
{
    rightChild = newRightChild; //Setting the right child pointer to the parameter
}
                                                        //GETTERS

template <class value_type>
value_type& BTNode<value_type>::getData()
{
    return data;    //Returning a reference to the data
}

template <class value_type>
const value_type BTNode<value_type>::getData() const
{
    return data;    //Returning a copy of the data
}

template <class value_type>
BTNode<value_type>* BTNode<value_type>::getParent()
{
    return parent;  //Returning the parent node
}

template <class value_type>
const BTNode<value_type>* BTNode<value_type>::getParent() const
{
    return parent;  //Returning the parent node as a const
}

template <class value_type>
BTNode<value_type>* BTNode<value_type>::getLeftChild()
{
    return leftChild;   //Returning the left child pointer
}

template <class value_type>
const BTNode<value_type>* BTNode<value_type>::getLeftChild() const
{
    return leftChild;   //Returning the left child pointer as a const
}

template <class value_type>
BTNode<value_type>* BTNode<value_type>::getRightChild()
{
    return rightChild;  //Returning the right child pointer
}

template <class value_type>
const BTNode<value_type>* BTNode<value_type>::getRightChild() const
{
    return rightChild;  //Returning the right child pointer as a const
}


                                                        //CHECKING
    
template <class value_type>
const bool BTNode<value_type>::isALeaf() const
{
    //If both children pointers are null, return true (the node is a leaf) else return false
    if(leftChild == NULL && rightChild == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class value_type>
const bool BTNode<value_type>::oneChild() const
{
    //If left and right child pointer are set to null and the other pointers are not set to null then there is one child so method returns true, else it returns false
    if((leftChild == NULL && rightChild != NULL) || (leftChild != NULL && rightChild == NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Overloaded recursive operator that gets called in BSTree in order to execute code without memory leaks 
template <class value_type>
std::ostream& operator<< (std::ostream& out, BTNode<value_type>& passed)
{
    out << *passed.getData();
    return out;
}
