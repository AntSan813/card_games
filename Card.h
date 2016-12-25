/***************************************************************************************************************************************************
        Author: Antonio Santos
        Last date of editting: 9/27/16
        Assignment: Card Class PRG
***************************************************************************************************************************************************/

#ifndef Card_h
#define Card_h

#include <string>
#include <iostream>

using namespace std;

/***************************************************************************************************************************************************
	Enum name: SUITS
	description: this enumerator creates 5 suits
***************************************************************************************************************************************************/
enum SUITS{SPADES, HEARTS, DIAMONDS, CLUBS, JOKER};

/**************************************************************************************************************************************************
	class name: Card
	Description: the card class sets private setting functions and variables that will be used later on in the program to build the cards.
**************************************************************************************************************************************************/
class Card{
	private:
		string name, rankName;
		SUITS suit;
		int cardRank, suitNum, bjackRank;
	public:
		void setRank(int);
		void setSuit(SUITS);
		Card(); //default constructor
	        Card(int, int);	//other constructor
		string toString(); //makes string objects to output the cards
		//following 2 getters grab the private variables and returns them to be used in the other program 
		string getRank();
		int getRankNum();
		SUITS getEnumSuit();
		int getBJackRank();
                string getSuit();	
                void blackjackRanks(int);
		friend void doMagictrick();
};
		bool operator<(Card,Card);
		bool operator>(Card,Card);
		ostream& operator<<(ostream&,Card);


#endif
