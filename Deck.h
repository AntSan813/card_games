/**************************************************************************************************************************************************
	Author: Antonio Santos
	Last update: 10/1/16
	description: creates a Deck class
**************************************************************************************************************************************************/
#ifndef Deck_h
#define Deck_h

#include "Card.h"
#include "Node.h"
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;


/**************************************************************************************************************************************************
	Class name: Deck
        Description: creats a deck class. outputs include making a 52 deck of cards and randomly picks 1 to output. it also checks if the output is valid
***************************************************************************************************************************************************/
class Deck : public Stack<Card>
{
        private:
                int randNum;
        public:
                Deck();
		Card checkRandom();
                Card deal();
		~Deck();

		void shuffle();
		void merge(Deck,Deck,Deck,int,int);


};
#endif

