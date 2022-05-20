/*
* Name: Mirak Bumnanpol
* Course: SENG1120
* Student number: c3320409
*/

#include <cstdlib>
#include "Node.h"
using namespace std;

    //Constructors
    template <class value_type>
    LinkedList<value_type>::LinkedList()
    {   //Setting all pointers to null
        head = NULL;
        tail = NULL;
        current = NULL;
        length = 0;
    }

    //Destructor
    template <class value_type>
    LinkedList<value_type>::~LinkedList()
    {
        while(head != NULL)                //Checks if head node is null and loops
        {
            Node<value_type>* tempHead = head;         //Creates a new temp pointer and setting it to the head
            head = head -> getNext();
            if (head != NULL)              //Checks to see if head node isn't null
            {
                head -> setPrevious(NULL); //Setting head node to the previous pointer
            }
            
            else
            {
                tail = NULL;               //Sets the tail to null if the head node is empty
            }
            
            delete tempHead;               //Deletes the temp node
            current = head;
        }
        length = 0;                        //Setting the length to 0 and therefore empty
    }

    template <class value_type>
    void LinkedList<value_type>::addToHead(const value_type& data)
    {
        if(length == 0)                  //Making sure that there are no nodes within the linked list
        {
            head = new Node<value_type>(data);           //Creating a new node that is the head node
            tail = head;                 //Assigning the tail pointer to the head node
            current = tail;              //Assigning the current pointer to the head node
            length = 1;                  //Setting the length of the linked list to 1
        }

        else
        {
            Node<value_type>* newhead = new Node<value_type>(data);     //Creating a new node
            head -> setNext(newhead);       //Setting the next node of the current head to the new node
            newhead -> setPrevious(head);   //Setting the previous node of the current head to the new node
            head = newhead;                 //Set the head node as the new node
            newhead = NULL;                 //Setting newhead to null
            length++;                       //Adds one to the length of the linked list
        }
    }

    template <class value_type>
    void LinkedList<value_type>::addToTail(const value_type& data)
    {
        if(length == 0)                   //Making sure that there are no nodes within the linked list
        {
            tail = new Node<value_type>(data);        //Creating a new node that is the tail node
            head = tail;                  //Assigning the head pointer to the tail node
            current = head;               //Assigning the current pointer to the tail node
            length = 1;                   //Setting the length of the linked list to 1
        }

        else
        {
            Node<value_type>* newtail = new Node<value_type>(data);     //Creating a new node
            tail -> setNext(newtail);           //Setting the next node of the current tail to the new node
            newtail -> setPrevious(tail);       //Setting the previous node of the current tail to the new node
            tail = newtail;                     //Set the tail node as the new node
            newtail = NULL;                     //Setting new tail as null
            length++;                           //Adds one to the length of the linked list
        }
    }
    
    template <class value_type>
    void LinkedList<value_type>::moveToHead()
    {
        current = head;                 //The current pointer is now the head pointer
    }

    template <class value_type>
    const value_type LinkedList<value_type>::getData() const
    {
        return current->getData();
    }

    template <class value_type>
    void LinkedList<value_type>::forward()
    {
        current = current->getNext();   //Moving the pointer to the next node
    }

    template <class value_type>
    void LinkedList<value_type>::back()
    {
        current = current->getPrevious();   //Moving the pointer to the next node
    }

    template <class value_type>
    void LinkedList<value_type>::removeFromHead()
    {
        Node<value_type>* tempHead = head;  //Creates a temp node and assigns it to the head
        head = head -> getNext();
        if (head != NULL)
        {
            head -> setPrevious(NULL);
        }
        
        else
        {
            tail = NULL;
        }
        
        delete tempHead;
        length--;
        moveToHead();
    }

    template <class value_type>
    void LinkedList<value_type>::removeFromTail()
     {
         Node<value_type>* tempTail = tail;  //Creates a temp node and assigns it to the head
         tail = tail -> getPrevious();
         if (tail != NULL)
         {
             tail -> setNext(NULL);
         }
         
         else
         {
             head = NULL;
         }
         
         delete tempTail;
         length--;
         moveToHead();
     }

    template <class value_type>
    const string LinkedList<value_type>::print()
    {
        string output = string();
        const Node<value_type>* tempNode = head;
        while(tempNode!=NULL)
        {
            output.append(tempNode->getData());
            output.append(" ");
            tempNode = tempNode->getNext();
        }
        
        tempNode = NULL;
        return output;
    }

    template <class value_type>
    const int LinkedList<value_type>::getSize() const
    {
        return length;
    }

    template <class value_type>
    ostream& operator << (ostream& stream, LinkedList<value_type>& list)
    {
        stream << list.print();
        return stream;
    }
