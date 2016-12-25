/**************************************************************************************************************************************************
	Author: Antonio Santos
	Last update: 10/1/16
	Description: Implentation file for the Deck.h Deck class
**************************************************************************************************************************************************/

#ifndef Card_cpp
#define Card_cpp

#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string> 
#include "Stack.h"
using namespace std;


/**************************************************************************************************************************************************
        Constructor: Deck()
        Description: creates a deck of 52 cards at a pointed location of the Card class. outputs the 52 cards in order and in their full name
**************************************************************************************************************************************************/
Deck::Deck(){
        int count = 0;
        srand(time(0));
        for(int suit = 0; suit < 4; suit++)
        {
                for (int rank = 1; rank <= 13; rank++)
                {
                          this->push(*new Card(rank,suit));
                          count++;
                }
        }
};

/***************************************************************************************************************************************************
        function name: checkRandom()
        description: generates a random number between 0-51 (representing 52 cards) and uses that number to check the checker array to see if that "card" has already been pulled. if it has, display an error and tell the user how many cards have not been pulled yet. if it is has not been pulled yet, return a true value so that another function displays the newly pulled card
***************************************************************************************************************************************************/
Card Deck::checkRandom(){
	Card randomCard;
	this->shuffle();
        if(!this->isEmpty())
        {
		randomCard = this->pop();
		return this->deal();
        }
        else 
        {
		throw 99;	
        }
	
}

/************************************************************************************************************************************************
        Function name: deal()
        description: returns the card of the random number
***********************************************************************************************************************************************/

Card Deck::deal(){
	return this->pop(); 
}

/************************************************************************************************************************************************
	Start of Stack Implementation
************************************************************************************************************************************************/

void Deck::shuffle(){
	int randNum, size1, size2;
	randNum = rand()%8 + 1;
	Stack<Card> x;
	Stack<Card> y;
   for(int counter = 0; counter < 10; counter++){
        size1 = 22 + randNum;
        size2 = 22 + (8 - randNum);
	//following pops one deck of cards into another.
	for(int i = 0; i < size1; i++)
		x.push(this->pop()); 
	for(int i = 0; i < size2; i++)
		y.push(this->pop());
	for(int i = 0; i < 52; i++){
		if(size1 >= size2){
			this->push(x.pop());
			size1 = size1 - 1;
		}
		else{
			this->push(y.pop());
			size2 = size2 - 1;
		}
	}
    }		
}

Deck::~Deck(){
	Node<Card>* holder;
	while(topOfStackPtr != NULL){
		holder = topOfStackPtr;
		topOfStackPtr = topOfStackPtr->getNext();
		delete holder;
	}
	cout << "Deck of Cards successfully deleted" << endl;
}	


#endif
