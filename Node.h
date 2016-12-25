#ifndef Node_h
#define Node_h

#include <iostream>
#include <cstdlib>

using namespace std;

template <class datumType>
class Node{
	private:
		datumType datum;//item / object
		Node* next; // pointer to the next object in stack
	public:
		//following are constructors
		Node();//default construct
		Node(datumType V);//contruct with one parameter
		Node(datumType V, Node* n);//construct with two paramaters
		//following are setters
		void setItem(datumType v);
		void setNext(Node* n);
		
		//following are getters
		Node<datumType>* getNext();//get the node in array
		datumType getItem();//get the item 
};

template<class datumType>
Node<datumType>::Node(){
	next = NULL;
}

template<class datumType>
Node<datumType>::Node(datumType V){
	datum = V;
	next = NULL;
}
	
template<class datumType>
Node<datumType>::Node(datumType V, Node* n){
	datum = V;
	next = n;
}

template<class datumType>
void Node<datumType>::setItem(datumType v){
	datum = v;
}

template <class datumType>
void Node<datumType>::setNext(Node* n){
	next = n;
}

template<class datumType>
Node<datumType>* Node<datumType>::getNext(){
	return next;
}

template<class datumType>
datumType Node<datumType>::getItem(){
	return datum;
}

#endif
