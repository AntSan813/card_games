/***************************************************************************************************************************************************
	Author: Antonio Santos
	date: 11/28/16
	Assignment: Crazy8
***************************************************************************************************************************************************/
#ifndef PlayingHand_cpp
#define PlayingHand_cpp

#include "PlayingHand.h"
#include "Card.h"
#include "Deck.h"
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "DiscardPile.h"
using namespace std;



//Constructor
PlayingHand::PlayingHand(){}



/***************************************************************************************************************************************************	function: manualAlgotithm
    description: used to have the user manually pick which card they would like to choose from their hand. if the crazy 8 logic is on, this function also asks user for the new wild suit
***************************************************************************************************************************************************/
void PlayingHand::manualAlgorithm(int gameMode, bool &boolForP, Card matchCard, Deck &cards, Card &pChoice, int &count, DiscardPile &dp, string name){
	int choice;
	int max;
	int newS;
	max = this->count();
	while(boolForP == false){
		cout << "Card Drawn: " << matchCard << endl;
                cout << endl << "Your hand: " << endl;
                this->printList();
                cout << "Which card would you like to draw? Select 99 to draw from deck: ";
                cin >> choice;

                //following uses the players input to determine validity and takes out the card from the linked list if it is valid
                if(choice == 99){
                	if(cards.isEmpty()){
				cout << endl << "The deck is empty! Your turn is skipped." << endl;
				boolForP = true;
			}
			else{
				this->insertFront(cards.pop());
                	        boolForP = true;
                        	cout << endl << name << " picks up a card" << endl;
			}
                }
		
		else if((!this->validAtPos(choice))){
			boolForP = false;
			cout << endl << "****Please enter a valid number.****" << endl;
		}
                else if(this->validAtPos(choice)){
                	pChoice = this->remove(choice);
                        boolForP = true;
                        cout << endl << "You chose: " << pChoice << endl;
			

			//following switches crazy 8 logic depending on gamemode
			if(gameMode == 2){ //WITHOUT crazy 8 logic
	                        if((pChoice.getSuit() != matchCard.getSuit()) && (pChoice.getRank() != matchCard.getRank()) && (pChoice.getSuit() != dp.getWildSuit()) && (pChoice.getBJackRank() != 8)){
                                	boolForP = false;
                       		        cout << endl << "***The card you place must match the suit or rank of the card drawn."
                                	        << " Please choose another card from your deck to draw.***"  << endl;
                                	cout << "***If you do not have a card that matches, please select 99 to draw from deck.***" << endl << endl;
                           	     this->insertFront(pChoice);
				}
			}
			else{//WITH crazy 8 logic
                       		if((pChoice.getRank() != matchCard.getRank()) && (pChoice.getSuit() != dp.getWildSuit()) && (pChoice.getBJackRank() != 8)){
	                        	boolForP = false;
        	                        cout << endl << "***The card you place must match the suit or rank of the card drawn."
                	                        << " Please choose another card from your deck to draw.***"  << endl;
                        	        cout << "***If you do not have a card that matches, please select 99 to draw from deck.***" << endl << endl;
                                	this->insertFront(pChoice);
                       		}
			}                	
		}
	}
        if((choice == 99) && (!cards.isEmpty())){
        	boolForP = false;
		count--;
	}

	//WITH crazy 8 logic
	if(gameMode == 1){
		if(boolForP == true){
			if(pChoice.getBJackRank() == 8){
				cout << "You drew an 8!!" << endl;
				dp.menu();
				cin >> newS;
				dp.setWildSuit(newS);
				cout << endl;
				cout << "New Wild Card Suit: " << dp.getWildSuit() << endl;
			}
			else if(pChoice.getRank() == matchCard.getRank()){
				dp.setWildSuit(pChoice.getSuit());
                        	cout << endl;
                        	cout << "New Wild Card Suit: " << dp.getWildSuit() << endl;	
			}
		}
	}
	cout << endl;
	
}



/***************************************************************************************************************************************************	function: automaticAlgorithm
    description: this function is used in main.cpp to automatically pick a card in hand if it meets the conditions given. this function also automatically chooses a new wild suit if crazy 8 logic is on
***************************************************************************************************************************************************/
void PlayingHand::automaticAlgorithm(int gameMode, bool &boolForP, Card matchCard, Deck &cards, Card &pChoice, string name, int &count, DiscardPile &dp){
	int counter = 1;
        int max = this->count();
	int randomNum;
	boolForP = false;

	//following is an algorithm that determines the computers choice
        while((counter <= max) && (max >= counter) && (boolForP == false)){
           if(this->validAtPos(counter)){
        	pChoice = this->peek(counter);   

		//following determines logic of the game
		if(gameMode == 2){//WITHOUT crazy 8 logic
			if((pChoice.getSuit() == matchCard.getSuit())){
                        	boolForP = true;
                	}
        	        else if(pChoice.getRank() == matchCard.getRank()){
	                        boolForP = true;
	                }
	                else{
        	                counter++;
                	        boolForP = false;
               		}
		}//end of no crazy 8 logic

		else{//WITH crazy 8 logic
	    		if(pChoice.getSuit() == dp.getWildSuit()){
        	       		boolForP = true;    
	                }
			else if(pChoice.getBJackRank() == 8){
			        boolForP = true;
        	                if(pChoice.getBJackRank() == 8){
                        	        randomNum = rand()%4 + 1;
                	                dp.setWildSuit(randomNum);
        	                        cout << endl;
	                                cout << "New Wild Card Suit: " << dp.getWildSuit() << endl;
                        	}
			}
        	       	else if(pChoice.getRank() == matchCard.getRank()){
	       	        	boolForP = true;
				dp.setWildSuit(pChoice.getSuit());
        		        cout << endl;
		                cout << "New Wild Card Suit: " << dp.getWildSuit() << endl;
			}
	                else{
	                        counter++;
        	                boolForP = false;
                	}
		}//end of crazy 8 logic
	   }
	   else 
	    	    counter++;
	}//end of while

	if(boolForP == false){
		if(cards.isEmpty()){
			cout << endl << "The deck is empty! Turn is skipped." << endl;
		}
		else{
               		this->insertFront(cards.pop());
			count--;
	        	cout << endl << name << " picks up a card from the deck." << endl;
		}
	}        
	if(boolForP == true){
		pChoice = this->remove(counter);
		cout << endl << name << " Choice: " << pChoice << endl;
	}

	cout << endl;
}

#endif
