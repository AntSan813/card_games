/***************************************************************************************************************************************************
	Author: Anotnio Santos
	Class name: DiscardPile.h
	Assignment: Crazy8
***************************************************************************************************************************************************/
#ifndef DiscardPile_H
#define DiscardPile_H

#include "Stack.h"
#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

class DiscardPile : public Stack<Card> {
	private: 
		string wildSuit;
		int crazy8;
		int matchNum;
	public:
		DiscardPile();					 
		void setWildSuit(int);
		void setWildSuit(string);
		void menu();
		string getWildSuit();		
		~DiscardPile();		
};



#endif

