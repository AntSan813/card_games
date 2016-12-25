/***************************************************************************************************************************************************
	Author: Antonio Santos
	Date: 11/28/16
	Assignment: Crazy8
***************************************************************************************************************************************************/
#ifndef PlayingHand_H
#define PlayingHand_H

#include "LinkedList.h"
#include "Stack.h"
#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include <string>
using namespace std;

class PlayingHand : public LinkedList<Card> {
	protected:
		Node<Card> choice;
		string wild;
		
	public:
		PlayingHand();
		void manualAlgorithm(int, bool &, Card, Deck &, Card &, int &count, DiscardPile &dp, string name);				
		void automaticAlgorithm(int, bool &, Card, Deck &, Card &, string name, int &count, DiscardPile &dp);


};



#endif
