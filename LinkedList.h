// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include "Node.h"
using namespace std;

/******************************************************************
 Class LinkedList
 This class defines a data structure for a linked list of integers
*******************************************************************/   
template<typename obj>
class LinkedList 
{
  private:
   Node<obj>* headNodePtr;

  public:
   LinkedList ();
   bool isEmpty();
   void insertFront(obj);
   void insertRear(obj);
   int count();
   void printList();
   int  findPos(obj);
   obj retrieveAtPos(int);
   void clear();
   obj peek(int);   
   bool validAtPos(int);
   obj remove(int);
   // EXCEPTIONS THROWN

	static const int ItemNotFound = 8001;
	static const int NodeAtPositionNotFound = 8002;
};




/*=====================================================================
*     IMPLEMENTATION OF METHOD/FUNCTIONS
*=====================================================================

******************************************************************
 Class LinkedList
 Function:  Constructor
     Create am empty linked list
	 This is indicated by a null pointer in the start of list (headNodePtr)
 Return: a pointer to the constructed LinkedList object.
*******************************************************************/   
template<typename obj>
LinkedList<obj>::LinkedList() 
{
	headNodePtr = NULL;
}

 /******************************************************************
 Class LinkedList
 Function:  isEmpty
 Parameters: None
  Returns a bool that indicates if the linked list is or is not empty
*******************************************************************/   
template<typename obj>
bool LinkedList<obj>::isEmpty() 
   {
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   // Print each item on a new line
	if(headNodePtr == NULL)
		return true;
	else 
		return false;
}

/******************************************************************
 Class LinkedList
 Function:  insertFront
     Inserts a new item at the front of the list
	 This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/   
template<typename obj>
void LinkedList<obj>::insertFront(obj item)
{
	// The headNodePtr currently points to the first node in the list or NULL
	// Create the new node with the item given and point it to the same node (or NULL) as the head
 	 
	 //REPLACE THE LINE BELOW WITH YOUR OWN CODE
	Node<obj>* newNode = new Node<obj>(item, headNodePtr);		
	 
	// Set the head node pointer equal to the new node, now the first one in the list
      //REPLACE THE LINE BELOW WITH YOUR OWN CODE
	headNodePtr = newNode;	
   // Now the head node points to the new node and the new node points to the rest of the list. 
}

/******************************************************************
 Class LinkedList
 Function:  insertRear
     Inserts a new item at the end of the list
	 This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/   
template<typename obj>
void LinkedList<obj>::insertRear(obj item)
{
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
	Node<obj>* holderPtr;
	
	if(headNodePtr == NULL)
		headNodePtr = new Node<obj>(item);
	else{
		holderPtr = headNodePtr;
		while(holderPtr->getNext() != NULL){
			holderPtr = holderPtr->getNext();
		}
		holderPtr->setNext(new Node<obj>(item));
	}			

}

 /******************************************************************
 Class LinkedList
 Function:  count
 Parameters: None
  Returns an integer count of the number of items in the list
*******************************************************************/   
template<typename obj>
int LinkedList<obj>::count() 
   {
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   // Print each item on a new line
	Node<obj>* holderPtr;
	int counter = 1;
	holderPtr = headNodePtr;
	if(headNodePtr == NULL)
		return 0;
	else{
		while(holderPtr->getNext() != NULL){
			counter++;
			holderPtr = holderPtr->getNext();
		}
		return counter;
	}
}	


/******************************************************************
 Class LinkedList
 Function:  printList
    Walks through the list looking for a node at the position passed.
	The position starts counting at 1. That is the first node in the list
	is at position 1.
	If that node is found, it removes the node from the list 
	 and returns the value.
	 
	 If the node is not found, signal an  exception: NodeAtPositionNotFound
	 
 Parameters: item to find.
 Result:  Node with item is removed from the list.
 Return: item
*******************************************************************/ 
template<typename obj>
void LinkedList<obj>::printList () 
{
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   // Print each item on a new line
        Node<obj>* holderPtr;
        int counter = 1;
        holderPtr = headNodePtr;
        while(holderPtr != NULL){
                cout << "Card " << counter << ". " << holderPtr->getItem() << endl;
                holderPtr = holderPtr->getNext();
                counter++;
        }
}

/******************************************************************
 Class LinkedList
 Function:  findPos
    Walks through the list looking for a node at the position passed.
	The position starts counting at 1. That is the first node in the list
	is at position 1.
	If that node is found, it returns the position of that node in the list.
	 
	 If the node is not found, signal an  exception: itemNotFound
	 
 Parameters: Position in list.

 Return: item at that position
*******************************************************************/ 
template<typename obj>
int  LinkedList<obj>::findPos(obj item)
   {
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
/*	Node<int>* prevPtr;
	Node<int>* holderPtr = headNodePtr;
	int position = 1;
	while(item > holderPtr->getItem()){
		prevPtr = holderPtr;
		holderPtr = holderPtr->getNext();
		position++;
	}
	Node<int> newNode(item,holderPtr);
	prevPtr->setNext(&newNode);
	return position;
*/

	Node<obj>* holderPtr;
	holderPtr = headNodePtr;
	int position = 0;
	if(headNodePtr == NULL)
		return NodeAtPositionNotFound;
	else{
		while((holderPtr->getItem() != item )&& (holderPtr->getNext() != NULL)){
			holderPtr = holderPtr->getNext();
			position++;
		}
		if(holderPtr->getItem() == item)
			return position + 1;
		else
			return NodeAtPositionNotFound;
	}
}



/******************************************************************
 Class LinkedList
 Function:  retrieveAtPos
    Walks through the list looking for a node at the position passed.
	The position starts counting at 1. That is the first node in the list
	is at position 1.
	If that node is found, it removes the node from the list 
	 and returns the value.
	 
	 If the node is not found, signal an  exception: NodeAtPositionNotFound
	 
 Parameters: Position in list.

 Result:  Node with item is removed from the list.
 Return: item at that position
*******************************************************************/ 
template<typename obj>
obj LinkedList<obj>::retrieveAtPos (int pos)
{
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
	Node<obj>* holderPtr;
	obj returnItem;
	int i = 1;
	holderPtr = headNodePtr;
	while((i != pos) && (holderPtr->getNext() != NULL)){
	holderPtr = holderPtr->getNext();
		i++;
	}
	if(pos > i)
		throw ItemNotFound;

	else if(pos == i){
		returnItem = holderPtr->getItem();
		delete holderPtr;
		while(holderPtr->getNext() != NULL){
			holderPtr = holderPtr->getNext();
		}
		delete holderPtr;
		holderPtr = NULL;
		return returnItem;
	
	}	
	else 
		throw ItemNotFound;
}

template<typename obj>
obj LinkedList<obj>::peek(int x)
{
	Node<obj>* holderPtr;
	int i = 1;
	holderPtr = headNodePtr;
	if(isEmpty())
		throw ItemNotFound;
	else if(x == 1)
		return holderPtr->getItem();
	else if(x < 1)
		throw ItemNotFound;
	else if(x > count())
		throw ItemNotFound;
	else{
		while((i != x) && (holderPtr->getNext() != NULL)){
	     	        holderPtr = holderPtr->getNext();
        	        i++;
		}
		if(holderPtr == NULL)
			throw ItemNotFound;
		else
        	        return holderPtr->getItem();
	}
}
template<typename obj>
bool LinkedList<obj>::validAtPos(int x){
        Node<obj>* holderPtr;
       
        int i = 1;
        holderPtr = headNodePtr;		
        while((i != x) && (holderPtr->getNext() != NULL)){
        holderPtr = holderPtr->getNext();
                i++;
        }
	if(x > count())
		return false;
	else if(isEmpty())
		return false;
        else if(x == i)
                return true;

}

template<typename obj>
obj LinkedList<obj>::remove(int pos){
	Node<obj>* deletePtr;
	Node<obj>* prevPtr = NULL;
	obj returnObj;
	int counter = 1;
	if(pos == 1){
		if(headNodePtr == NULL)
			throw ItemNotFound;
		if(headNodePtr->getNext() == NULL){
			returnObj = headNodePtr->getItem();
			delete headNodePtr;
			headNodePtr = NULL;
			return returnObj;
			
		}
		else{
			deletePtr = headNodePtr;
			headNodePtr = headNodePtr->getNext();
			returnObj = deletePtr->getItem();
			delete deletePtr;
			return returnObj;
		}
	}
	else{
		prevPtr = headNodePtr;
		while((counter != pos-1) && (prevPtr->getNext() != NULL)){
			prevPtr = prevPtr->getNext();
			counter++;
		}
		if(prevPtr->getNext() == NULL)
			throw ItemNotFound;
		else{
			deletePtr = prevPtr->getNext();
			returnObj = prevPtr->getNext()->getItem();
			prevPtr->setNext(deletePtr->getNext());
			delete deletePtr;
			return returnObj;
		}
	}


}

 /******************************************************************
 Class LinkedList
 Function:  clear
 Parameters: None
  Removes and deletes all the entries of the list
   Function:  isEmpty
  Returns void
*******************************************************************/   
template<typename obj>
void LinkedList<obj>::clear() {
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   // Print each item on a new lin
	Node<obj>* copyPtr;

	while(headNodePtr != NULL){
		copyPtr = headNodePtr->getNext();
		delete headNodePtr;
		headNodePtr = copyPtr;
	}
	return;
}

#endif
