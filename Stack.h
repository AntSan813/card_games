#ifndef _STACK_H
#define _STACK_H

#include "Node.h"
using namespace std;


template<class ItemType>
class Stack
{

protected:
        Node<ItemType> * topOfStackPtr ;
public:

   /*****************************************************
        METHOD:  Constructor
        ****************************************************/
       Stack();

   /*****************************************************
        METHOD:  isEMPTY
                Sees whether this stack is empty.
    RETURNS: True if the stack is empty, or false if not. 
        ****************************************************/
    bool isEmpty() ;

   /*****************************************************
        METHOD:  PUSH
                Adds a new entry to the top of this stack.
                If the operation was successful, 
                       newEntry is at the top of the stack.
                                   
        PARAMETER: newEntry The object to be added as a new entry.
        RETURNS: True if the addition is successful or false if not.
   ****************************************************/
    bool push(ItemType newEntry) ;


   /*****************************************************
        METHOD:  POP
                Removes the top of this stack.
                If the operation was successful, 
                  the top of the stack has been removed.
        
        PARAMETER: None
        RETURNS: The item removed from the stack
        ERROR RETURNED:  If the stack is empty an error is returned
                student: define the error you will return here
        ****************************************************/
    ItemType pop() ;

    ItemType peek();
};  // end Stack.h

template<typename ItemType>
Stack<ItemType>::Stack(){
        topOfStackPtr = NULL;

}

template<typename ItemType>
bool Stack<ItemType>::isEmpty(){
        if(topOfStackPtr == NULL)
                return true;
        else
                return false;
}

template<typename ItemType>
bool Stack<ItemType>::push(ItemType newEntry){
        Node<ItemType>* newitem = new Node<ItemType>(newEntry, topOfStackPtr);
        topOfStackPtr = newitem;
        return true;
}

template<typename ItemType>
ItemType Stack<ItemType>::pop(){
        Node<ItemType>* poppedItem;
        ItemType temp;
        if(topOfStackPtr == NULL)
                throw 99;
        else{
                poppedItem = topOfStackPtr;
                topOfStackPtr = poppedItem->getNext();
                temp = poppedItem->getItem();
                delete poppedItem;
                return temp;
        }
}
template<typename ItemType>
ItemType Stack<ItemType>::peek(){
        ItemType temp;
        if(topOfStackPtr == NULL)
                throw 99;
        else{
                return topOfStackPtr->getItem();
        }


}

#endif
