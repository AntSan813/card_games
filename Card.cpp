/***************************************************************************************************************************************************
	Author: Antonio Santos
	Last date of editting: 9/27/16
	Assignment: Card Class PRG
***************************************************************************************************************************************************/

#ifndef Card_cpp
#define Card_cpp

#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

/***************************************************************************************************************************************************
	Constructor name: Card()
	Description: default constructor that sets suit to JOKER and rank to 0
***************************************************************************************************************************************************/
Card::Card(){
	setSuit(JOKER);
	setRank(0);	
}

/***************************************************************************************************************************************************
        Constructor name: Card(int, int)
        Description: builds a card by converting a number from 0 to 4 to be equal to a suit enum, and then sets the suit with that enum. the constructor then sets a card rank to the number provided. catches any errors as well.
***************************************************************************************************************************************************/
Card::Card(int cardRank, int suitNum){
	try{
        	if((suitNum >= 4) && (suitNum < 0))
                  throw 98;
                else
                  switch(suitNum)
                  {
                     case 0: setSuit(SPADES);
                          break;
                     case 1: setSuit(HEARTS);
                          break;
                     case 2: setSuit(DIAMONDS);
                          break;
                     case 3: setSuit(CLUBS);
                          break;
                     case 4: setSuit(JOKER);
			  break;
		     default: throw 99;
                   }
                 }catch (int y){
                                cout << "Error Code: " << y << endl;
                 }
         try{
                 if((cardRank >= 0) && (cardRank <= 13))
                      setRank(cardRank);
                 else
                      throw 99;
             }catch(int x){
                      cout << "Error code: " << x << endl;
             }
	blackjackRanks(cardRank);

}

/***************************************************************************************************************************************************

***************************************************************************************************************************************************/
void Card::setRank(int rank)
                {
                        try{
                        if(rank == 2)
                                rankName = "Two ";
                        else if (rank == 3)
                                rankName = "Three ";
                        else if (rank == 4)
                                rankName = "Four ";
                        else if (rank == 5)
                                rankName = "Five ";
                        else if (rank == 6)
                                rankName = "Six ";
                        else if (rank == 7)
                                rankName = "Seven ";
                        else if (rank == 8)
                                rankName = "Eight ";
                        else if (rank == 9)
                                rankName = "Nine ";
                        else if (rank == 10)
                                rankName = "Ten ";
                        else if (rank == 11)
                                rankName = "Jack";
                        else if (rank == 12)
                                rankName = "Queen";
                        else if (rank == 13)
                                rankName = "King";
                        else if (rank == 1)
                                rankName = "Ace";
                        else if (rank == 0)
                                rankName = "Zero";
                        else
                                throw 98;
                        }catch(int x){
                                cout << "Error code: " << x << endl;
                        }
                }
/**************************************************************************************************************************************************

***************************************************************************************************************************************************/
void Card::setSuit(SUITS suit){
                        switch(suit)
                        {
                                case SPADES: name = "Spades";
                                        break;
                                case HEARTS: name = "Hearts";
                                        break;
                                case DIAMONDS: name = "Diamonds";
                                        break;
                                case CLUBS: name = "Clubs";
                                        break;
                                case JOKER: name = "Joker";
					break;
				default: throw 99;
                        }
}


void Card::blackjackRanks(int x){

        if(x > 9){
                bjackRank = 10;
        }
        else{
                bjackRank = x;
        }
}

/**************************************************************************************************************************************************

***************************************************************************************************************************************************/
string Card::getRank(){
                        return rankName;
}
/**************************************************************************************************************************************************

***************************************************************************************************************************************************/
string Card::getSuit(){
                        return name;
}

int Card::getRankNum(){
	return cardRank;
}
SUITS Card::getEnumSuit(){
	return suit;
}
int Card::getBJackRank(){
	return bjackRank;
}
/***************************************************************************************************************************************************
        Function name: toString()
        Description: converts everything into a string object and returns that string object to output the results.
***************************************************************************************************************************************************/
string Card::toString(){
	string suitName, rankName;
	 if (getSuit() == "Joker")
        { 
	     suitName = "Joker";
		return suitName;
        }
	 else
	{
              suitName = getSuit();
	      rankName = getRank();
	      return rankName + " of " + suitName;
	}
}


/**************************************************************************************************************************************************

***************************************************************************************************************************************************/
bool operator<(Card p1, Card p2){
	if(p1.getBJackRank() < p2.getBJackRank())
                return true;
        else if(p2.getBJackRank() < p1.getBJackRank())
                return false;
        else if(p2.getBJackRank() == p1.getBJackRank())
        {
                if((p1.getEnumSuit() == CLUBS) && ((p2.getEnumSuit() == DIAMONDS) || (p2.getEnumSuit() == HEARTS) || (p2.getEnumSuit() == SPADES)))
                	return false;
                else if((p1.getEnumSuit() == DIAMONDS) && (((p2.getEnumSuit() == HEARTS) || (p2.getEnumSuit() == SPADES))))
               		return false;
                else if((p1.getEnumSuit() == HEARTS) && (p2.getEnumSuit() == SPADES))
                	return false;
		else
			return true;
        }
}


/**************************************************************************************************************************************************

***************************************************************************************************************************************************/
bool operator>(Card p1, Card p2){
        if(p1.getBJackRank() > p2.getBJackRank())
                return true;
        else if(p2.getBJackRank() > p1.getBJackRank())
                return false;
        else if(p2.getBJackRank() == p1.getBJackRank())
        {
                if((p1.getEnumSuit() == CLUBS) && ((p2.getEnumSuit() == DIAMONDS) || (p2.getEnumSuit() == HEARTS) || (p2.getEnumSuit() == SPADES)))
                        return false;
                else if((p1.getEnumSuit() == DIAMONDS) && ((p2.getEnumSuit() == HEARTS) || (p2.getEnumSuit() == SPADES)))
                        return false;
                else if((p1.getEnumSuit() == HEARTS) && (p2.getEnumSuit() == SPADES))
                        return false;
                else
                        return true;
        }
}


/**************************************************************************************************************************************************

***************************************************************************************************************************************************/
ostream& operator<<(ostream& os, Card myCard){
        os << myCard.toString();
        return os;
}

#endif
