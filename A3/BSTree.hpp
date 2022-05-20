/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
* File name: BSTree.hpp
*/

template <class value_type>
BSTree<value_type>::BSTree()
{
    root = NULL;        //Declaring the root is null
}

template <class value_type>
BSTree<value_type>::BSTree(const value_type& newData)
{
    add(newData);       //This allows new inputted data to be added to the BSTree
}

template <class value_type>
BSTree<value_type>::~BSTree()
{
    delete root;        //Deletes the root of the tree
    root = NULL;        //Sets the root node to null in order to not cause memory leaks
}

template <class value_type>
void BSTree<value_type>::add(const value_type& data)
{
    addData(data, root);    //Calls the recursive function to add the new data and its root node
}

template <class value_type>
void BSTree<value_type>::remove(const value_type& data)
{
    if(root == NULL)
    {
        cout << "Nothing in the tree" << endl;  //If the search for the selected data null then display this message
    }
    else
    {
        removeData(root, data);                 //Otherwise, call the recursive remove function to find and remove the selected data and its root node
    }
}

template <class value_type>
const string BSTree<value_type>::printTree() const
{
    stringstream data;  //Efficientally uses the stringstream to initialise the data
    printTreeOut(root); //Calls the recursive print function
    return data.str();
}

template <class value_type>
void BSTree<value_type>::addData(const value_type& newData, BTNode<value_type>* node)
{
    if(root==NULL)
    {
        root = new BTNode<value_type>(newData); //Creates an instance of BTNode if the tree is empty
    }
    else if((newData.compare(node->getData())) < 0) //Otherwise check to see if the data is less than the current data
    {
        if(node->getLeftChild() != NULL)            //If the left child is not null
        {
            addData(newData, node->getLeftChild()); //Calls the recursive add function to add new inputted data in the correct place
        }
        else    //If the left child is null
        {
            BTNode<value_type>* temp = new BTNode<value_type>(newData); //Creates a temp node and assigns it to the new inputted data
            temp -> setParent(node);    //Set the parent pointer to the temp node
            node -> setLeftChild(temp); //Sets the left child pointer to the current node
            temp = NULL;    //Sets the temp node as null
            delete temp;    //Deletes the temp node so there are no memory leaks
        }
    }
    else if((newData.compare(node->getData())) > 0) //Otherwise check to see if the data is more than the current data
    {
        if (node->getRightChild() != NULL)  //If the right child is not null
        {
            addData(newData, node->getRightChild()); //Calls the recursive add function to add new inputted data in the correct place
        }
        else //If the right child is null
        {
            BTNode<value_type>* temp = new BTNode<value_type>(newData); //Creates a temp node and assigns it to the new inputted data
            temp -> setParent(node); //Set the parent pointer to the temp node
            node -> setRightChild(temp); //Sets the right child pointer to the current node
            temp = NULL; //Sets the temp node as null
            delete temp; //Deletes the temp node so there are no memory leaks
        }
    }
    else //If there is duplicate data
    {
        node->setData(newData); //Assign current node to the current data and return the value
        return;
    }
}

template <class value_type>
void BSTree<value_type>::removeData(BTNode<value_type>* node, const value_type& newData)
{
    if(node == NULL)    //Checks to see if there is a current node in the tree and returns the value if there is
    {
        return;
    }
    int relation = newData.compare(node->getData());    //Stores an integer relation and compares the inputted data with the current node and data
    
    if(relation > 0)    //If the inputted data is greater to the current data
    {
        removeData(node->getRightChild(), newData); //Calls the recursive remove function to move the right child pointer
    }
    else if(relation < 0)   //If the inputted data is less than the current data
    {
        removeData(node->getLeftChild(), newData); //Calls the recursive remove function to move the left child pointer
    }
    else    //If there is a node
    {
        if(node->isALeaf()) //Checks to see if the node is a leaf in the tree
        {
            if((root->getData().compare(newData)) == 0)   //Compares the data and the root and checks to see if there are children
            {
                root = NULL;        //Sets the root as null if there is
            }
            else    //Else, if there are no children
            {
                if((node->getData().compare(node->getParent()->getData())) > 0) //Compares the data with the parent pointer and sees if it is greater than 0
                {
                    node->getParent()->setRightChild(NULL); //If it is then set the current node to the parent and then right child and set as null
                }
                else    //If the data is less than 0
                {
                    node->getParent()->setLeftChild(NULL);  //If it is then set the current node to the parent and then left child and set as null
                }
            }
            //Sets the left and right children pointers to null and then deletes the node in order to not create memory leaks
            node->setLeftChild(NULL);
            node->setRightChild(NULL);
            delete node;
        }
        
        //Else, if the node is not a leaf, checks to see if there is one child in the BSTree
        else if(node->oneChild())
        {
            if((root->getData().compare(newData)) == 0) //Compares the current root data to the new data and sees if it exists
            {
                if(node->getRightChild() != NULL)   //If it does, checks to see if the right child exists
                {
                    node->getRightChild()->setParent(node->getParent());    //Sets the right child pointer to its parent pointer
                }
                else    //If the data does not exist
                {
                    node->getLeftChild()->setParent(node->getParent()); //Set the left child pointer as its parent pointer
                }
            }
            else if(node->getRightChild() != NULL)  //Else, checks to see if the right child exists
            {
                node->getRightChild() -> setParent(node->getParent());  //Sets the right child pointer to its parent pointer
            
                if((node->getData().compare(node->getParent()->getData())) > 0) //Compares the current data with the parent pointer and checks to see if its greater than 0
                {
                    node->getParent()->setRightChild(node->getRightChild());    //Sets the parent pointer to the right child pointer
                }
                else    //If the data is less than 0
                {
                    node->getParent()->setLeftChild(node->getRightChild()); //Sets the parent pointer to the left child pointer
                }
            }
            else    //Else, if the right child does not exist
            {
                node->getLeftChild()->setParent(node->getParent()); //Sets the left child pointer to its parent pointer
                
                if((node->getData().compare(node->getParent()->getData())) > 0) //Compares the current data with the parent pointer and checks to see if its greater than 0
                {
                    node->getParent()->setRightChild(node->getLeftChild()); //Sets the parent pointer to the right child pointer and then sets the current node to the left child pointer
                }
                else //If the data is less than 0
                {
                    node->getParent()->setLeftChild(node->getLeftChild());  //Sets the parent pointer to the left child pointer
                }
            }
            //Sets the left and right children pointers to null and then deletes the node in order to not create memory leaks
            node->setLeftChild(NULL);
            node->setRightChild(NULL);
            delete node;
        }
        else    //If there are two children in the BSTree
        {
            BTNode<value_type>* temp = leftNode(node->getRightChild()); //Creates a temp node, calls the leftNode function which finds the furthest left node and assigns it to the right child pointer
            value_type* copyData = new value_type(temp->getData()); //Takes a copy of the data
            removeData(temp, temp->getData());  //Calls the recursive remove function to delete the temp node and its data
            node->setData(*copyData);   //Sets the new data as the copied data 
        }
    }
}

template <class value_type>
BTNode<value_type>* BSTree<value_type>::leftNode(BTNode<value_type>* node) const
{
    if(node->getLeftChild() != NULL)    //Searches to see if the left child pointer exists
    {
        return leftNode(node->getLeftChild());  //Returns the current data for the left child
    }
    else
    {
        return node;                            //Else, return the current data for the node
    }
}

template <class value_type>
void BSTree<value_type>::printTreeOut(BTNode<value_type>* node) const 
{
    if(node)    //If there is an instance of a node in the BSTree
    {
        printTreeOut(node->getLeftChild());     //Point the current node to the left child and print
        std::cout << node->getData() << " ";    //Storing the current node
        printTreeOut(node->getRightChild());    //Point the current node to the right child and print
    }
    else
    {
        return;                                 //If there is no node (which wouldnt happen since all the data has been added) then                                         return the current node
    }
}

//Overloaded operator that calls the recursive overloaded operator from BTNode 
template <class value_type>
std::ostream& operator<< (std::ostream& out, BSTree<value_type>& passed)
{
    passed.printTree();
    return out;
}
