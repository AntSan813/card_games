/***************************************************************************************************************************************************
	Author: Antonio Santos
	Description: chooses game mode to go into
***************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "Rock.h"
#include "Scissor.h"
#include "Paper.h"
#include "Tool.h"
#include "Monte.h"
#include "Marble.h"
#include "Marble.cpp"
#include "DiscardPile.h"
#include "PlayingHand.h"
using namespace std;

// Function Prototypes
void showMenu();
void doRandomCard(); // build to make switch statement easier to read
void doWar();
void doBlackjack();
void doMagictrick();
void doRps();
void doMonteMarble();
void doMonteCard();
void doCrazy8();
void invalidInputReset();  // resets console after invalid input


// Start of main routine
int main(){

 srand(time(0));
 system("clear");  // clear the screen
 int choice=0; // init to ensure while executes once

 while (choice!=99){
	showMenu();
	cin >> choice;
		if (cin.fail())  // Input validation error
		{   choice = 0; // reset choice to indicate invalid choice
			invalidInputReset(); // reset cin to valid state
		}
	switch (choice) {
		// Pick a random Card
		case 1 :
	 	   doRandomCard(); 
		   break;
		case 2 : // play a game of War
			doWar();
			break;
		case 3 : // play a game of blackjack
			doBlackjack();
			break;
		case 4 : //play a magic trick
			doMagictrick();
			break;
		case 5 : //play rock paper scissors
			doRps();
			break;
		case 6: //play monte with marbles
			doMonteMarble();
			break;
		case 7: // play monte with cards
			doMonteCard();
			break;
		case 8: //play crazy 8 game
			doCrazy8();
			break;
		case 99 :  // end game	
			cout << "Thanks for playing " << endl << endl;
			break;
		default :  // not a valid choice
			cout << "Error: not a valid selection " << endl;
			break;

		} // end of switch statement

 } // end of while loop
 return 0;
}

//***************************************
// Function : showMenu
// Input: none
// output: none
// Description: This function presents the menu
//    options on the screen.
//*****************************************
void showMenu(){

     cout<<endl << endl << endl << endl;
     cout << "****  GAME MENU   ******" << endl << endl;
     cout<<"Please type a choice"<<endl;
     cout<<"1:  Pick a random card"<<endl;
     cout<<"2:  Play War"<<endl;
     cout<<"3:  Play Blackjack"<<endl;
     cout <<"4:  Play Magic Card" << endl;
     cout <<"5:  Play Rock, Paper, Scissors" << endl;
     cout <<"6:  Play Monte with Marbles" << endl;
     cout <<"7:  Play Monte with Cards" << endl;
     cout <<"8:  Play Crazy 8 " << endl;
     cout<<"99:  Exit the program"<<endl;

}

//***************************************
// Function : doRandomCard
// Input: none
// output: none
// Description: This function does everything needed to pick a random card
//*****************************************	
void doRandomCard(){
	
	cout << endl;
	cout << "Random Card Game" << endl;
       Deck d;
       int count = 0, inDeck = 52;
       char choice;
	d.shuffle();
	do{
               cout << "Random Card Drawn: " << endl;
               cout << d.deal();
		cout << endl;
               inDeck--;
	       count ++;

               cout << "Draw another random card? (y/n) ";
               cin >> choice;
               cout << endl;
               if(islower(choice))
                       choice = toupper(choice);
       }while((choice == 'Y') && (inDeck !=0));
	cout << "." << endl;
	//output
        cout << "Numer of cards drawn: " << count << endl;
        cout << "Number of cards in deck: " << inDeck  << endl;


}
	
//***************************************
// Function : doWar
// Input: none
// output: none
// Description: This function does everything needed to play war
//*****************************************
void doWar(){
      cout << "Play War" << endl;
	cout <<endl;
	cout << endl;
	Deck deck; // creates deck
	
	int points1 = 0, points2 = 0;
	Card p1, p2; //creates 2 card objects for 2 players
	Card* cardPtr; // creates a card pointer to move cards from the deck to the card objects
	int tricks = 10;	

	deck.shuffle();
	//following plays game
	for(tricks; tricks--; tricks >= 1){

		p1 = deck.deal(); // card equals the pointed value for the cardPTR
		cout << "Player 1: ";
		cout << p1 << endl;
                
		p2 = deck.deal();
		cout << "Player 2: ";
		cout << p2 << endl;
		
		//decides this rounds winner
		if(p1 > p2){
			points1++;
			cout << "Winner for this round is Player 1!" << endl;
		}
		else{
			points2++;
			cout << "Winner for this round is Player 2!" << endl;
		}
	}

	cout << endl;
	//decides overall winner
	if(points1 > points2)
		cout << "Player 1 is the overall winner with " << points1 << " points!" << endl;
	else if(points2 > points1)
		cout << "Player 2 is the overall winner with " << points2 << " points!" << endl;
	else
		cout << "Player 1 and Player 2 tie with " << points1 << " points!" << endl;

}

	
//***************************************
// Function : doBlackjack
// Input: none
// output: none
// Description: This function does everything needed to play blackjack
//*****************************************
void doBlackjack(){ 

	cout << "Play Blackjack" << endl; 

	Deck deck;
	Card c1, c2;
	Card* cardPtr;
	int rank1, rank2;
	char choice;
	deck.shuffle();
	//houses turn
	int total1;
	c1 = deck.deal();
	c2 = deck.deal();

	cout << "The house picked 2 cards: ";	
	cout << c1;
	cout << " and ";
	cout << c2 << endl;
	
	rank1 = c1.getBJackRank();
	rank2 = c2.getBJackRank();
	total1 = rank1 + rank2;

	cout << "The house has a total of: " << total1 << endl;
	cout << endl;


	//players turn
	int total2;

        c1 = deck.deal();

        c2 = deck.deal();

        cout << "The player picked 2 cards: ";
        cout << c1;
        cout << " and ";
        cout << c2 << endl;

        rank1 = c1.getBJackRank();
        rank2 = c2.getBJackRank();
	total2 = rank1 + rank2;

        cout << "You have a total of: " << total2 << endl;
        cout << endl;
	

        cout << "Would you like to draw another card? (Y/N)  ";
        cin >> choice;
        if(islower(choice))
        choice = toupper(choice);

	//if player wants to get more cards
	while(choice == 'Y'){
		c1 = deck.deal();
		
		cout << "The card you picked was: ";
		cout << c1 << endl;
		
		rank1 = c1.getBJackRank();
		total2 = total2 + rank1;
		cout << "The new total is: " << total2 << endl;
				
			
	        cout << "Would you like to draw another card? (Y/N)  ";
                cin >> choice;
                if(islower(choice))
                        choice = toupper(choice);
			
	}	

	cout << endl;

	if((total1 < total2) && (total2 < 21)){
		c2 = deck.deal();
		
		cout << "The house got another card: ";
		cout << c2 << endl;
		
		rank1 = c2.getBJackRank();
		total1 = total1 + rank1;
	}
	
	if(total2 == 21)
		cout << "You win with " << total2 << " points!!" << endl;
	else if((total2 < 21) && (total1 > 21))
		cout << "The house busted! You win by default with " << total2 << " points!" << endl;
	else if((total1 < 21) && (total2 < 21) && (total2 > total1))
		cout << "You win!!! You beat the house by " << total2 - total1 << " points!" << endl;
	else 
		cout << "You lose!!! The house wins with " << total1 << " points!" << endl;

}


/***************************************************************************************************************************************************
	function: doMagictrick()
	description: draws a random card from deck and changes its values
	output: outputs random number. outputs new card
***************************************************************************************************************************************************/
void doMagictrick(){
	cout << "Play Magic Trick" << endl;
        cout << endl;
        
	Deck d;
	d.shuffle();
	Card x = d.deal();	
        cout << "Card picked from deck: "; 		
        cout << d.deal() << endl << endl;
        cout << "Alla Blubabe Canabi Rashi!!!!!!" << endl;
        cout << "Your card changed! Here is the new card: ";
	x.setRank(12);
	x.setSuit(HEARTS);

	cout << x.toString() << endl << endl;
}

/**************************************************************************************************************************************************
	function: doRps()
	description: this is the rock paper scissor game. Comments in the code explain the process.
	output: user inputs numbers 3 times that coorelate to a Rock, paper or scissor. outputs what the user chose, what the computer chose and who won
**************************************************************************************************************************************************/
void doRps(){
	cout << "Play Rock, Paper, Scissor" << endl;
	
	//start of test
	cout << "*****START OF TEST*****" << endl;
	Rock p2;
	Scissor p1;
	cout << "Rock and Scissor objects created." << endl;
	Tool* player1;
	Tool* player2;
	cout << "Tool pointers created." << endl;
	player1 = &p1;
	player2 = &p2;
	cout << "Player 1 tool pointer is equal to the address of a scissor object. \nPlayer 2 tool pointer is equal to the address of a rock object." << endl;
	cout << "Player 1: " << player1->getType() << endl;
	cout << "Player 2: " << player2->getType() << endl;
	cout << "They fight. Expected output is 2." << endl;
	cout << "Output: " << player1->fight(player2) << endl;
	cout << "This translates to player 2 winning!" << endl
		<< "*****END OF TEST*****" << endl;

	//start of actual game
	cout << endl;
	//creating objects
	Rock r;
	Paper p;
	Scissor s;		
	int choice, compChoice, winner;
	Tool* player;//creating Tool pointers for both players(player and computer)
	Tool* computer;
	
    //following executes game
    for(int i = 1; i<4; i++){	
	cout << "*****Round " << i << "*****" << endl;
	cout << "Rock, Paper, Scissor, Shoot! " <<endl;
	cout << "1: Rock \n2: Paper \n3: Scissor" << endl; //menu
	cin >> choice;
	//converts choice to the appropriate object address
	if(choice == 1)
		player = &r;
	else if(choice == 2)
		player = &p;
	else if(choice == 3)
		player = &s;

	compChoice = rand()%3 + 1;//random number for computer
	//converts computers random numner to a random choice 
        if(compChoice == 1)
                computer = &r;
        else if(compChoice == 2)
                computer = &p;
        else if(compChoice == 3)
                computer = &s;

	//calculates winner using fight(Tool*) function
	winner = computer->fight(player);
	//displays what the computer and player chose
	cout << "You chose: " << player->getType() << endl;
	cout << "The computer chose: " << computer->getType() << endl;
	//figures out winner on information given and displays winner
	if (winner == 0)
		cout << "There is no winner. You and the computer tied with " << player->getType() << endl;
	else if(winner == 1)
		cout << "Computer wins. " << computer->getType() << " beats " << player->getType() << endl;
	else if(winner == 2)
		cout << "Player wins. " << player->getType() << " beats " << computer->getType() << endl;
	cout << endl << endl;
    }
}		
/***************************************************************************************************************************************************
	
***************************************************************************************************************************************************/
void doMonteMarble(){
	//beginning of test
	int testans = 1;
	int testchoice = 1;
	string testanspick, testpick;
	cout << "tested answer and tested choice equal each other. Expected output is a win." << endl;	
        Marble t1, t2, t3; //create 3 marble objects
        t1.setColor("Red");
        t2.setColor("Blue");
        t3.setColor("Purple");
        Monte<string> test1(t1.getColor(),t2.getColor(),t3.getColor());
        test1.randomize(testans); //randomize the colors using that rand num
        testanspick = test1.pick(testans); // pick a random number using that rand num
	testpick = test1.pick(testchoice);
	cout << "Tested answer: " << testanspick << endl;
	cout << "Tested choice: " << testpick << endl;

	cout << "tested answer and tested choice may or may not equal each other. Expected output is either a win or lose." << endl;
        Monte<string> test2(t1.getColor(),t2.getColor(),t3.getColor());
        testans = rand()%3; // pick rand num from 0 - 2
        test2.randomize(testans); //randomize the colors using that rand num
        testanspick = test2.pick(testans); // pick a random number using that rand num
        testpick = test2.pick(testchoice);
        cout << "Tested answer: " << testanspick << endl;
        cout << "Tested choice: " << testpick << endl;
	//end of test


	cout << endl << endl;
	cout << "Play Monte Marble" << endl;
	cout << endl << endl;
	
	int num, choice;
	string pick, ans;

	Marble c1, c2, c3; //create 3 marble objects
	c1.setColor("Red");
	c2.setColor("Blue");
	c3.setColor("Purple");
	Monte<string> p1(c1.getColor(),c2.getColor(),c3.getColor());			
	
	num = rand()%3; // pick rand num from 0 - 2
	p1.randomize(num); //randomize the colors using that rand num
	ans = p1.pick(num); // pick a random number using that rand num
	
	cout << "Pick a number between 1 and 3: ";
	cin >> choice;	//user chooses a num
	choice = choice - 1;
	pick = p1.pick(choice);	//users num input is used to pick a colow
	
	if(ans == pick) // compare ans and user input
		cout << "You picked the right marble! The answer was the " << ans << " marble." << endl;
	else
		cout << "You lose! You picked: " << pick << " and the answer was: " << ans << endl;
}

void doMonteCard(){
        //beginning of test
        int testans = 1;
        int testchoice = 1;
        string testanspick, testpick;
        cout << "tested answer and tested choice equal each other. Expected output is a win." << endl;

        Deck t;
	t.shuffle();
	Card t1;
	Card t2;
	Card t3; //create 3 marble objects
	t1 = t.deal();
	t2 = t.deal();
	t3 = t.deal();

        Monte<string> test1(t1.toString(),t2.toString(),t3.toString());
        test1.randomize(testans); //randomize the colors using that rand num
        testanspick = test1.pick(testans); // pick a random number using that rand num
        testpick = test1.pick(testchoice);
        cout << "Tested answer: " << testanspick << endl;
        cout << "Tested choice: " << testpick << endl;

        cout << "tested answer and tested choice may or may not equal each other. Expected output is either a win or lose." << endl;
        Monte<string> test2(t1.toString(),t2.toString(),t3.toString());
        testans = rand()%3; // pick rand num from 0 - 2
        test2.randomize(testans); //randomize the colors using that rand num
        testanspick = test2.pick(testans); // pick a random number using that rand num
        testpick = test2.pick(testchoice);
        cout << "Tested answer: " << testanspick << endl;
        cout << "Tested choice: " << testpick << endl;
        //end of test

	cout << endl << endl;
	cout << "Play Monte Card" << endl;
	cout << endl << endl;

	Deck d;
	d.shuffle();
	Card c1;
	Card c2;
	Card c3;
	c1 = d.deal();
	c2 = d.deal();
	c3 = d.deal();

	Monte<string> x(c1.toString(), c2.toString(), c3.toString());
	
	int num, choice;
	string pick, ans;
	num = rand()%3; // pick rand num from 0 - 2
        x.randomize(num); //randomize the colors using that rand num
        ans = x.pick(num); // pick a random number using that rand num

        cout << "Pick a number between 1 and 3: ";
        cin >> choice;  //user chooses a num
        choice = choice - 1;
        pick = x.pick(choice); //users num input is used to pick a colow

        if(ans == pick) // compare ans and user input
                cout << "You picked the right card! The answer was: " << ans ;
        else
                cout << "You lose! You picked: " << pick << " and the answer was: " << ans << endl;

}

/**************************************************************************************************************************************************


**************************************************************************************************************************************************/
void doCrazy8(){
	cout << endl << endl << "Play Crazy 8 " << endl << endl;
	int max, counter = 0;	
	Deck cards;
	Card p1Choice;
	Card p2Choice; 
	Card matchCard;
	DiscardPile discarded;
	cards.shuffle();
	bool boolForP2, boolForP1;
	char playAgain;
	string player1, player2;
	PlayingHand p1,p2;
        int round = 1;
        int choice, p1Points = 0, p2Points = 0;
	int game, game2, inDeck;
	for(int i = 0; i < 7; i++){
		p1.insertFront(cards.deal());
		p2.insertFront(cards.deal());
	}
	inDeck = 52 - 14;


	//determines if game will use crazy 8 logic or not
	do{
		cout << "How would you like to play? \n"
			<< "1.  With Crazy-8 Logic\n" 
			<< "2.  Without Crazy-8 Logic" << endl;
		cin >> game2;
		if((game2 < 0) || (game2 > 2))
			cout << endl << "*****Invalid input. Please enter a number between 1-2*****" << endl;
	}while((game2 < 0) || (game2 > 2));


	
	//determines how game will be played
	do{
		cout << "How many players? \n"
			<< "0.  Watch computer lash out at itself.\n"
			<< "1.  Play versus the computer.\n" 
			<< "2.  Play against another person.\n";
		cin >> game;

		if((game < 0) || (game > 2))
			cout << endl << "*****Invalid input. Please enter a number between 0-2*****" << endl;
	}while((game < 0) || (game > 2));
	
	//following if  else's determine names
	if(game == 0){
		player1 = "Computer 1";
		player2 = "Computer 2";
	}
	else if(game == 1){
		player1 = "Player";
                player2 = "Computer";
	}		
	else{
		player1 = "Player 1";
                player2 = "Player 2";
	}	



   //following while is encapsulates the game using functions from new classes 
   while((p1.isEmpty() == false) && (p2.isEmpty() == false) && (cards.isEmpty() == false)){

		system("clear"); //clears screen for better visability

		cout << endl << endl << "Round " << round << endl;
		
		//following is how match card and wild suit are determined per round
		discarded.push(cards.pop());
		matchCard = discarded.peek();
		discarded.setWildSuit(matchCard.getSuit());
		

		inDeck--;//deck counter
		
		boolForP1 = false;
		boolForP2 = false;


	//PLAYER VERSUS COMPUTER implementation
	if(game == 1){
		cout << "Cards in Deck: " << inDeck << endl;
		if(game2 == 1)
			cout << "WildSuit: " << discarded.getWildSuit() << endl; //shows wild suit for this round
		p1.manualAlgorithm(game2, boolForP1, matchCard, cards, p1Choice, inDeck, discarded, player1);//call to function in PlayingHand
		p2.automaticAlgorithm(game2, boolForP2, matchCard, cards, p2Choice, player2, inDeck, discarded);//call to function in PlayingHand
	}
	

	//COMPUTER VERSUS COMPUTER implementation
	else if (game == 0){
		cout << "Cards in deck: " << inDeck << endl;
		if(game2 == 1)
			cout << "Wild Suit: " << discarded.getWildSuit() << endl;
		
	       	cout << endl;
		cout << player1 << " Hand (" << p1.count() << "): " << endl;
		p1.printList(); // prints the hand for computer 1

		cout << endl << endl;
		cout << player2 << " Hand (" << p2.count() << "): " << endl;
		p2.printList();//prints the hand for computer 2
		cout << endl << endl;
    			
		cout <<  "Card chosen: " << matchCard << endl << endl << endl; //outputs the card chosen for this round
		p1.automaticAlgorithm(game2, boolForP1, matchCard, cards, p1Choice, player1, inDeck, discarded); //call to a funciton in PlayingHand
               	p2.automaticAlgorithm(game2, boolForP2, matchCard, cards, p2Choice, player2, inDeck, discarded); //call to a function in PlayingHand
	}


	//PLAYER VERSUS PLAYER implementation
	else{
		//PLAYER 1		
		cout << endl << endl << "PLAYER 1 TURN" << endl << endl;
		if(game2 == 1)
	                cout << "Wild Suit: " << discarded.getWildSuit() << endl << endl;
	        p1.manualAlgorithm(game2, boolForP1, matchCard, cards, p1Choice, inDeck, discarded, player1); //call to a function in PlayingHand
		system("clear"); //clear screen for readability

		//PLAYER 2
		cout << endl << endl << "PLAYER 2 TURN" << endl << endl;
		if(game2 == 1)
			cout << "Wild Suit: " << discarded.getWildSuit() << endl << endl;
		p2.manualAlgorithm(game2, boolForP2, matchCard, cards, p2Choice, inDeck, discarded, player2);
		system("clear"); //clear screen for readability
			
		cout << endl << endl;
	
		//following outputs the Players choice	
		if(boolForP1 == true)	
			cout << "Player 1 chose: " << p1Choice << endl; 
		else 
			cout << "Player 2 picked up a card from deck." << endl;

		if(boolForP2 == true)
			cout << "Player 2 chose: " << p2Choice << endl;
		else
			cout << "Player	2 picked up a card from deck." << endl;
	}
	

	cout << endl;	
	//following if statements determine winner(s), if any.

	//if both players draw a card
	if((boolForP2 == true) && (boolForP1 == true)){
		if(((matchCard.getSuit() == p2Choice.getSuit()) && (matchCard.getSuit() == p1Choice.getSuit())) ||
			((matchCard.getSuit() == p2Choice.getSuit()) && (matchCard.getRank() == p1Choice.getRank())) ||
				((matchCard.getRank() == p2Choice.getRank()) && (matchCard.getSuit() == p1Choice.getSuit())) ||
					((matchCard.getRank() == p2Choice.getRank()) && (matchCard.getRank() == p1Choice.getRank()))){
			cout <<  "This round ends in a tie." << endl << endl;
			
			//if statement determines the points WITH crazy 8 logic 
			if(game2 == 1){//distributes 
				if(p1Choice.getBJackRank() == 8)
					p1Points = p1Points + 20;
				else
	                                p1Points = p1Points + p1Choice.getBJackRank();
				if(p2Choice.getBJackRank() == 8)
					p2Points = p2Points + 20;	
				else
        	                        p2Points = p2Points + p2Choice.getBJackRank();
                        }
			//the else statement determines the points WITHOUT crazy 8 logic
			else{//districuted points based off of card value
				p1Points = p1Points + p1Choice.getBJackRank();
				p2Points = p2Points + p2Choice.getBJackRank();		
			}
		}
	}


	else{//if one or both players do not draw a card
		//if player one only draws a card
		if(boolForP1 == true){
	                if(game2 == 1){
        	                if(p1Choice.getBJackRank() == 8)
                                        p1Points = p1Points + 20;
                        else
                                p1Points = p1Points + p1Choice.getBJackRank();
			}
			else
				p1Points = p1Points + p1Choice.getBJackRank();
			cout << player1 << " wins this round." << endl << endl;
		}

		//else if player 2 only draws a card
		else if(boolForP2 == true){
                        if(game2 == 1){
                                if(p2Choice.getBJackRank() == 8)
                                        p2Points = p2Points + 20;
                        else
                                p2Points = p2Points + p2Choice.getBJackRank();
                        }
                        else
                                p2Points = p2Points + p2Choice.getBJackRank();
			cout << player2 << " wins this round." << endl << endl;
		}

		//else noone draws a card
		else
			cout << "Noone wins this round." << endl << endl;
	}


		cout << endl; //readability statements
		//following if is used to catch a cin error
		if((game != 0) || (round == 1))
			cin.ignore();

		//allows person at the keyboard to continue to the next round
		cout << "Press enter to continue to next round" << endl;
		cin.ignore();
		round++;//round counter

   } //end of while
	
	cout << endl;

	cout << player1 << " score: " << p1Points << endl;
	cout << player2 << " score: " << p2Points << endl;
	
	//if any of the linked lists are empty, the winner is whoever emptied theirs first (determined below)
	if(p1.isEmpty())
		cout << "The winner is " << player1 << endl;
	else if(p2.isEmpty())
		cout << "The winner is " << player2 << endl;

	//else whoever has the most points win
	else{
		if(p1Points > p2Points)
			cout << "The winnner is " << player1 << endl;
		else if (p2Points > p1Points)
			cout << "The winner is " << player2 << endl;
		else 
			cout << "No winner, the game ends in a tie!" << endl;
	}
}



//***************************************
// Function : invalidInputReset
// Input: none
// output: none
// Description: This function resets the cin stream object
//      after in invalid input is detected. It clears the error flags
//      and reads any other 'garbage' on the input line past the last '\n'
//*****************************************
void invalidInputReset(){

     cin.clear(); // clear the error flags
}
