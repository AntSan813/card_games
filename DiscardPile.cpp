/***************************************************************************************************************************************************	Author: Anotnio Santos
    Date: 11/28/16
    Assignment: Crazy8
***************************************************************************************************************************************************/

#ifndef DiscardPile_cpp
#define DiscardPile_cpp

#include "DiscardPile.h"
#include "Card.h"

using namespace std;



//constructor
DiscardPile::DiscardPile(){}



/***************************************************************************************************************************************************	function: setWildSuit(string newSuit) and setWildSuit(int newSuit)
    description: both funcitons set the wild suit to a new suit. 
    output: none
***************************************************************************************************************************************************/
void DiscardPile::setWildSuit(string newSuit){
	wildSuit = newSuit;
}
void DiscardPile::setWildSuit(int newSuit){
	switch(newSuit){
		case 1: wildSuit = "Spades";
			break;
		case 2: wildSuit = "Hearts";
			break;
		case 3: wildSuit = "Diamonds";
			break;
		case 4: wildSuit = "Clubs";
			break;
		default: throw 99;
	}
}



/***************************************************************************************************************************************************	function: menu()
    description: shows the menu of crazy suits to choose from
    output: outputs crazy suit menu

***************************************************************************************************************************************************/
void DiscardPile::menu(){
	cout << "Set a new crazy suit:" << endl;	
	cout << "1.  Spades\n" 
		<< "2.  Hearts\n" 
		<< "3.  Diamonds\n"
		<< "4.  Clubs\n" 
	<< endl << endl;
}



/***************************************************************************************************************************************************	function: getWildSuit()
    description: returns wildSuit
***************************************************************************************************************************************************/
string DiscardPile::getWildSuit(){
	return wildSuit;
}



//deconstructor
DiscardPile::~DiscardPile(){
        Node<Card>* holder;
        while(topOfStackPtr != NULL){
                holder = topOfStackPtr;
                topOfStackPtr = topOfStackPtr->getNext();
                delete holder;
        }
        cout << "Discard Pile successfully deleted" << endl;
}


#endif

