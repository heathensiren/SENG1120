/*
 * Name: Mirak Bumnanpol
 * Course: SENG1120
 * Student number: c3320409
 */

#include <cstdlib>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

    //Constructors
    LinkedList::LinkedList()
    {   //Setting all pointers to null
        head = NULL;
        tail = NULL;
        current = NULL;
        length = 0;
    }

    //Destructor
    LinkedList::~LinkedList()
    {
        while(head != NULL)                //Checks if head node is null and loops
        {
            Node* tempHead = head;         //Creates a new temp pointer and setting it to the head
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

    void LinkedList::addToHead()
    {
        if(length == 0)                  //Making sure that there are no nodes within the linked list
        {
            head = new Node();           //Creating a new node that is the head node
            tail = head;                 //Assigning the tail pointer to the head node
            current = tail;              //Assigning the current pointer to the head node
            length = 1;                  //Setting the length of the linked list to 1
        }

        else
        {
            Node* newHead = new Node();     //Creating a new node
            head -> setNext(newHead);       //Setting the next node of the current head to the new node
            newHead -> setPrevious(head);   //Setting the previous node of the current head to the new node
            head = newHead;                 //Set the head node as the new node
            newHead = NULL;                 //Setting newhead to null
            length++;                       //Adds one to the length of the linked list
        }
    }

    void LinkedList::addToTail(const value_type& data)
    {
        if(length == 0)                   //Making sure that there are no nodes within the linked list
        {
            tail = new Node(data);        //Creating a new node that is the tail node
            head = tail;                  //Assigning the head pointer to the tail node
            current = head;               //Assigning the current pointer to the tail node
            length = 1;                   //Setting the length of the linked list to 1
        }

        else
        {
            Node* newTail = new Node(data);     //Creating a new node
            tail -> setNext(newTail);           //Setting the next node of the current tail to the new node
            newTail -> setPrevious(tail);       //Setting the previous node of the current tail to the new node
            tail = newTail;                     //Set the tail node as the new node
            newTail = NULL;                     //Setting new tail as null
            length++;                           //Adds one to the length of the linked list
        }
    }

    void LinkedList::moveToHead()
    {
        current = head;                 //The current pointer is now the head pointer
    }

    void LinkedList::setCurrent(Node* newCurrent)
    {
        current = newCurrent;           // Assigns new value to the current node
    }

    Node* LinkedList::getHead() const
    {
        return head;                    //Returns the head node
    }

    Node* LinkedList::getTail() const
    {
        return tail;                    //Returns the tail node
    }

    Node* LinkedList::getCurrent() const
    {
        return current;                 //Returns data of current node
    }

    void LinkedList::forward()
    {
        current = current->getNext();   //Moving the pointer to the next node
    }


    void LinkedList::add(const value_type& sentence)
    {
        value_type word;    //Holds new words in the linked list
        int start = 0;      //This is the variable for the start of each word in the linked list
        int place = 0;      //This is the variable for the place of each word in the linked list
        int wordLength = 0; //This is the variable for the length of the each word
        int endOfSentence = sentence.length(); //Variable for length of sentence 
            while (place != (endOfSentence + 1))    //Checks if the place isn't equal to the sentence length plus one. This is to make sure that all of the words are included in the sentence
            {
                if (sentence[place] == ' ' || place == endOfSentence)   //Checks for the spaces between the words or if the places of the words are equal to the sentence length
                {
                    addToTail(sentence.substr(start, wordLength));  //Adds the rest of the words to the tail in order
                    start = place + 1; //Sets the start variable as the place variable plus one so that all words in the node are included in the linked list
                    wordLength =  - 1; //This makes sure that the spaces between the nodes are even
                }
                place++;        //Increases the place by one
                wordLength++;   //Increases the wordlength by one
            }
    }

    void LinkedList::remove(const value_type& sentence)
    {
        moveToHead();           //Moves the current pointer to the head
        while (current != NULL) //Checks if current pointer is not null and loops
        {
            if(sentence == current -> getData() && current == head) //Checks if current node matches to given data and also checks if current pointer is the head pointer
            {
                Node* tempHead = head;          //Creates a temp node and assigning it to the head
                head = tempHead -> getNext();   //Moving head pointer to the next node
                head -> setPrevious(NULL);      //Setting the previous head pointer to null
                tempHead -> setPrevious(NULL);  //Setting the next pointer assigned to the temphead node as null
                tempHead -> setNext(NULL);      //Setting the previous pointer assigned to the temphead as null
                delete tempHead;                //Deletes the temphead Node
                length--;                       //Decreases the list length by one
                current = head;                 //Current pointer is now the head pointer
            }
            
            else if (sentence == current -> getData() && current == tail)
            {
                Node* tempTail = tail;              //Creates a temp node and assigns it to the tail
                tail = tempTail -> getPrevious();   //Moving the tail pointer to the previous node
                if(tail != NULL)                    //Checks to see if the tail pointer is null
                {
                    tail -> setNext(NULL);          //Sets the tail pointer to the next node
                }
                
                else
                {
                    head = NULL;                    //Setting the head pointer to null
                }
                delete tempTail;                    //Deletes the tempTail node
                length--;                           //Decreases the list length by one
                current = NULL;                     //Setting the current pointer to null
            }
            
            else if (sentence == current -> getData())
            {
                Node* tempCurrent = current;    //Creates a temp node and assigns it to current
                forward();
                current -> setPrevious(tempCurrent -> getPrevious());   //Previous node of the current pointer is now the previous node of the tempCurrent pointer
                tempCurrent -> getPrevious() -> setNext(current);       //Gets the previous node of the tempCurrent pointer and sets it to the next node
                tempCurrent -> setPrevious(NULL);//Setting the next pointer assigned to tempCurrent as null
                tempCurrent -> setNext(NULL);    //Setting the previous pointer assigned to tempCurrent as null
                delete tempCurrent;              //Deletes the tempCurrent node
                length--;                        //Decreases the list length by one
                forward();                       //Moves the current pointer to the next node
            }
            
            else
            {
                forward();                      //Moves the current pointer to the next node
            }
        }
    }

    int LinkedList::count(const string word)
    {
        int count = 0;                          //Initialises count to 0
        moveToHead();                           //Moving the current pointer to the head
        while (current != NULL)                 //Checks if the current pointer is null
        {
            if (word == current -> getData())   //Checks if the current pointer matches with the given data
            {
                count++;                        //Increases count by one
            }
            forward();                          //Moves the current pointer to the next node
        }
        return count;                           //Returning count
    }

    void LinkedList::operator+=(LinkedList& list)
    {
        list.moveToHead();                          //Moving the RHS to the head
        while (list.getCurrent() != NULL)           //Making sure that the current pointer is NULL
        {
            addToTail(list.current -> getData());   //Adding the RHS node to the LHS node
            list.forward();                         //Moving the current pointer to the next node
        }
    }

    ostream& operator << (ostream& stream, LinkedList& list)
    {
        list.moveToHead();                                      //Moving the RHS to the head
        while (list.getCurrent() != NULL)                       //Making sure that the current pointer is NULL
        {
            stream << list.getCurrent() -> getData() << ' ';    //Receives data from the current node
            list.forward();                                     //Moving the current pointer to the next node
        }
        return stream;                                          //Returns the stream
    }
